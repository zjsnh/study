#include "thread.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <string>
#include <memory> // ������ͷ�ļ���ʹ�� shared_ptr
#include <fstream>

// �Զ����ϣ����
struct pair_hash {
    template <typename T1, typename T2>
    size_t operator ()(const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);  // �ϲ�������ϣֵ
    }
};

// Ԥ�ڽ���ļ�
const std::string txt_1 = "./ssp_fl_1ch_1733559855001.txt";
const std::string txt_2 = "./ssp_fl_1ch_1733561048228.txt";
const std::string txt_3 = "./ssp_fl_1ch_1733562619682.txt";
const std::string txt_4 = "./ssp_fl_1ch_1733562948791.txt";
const std::string output_file = "./data.csv";

//�������ļ�
const std::string csv_1 = "./res_showcar1227.csv";

class ssp
{
public:
    ssp() {}

    void assign(float f1, float f2, std::string l)
    {
        s_time = f1;
        e_time = f2;
        literals = l;
    }

    void Path_Set(std::string input)
    {
        size_t pos = input.rfind('_');

        if (pos != std::string::npos) {
            std::string number_str = input.substr(pos + 1);

            size_t dot_pos = number_str.find('.');
            if (dot_pos != std::string::npos) {
                number_str = number_str.substr(0, dot_pos);
            }

            ideal_file = number_str;
        }
    }

public:
    std::string ideal_file;

    float s_time;
    float e_time;
    std::string literals;
};

class csv
{
public:
    csv() {}
    void assign(std::string _ideal_file, std::string _mode, float f1, float f2, std::string l)
    {
        ideal_file = _ideal_file;
        mode = _mode;
        s_time = f1;
        e_time = f2;
        literals = l;   
    }

    void Path_Set(std::string input)
    {

    }

    std::string ideal_file;  //  ģ�������������ļ� ����Ƶ��
    std::string mode;
    float s_time;
    float e_time;
    std::string literals;  // ʶ������
};

template<class T>
bool Assign(const std::vector<std::string>& words, T& type)
{
    return;
}

template<>
bool Assign<ssp>(const std::vector<std::string>& words, ssp& type)
{
    type.assign(std::stof(words[0]), std::stof(words[1]), words[2]);
    return true;
}

template<>
bool Assign<csv>(const std::vector<std::string>& words, csv& type)
{
    if (words[7] != "PartialResult")
        return false;

    std::string input = words[5];
    std::string number_str;

    size_t pos = input.rfind('_');
    if (pos != std::string::npos) {
        number_str = input.substr(0, pos);
        size_t dot_pos = number_str.rfind('_');
        if (dot_pos != std::string::npos) {
            number_str = number_str.substr(dot_pos + 1);
        }
    }

    type.assign(number_str, words[1], std::stof(words[11]), std::stof(words[12]), words[13]);
    return true;
}

std::vector<std::string> split_string(const std::string& s, const std::string& delimiter) {
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = s.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(s.substr(start, end - start));
        start = end + delimiter.length();
        end = s.find(delimiter, start);
    }

    result.push_back(s.substr(start));
    return result;
}

static int n = 0;
template<class T>
bool split(const std::string& txt, const std::string &separator = " ", T& type = T())
{
    if (std::is_same<T, csv>::value && n == 1)
    {
        return false;
    }

    std::stringstream wss(txt);
    std::string word;
    std::vector<std::string> words;

    words = split_string(txt, separator);

    return Assign<T>(words, type);
}

template<class T, class C>
void Processing(const std::string& path, std::shared_ptr<std::vector<T>>& ptr, const C& _type, const std::string& separator = " ")
{
    std::ifstream ifs(path);

    if (!ifs.is_open())
    {
        std::cout << "open file false" << std::endl;
        return;
    }

    C type;
    std::string line;
    while (std::getline(ifs, line))
    {
        n++;
        if (split(line, separator, type))
        {
            if (std::is_same<C, ssp>::value)
            {
                type.Path_Set(path);
            }

            ptr->push_back(type);
        }
    }
    ifs.close();
}

void match(const std::shared_ptr<std::vector<ssp>>& txt_ptr, const csv& csv_entry,
    std::unordered_map<std::pair<std::string, std::string>, float, pair_hash>& results)
{
    for (const auto& ssp_entry : *txt_ptr) {
        if (csv_entry.s_time >= (ssp_entry.s_time - 0.5) && csv_entry.e_time <= (ssp_entry.e_time + 0.5) && ssp_entry.literals == csv_entry.literals) {
            results[std::pair<std::string, std::string>(csv_entry.ideal_file, csv_entry.mode)]++;
        }
    }
}

void comparison(const std::unordered_map<std::string, std::shared_ptr<std::vector<ssp>>>& map,
    const std::shared_ptr<std::vector<csv>>& csv_ptr,
    std::unordered_map<std::pair<std::string, std::string>, float, pair_hash>& results)
{
    for (const auto& csv_entry : *csv_ptr)
    {
        if (!results.count(std::make_pair(csv_entry.ideal_file, csv_entry.mode)))  // û���ҵ���Ӧ��key  ������Ϊ 0 
        {
            //  -> ��ʼ�� results 
            results[std::pair<std::string, std::string>(csv_entry.ideal_file, csv_entry.mode)] = 0;
        }

        auto it = map.find(csv_entry.ideal_file);
        if (it != map.end())
        {
            match(it->second, csv_entry, results);
        }
    }
}
//
//std::string map_key(const std::string& file_path)
//{
//	size_t pos = file_path.rfind('_');
//	if (pos != std::string::npos) {
//		std::string number_str = file_path.substr(pos + 1);
//		size_t dot_pos = number_str.find('.');
//		if (dot_pos != std::string::npos) {
//			number_str = number_str.substr(0, dot_pos);
//		}
//		return number_str;
//	}
//	return "";
//}

//// -> ssp map ����
//
//void ssp_map(std::unordered_map<std::string, std::shared_ptr<std::vector<ssp>>>& map, 
//            const std::string& file_path,my_util::ThreadPool& pool)
//{
//	std::shared_ptr<std::vector<ssp>> txt_ptr = std::make_shared<std::vector<ssp>>();
//	pool.addTask(std::bind(Processing<ssp, ssp>, file_path, txt_ptr, ssp(), "\t"));
//	map.insert(std::make_pair(map_key(file_path), txt_ptr));
//
//}

int main()
{
   /* my_util::ThreadPool pool;
	pool.start();
*/

    std::unordered_map<std::string, std::shared_ptr<std::vector<ssp>>> map;
    /*ssp_map(map, txt_1, pool);
	ssp_map(map, txt_2, pool);
	ssp_map(map, txt_3, pool);
	ssp_map(map, txt_4, pool);*/

     //ʹ�� shared_ptr
    std::shared_ptr<std::vector<ssp>> txt_ptr1 = std::make_shared<std::vector<ssp>>();
    Processing(txt_1, txt_ptr1, ssp(), "\t");

    std::shared_ptr<std::vector<ssp>> txt_ptr2 = std::make_shared<std::vector<ssp>>();
    Processing(txt_2, txt_ptr2, ssp(), "\t");

    std::shared_ptr<std::vector<ssp>> txt_ptr3 = std::make_shared<std::vector<ssp>>();
    Processing(txt_3, txt_ptr3, ssp(), "\t");

    std::shared_ptr<std::vector<ssp>> txt_ptr4 = std::make_shared<std::vector<ssp>>();
    Processing(txt_4, txt_ptr4, ssp(), "\t");

    std::shared_ptr<std::vector<csv>> csv_ptr = std::make_shared<std::vector<csv>>();
    Processing(csv_1, csv_ptr, csv(), ", ");


    //std::shared_ptr<std::vector<csv>> csv_ptr = std::make_shared<std::vector<csv>>();
    //pool.addTask(std::bind(Processing<csv, csv>, csv_1, csv_ptr, csv(), ", "));  //  �зָ��   ', '  ;

    map.insert(std::make_pair("1733559855001", txt_ptr1));  // ʹ�� shared_ptr ���� map
    map.insert(std::make_pair("1733561048228", txt_ptr2));  // ʹ�� shared_ptr ���� map
    map.insert(std::make_pair("1733562619682", txt_ptr3));  // ʹ�� shared_ptr ���� map
    map.insert(std::make_pair("1733562948791", txt_ptr4));  // ʹ�� shared_ptr ���� map

    // �ȴ������������
    //pool.stop();

    std::unordered_map<std::pair<std::string, std::string>, float, pair_hash> results;  //����Ԥ�ڵĽ������

    comparison(map, csv_ptr, results);

    // ���������ļ�
    std::ofstream ofs(output_file);
    if (!ofs.is_open()) {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

	ofs << "�ļ���ʶ" << ", " << "ģ�ͱ�ʶ" << ", " << "ƥ���" << std::endl;

    for (const auto& result : results)
    {
        const auto& key = result.first;
        float match_score = result.second;
        ofs << key.first << ", " << key.second
            << ", " << std::to_string(match_score / (map[key.first]->size())) << std::endl;
    }

    ofs.close();

	//pool.stop();
	//������ ��cmd
	/*for (const auto& result : results)
	{
		const auto& key = result.first;
		float match_score = result.second;
		std::cout << key.first << ", " << key.second
			<< ", " << std::to_string(match_score / (map[key.first]->size())) << std::endl;
	}*/


    return 0;
}

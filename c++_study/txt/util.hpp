#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1
#define _CRT_SECURE_NO_WARNINGS 1
/*

    文件内容，传输管理

*/

#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <memory>
#include <vector>
#include <experimental/filesystem>

#define Time_Delimiter ":"
#define Year_Division "-"
#define Path_separator "/"
#define ZIP ".lz"


namespace Finn
{
    namespace fs = std::experimental::filesystem;   //简化
    class FileUtil
    {
    private:
        std::string _filename;
    public:
        FileUtil(std::string filename)
            :_filename(filename)
        {}

        //格式时间
        static std::string FormatTime(time_t time)
        {
            struct tm* ctime = localtime(&time);
            std::string Mtime = std::to_string(ctime->tm_year + 1900);
            Mtime += Year_Division;
            Mtime += std::to_string(ctime->tm_mon + 1);
            Mtime += Year_Division;
            Mtime += std::to_string(ctime->tm_mday);
            Mtime += " ";
            Mtime += std::to_string(ctime->tm_hour);
            Mtime += Time_Delimiter;
            Mtime += std::to_string(ctime->tm_min);
            Mtime += Time_Delimiter;
            Mtime += std::to_string(ctime->tm_sec);

            return Mtime;
        }

        //文件大小
        int64_t FileSize()
        {
            struct stat st;
            if (stat(_filename.c_str(), &st) < 0)
            {
                std::cout << "get file size failed" << std::endl;
                return -1;
            }

            return st.st_size;
        }

        //最近访问时间
        time_t LastMTime()
        {
            struct stat st;
            if (stat(_filename.c_str(), &st) < 0)
            {
                std::cout << "get file size failed" << std::endl;
                return -1;
            }

            return st.st_mtime;
        }

        //最近修改时间
        time_t LastATime()
        {
            struct stat st;
            if (stat(_filename.c_str(), &st) < 0)
            {
                std::cout << "get file size failed" << std::endl;
                return -1;
            }

            return st.st_atime;
        }

        //去除路径的文件名
        std::string FileName()
        {
            size_t pos = _filename.find_last_of(Path_separator);
            if (pos == std::string::npos)
            {
                return _filename;
            }

            return _filename.substr(pos + 1);
        }

        //读文件
        bool GetPosLen(std::string* body, size_t pos, size_t len)
        {
            std::ifstream ifs;
            //std::unique_ptr<std::ifstream> ifs;
            ifs.open(_filename, std::ios::binary);
            if (ifs.is_open() == false)
            {
                std::cout << "open file false" << std::endl;
                //ifs.close();
                return false;
            }

            size_t fsize = FileSize();
            if (pos + len > fsize)
            {
                std::cout << "get file len error" << std::endl;
                ifs.close();
                return false;
            }

            ifs.seekg(pos, std::ios::beg);
            body->resize(len);
            ifs.read(&(*body)[0], len);

            if (ifs.good() == false)
            {
                std::cout << "read file error" << std::endl;
                ifs.close();
                return false;
            }

            ifs.close();
            return true;
        }


        bool GetContent(std::string* body)
        {
            return GetPosLen(body, 0, FileSize());
        }

        //写文件
        bool SetContent(const std::string& body)
        {
            std::ofstream ofs;
            ofs.open(_filename, std::ios::binary);
            if (ofs.is_open() == false)
            {
                //ofs.close();
                std::cout << "file open false" << std::endl;
            }

            ofs.write(body.c_str(), body.size());
            if (ofs.good() == false)
            {
                std::cout << "file write false" << std::endl;
                ofs.close();
                return false;
            }

            ofs.close();
            return true;
        }
    };

}

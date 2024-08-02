#include<iostream>
using namespace std;

#include<string>
#include<algorithm>


//int main()
//{
//	long long a ;
//	cin >> a;
//	string str = to_string(a);
//
//	for (auto& e : str)
//	{
//		int i = e + '0';
//		if (i % 2 == 0)
//			e = '0';
//		else
//			e = '1';
//	}
//
//
//	int pos = str.find_first_not_of('0');
//	if (pos != string::npos)
//	{
//		string substr = str.substr(pos);
//		str = substr;
//	}
//
//
//	a = stoi(str);
//	cout << a << endl;
//	return 0;
//
//}

#include<vector>

//int main()
//{
//
//	int a;
//	int c;
//	cin >> a >> c;
//
//	vector<int> VV;
//
//	int b;
//
//	vector<vector<long long>> V;
//	long long s = 0;
//	V.resize(a + 1);
//	
//	for (int i = 0; i < a; i++)
//	{
//		long long num = 0;
//		for (int j = 0; j < c; j++) {
//			
//			cin >> b;
//			num += b;
//			
//			V[i].push_back(b);
//
//			if (j + 1 == c)
//			{
//				V[i].push_back(num);
//			}
//
//		}
//	}
//
//
//	for (int i = 0; i < V[0].size(); i++)
//	{
//		int num = 0;
//		for (int j = 0; j < V.size() - 1; j++)
//		{
//			num += V[j][i];
//		}
//		V[a].push_back(num);
//	}
//
//	
//	for (int i = 0; i < a; i++)
//	{
//		for (int j = 0; j < c; j++) {
//
//			cout<<V[i][c]+V[a][j]-V[i][j]<<" ";
//		}
//		cout << endl;
//	}
//
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//    int a, c;
//    cin >> a >> c;
//
//    vector<vector<long long>> V(a, vector<long long>(c));
//    vector<long long> row_sum(a, 0);
//    vector<long long> col_sum(c, 0);
//
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j < c; j++) {
//            cin >> V[i][j];
//            row_sum[i] += V[i][j];
//            col_sum[j] += V[i][j];
//        }
//    }
//
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << row_sum[i] + col_sum[j] - V[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//4 2
//3 5 1 7
//4 6 5 1


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size, days;
    cin >> size >> days;

    vector<long long> V(size);
    vector<long long> _V(size);

    for (int i = 0; i < size; ++i) {
        cin >> V[i];
    }

    for (int i = 0; i < size; ++i) {
        cin >> _V[i];
    }

    long long expect = 0;
    long long shame = 0;

    for (int j = 0; j < days; j++) {
        shame += _V[j];
        expect += V[j];
    }

    int right = days;
    int left = 0;
    int _left = 0;

    long long _expect = expect;
    long long _shame = shame;

    while (right < V.size()) {
        _expect = V[right] + _expect - V[left];
        _shame = _V[right] + _shame - _V[left];

        if (_expect > expect) {
            expect = _expect;
            _left = left + 1;
        }

        if (_expect == expect && shame > _shame) {
            shame = _shame;
            _left = left + 1;
        }

        right++;
        left++;
    }

    cout << _left + 1 << endl;

    return 0;
}

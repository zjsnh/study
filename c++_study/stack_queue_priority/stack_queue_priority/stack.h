#pragma once
//#include"list.h"
#include<list>
#include<deque>
#include<vector>
//using namespace std;
//#include<list>

namespace sk
{
	template<class T, class Container=deque<T> >
	class stack
	{

	public:

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		const T& top()
		{
			return _con.back();
		}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};

}

#pragma once

#include<list>
#include<deque>

namespace qu
{
	template <class T, class Container = deque<T> >
	class queue
	{
	public:


		void push(const T& val)
		{
			_con.push_front();
		}
		void pop()
		{
			_con.pop_back;
		}

		const T& front()
		{
			return _con.front();
			//*(_con.begin());
		}

		const T& back()
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
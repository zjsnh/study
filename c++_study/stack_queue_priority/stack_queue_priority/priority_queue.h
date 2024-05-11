#pragma once

#include<vector>
#include<deque>

namespace priority
{
	template<class T, class Container=vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
		{	}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first,last)
		{
			for (int i = (_con.size() - 2) / 2; i > 0; --i)
			{
				adjust_down(i);
			}
		}

	protected:
		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;

			while (child > 0)
			{
				/*if (_con[parent] < _con[child])
				{
					swap(_con[parent], _con[child]);
				}*/
				if(com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}

				
			}
		}

		void adjust_down(int parent)
		{
			Compare com;
			int size = _con.size();
			int child = parent * 2 + 1;

			while (child < size)
			{
				if (child + 1 < size && com(_con[child], _con[child+1]))
				{
					child++;
				}

				if(com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	public:
		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size()-1);
		}

		void pop()
		{
			//  保证整体结构不变
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
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

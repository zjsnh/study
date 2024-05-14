#pragma once

#include<cstdbool>
#include<cassert>
#include"iterator.h"

namespace vec
{
	template< class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;
		typedef ReverseIterator<const_iterator,const T&,const T*> const_reverse_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		iterator begin() const
		{
			return _start;
		}
		 
		iterator end() const
		{
			return _finish;
		}

		iterator cbegin() const 
		{
			return _start;
		}

		iterator cend() const
		{
			return _finish;
		}


		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{		}

		vector(size_t size, const T& val = T())
		{
			reserve(size);
			while (_start != _endofstorage)
			{
				*_start = val;
				_start++;
			}
		}

		vector(int size, const T& val = T())
		{
			reserve(size);
			while (_start != _endofstorage)
			{
				*_start = val;
				_start++;
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator finish)
		{
			while (first != finish)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector<T>& v)
		{
			reserve(v.capacity());

			/*vector<T>::const_iterator it = v.cbegin();
			while (it != v.cend())
			{
				push_back(*it);
				it++;
			}*/

			for (auto e : v)
			{
				push_back(e);
			}
		}

		~vector()
		{
			delete[] _start;

			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		void push_back(T data)
		{
			if (size() == capacity())
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = data;
			_finish++;
		}

		void resize(size_t n,const T& val=T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* temp = new T[n];
				if (_start != nullptr)
				{
					for (size_t i = 0; i < sz; i++)
					{
						temp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = temp;
				_finish = _start + sz;
				_endofstorage = _start + n;

			}
		}

		void insert(iterator pos, const T& val)
		{
			assert(pos < _finish);
			assert(pos >= _start);


			if (size() == capacity())
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());

				pos = _start + len;
			}

			memmove(pos, pos + 1, sizeof(int)*(_finish - pos));

			*pos = val;
			_finish++;

		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			assert(pos >= _start);


			memmove(pos+1, pos, sizeof(int) * (_finish - pos));
			_finish--;

			return pos;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
				
			/*return *(start + pos);*/
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t size() const 
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;
	};

}

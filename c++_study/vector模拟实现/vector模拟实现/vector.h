#pragma once
#include<assert.h>


namespace vec
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;

		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		iterator begin()const
		{
			return _start;
		}

		iterator end()const 
		{
			return _finish;
		}

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
		{}

		~vector()
		{
			delete[] _start;

			_start = nullptr;
			_finish = nullptr;
			_endofstorage = nullptr;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _endofstorage - _start;
		}

		void resize(size_t vale_size, size_t vale = 0)
		{
			size_t sz = size();//
			size_t sz_capacity = capacity();
			T* tmp = new T[vale_size]{ 0 };
			if (sz > vale_size) // 如果原vector长度大于vale_size，将数据拷贝字节改变为vale_size；
				sz = vale_size;
			else
				sz_capacity = vale_size;
			memcpy(tmp, _start, sizeof(T) * sz);
			delete[] _start;
			_start = tmp;
			_finish = _start + vale_size;
			_endofstorage = _start + sz_capacity;
			
		}

		//void resize(size_t vale_size, T vale = 0)
		//{
		//	size_t sz = size();
		//	size_t sz_capacity = capacity();

		//	if (sz > vale_size) // 如果原vector长度大于vale_size，将数据拷贝字节改变为vale_size；
		//		sz = vale_size;
		//	else
		//		sz_capacity = vale_size;

		//	T* tmp = new T[vale_size]{ vale };
		//	std::copy(_start, _start + sz, tmp);
		//	delete[] _start;
		//	_start = tmp;
		//	_finish = _start + vale_size;
		//	_endofstorage = _start + sz_capacity;
		//}

		/*void resize(size_t n, const T& val = T())
		{
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}*/


		void reserve(size_t vale_size)
		{
			if (_finish == _endofstorage)
			{
				size_t sz = size();
				//size_t capacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[vale_size];

				if (_start != nullptr)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + vale_size;

			}
		}

		//void push_back(T vale)
		void push_back(const T& vale)//减小程序拷贝
		{
			if (_finish == _endofstorage)
			{
				/*size_t sz = size();
				size_t capacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[capacity];

				if (_start != nullptr)
				{
					memset(tmp, _start, sizeof(sz));
					delete[] _start;
				}

				_start = tmp;

				_finish = _start + tmp;
				_endofstorage = _start + capacity;
				size_t sz = size();*/
				size_t _capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(_capacity);
			}

			*_finish = vale;
			_finish++;
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos < _finish);
			assert(pos > _start);

			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				/*size_t _capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(_capacity);*/
				reserve(capacity() == 0 ? 4 : capacity() * 2);

				//扩容后，迭代器还是指向之前的空间，导致迭代器失效，

				pos = _start + len;
			}

			memmove(pos + 1, pos, sizeof(T) * (_finish - pos));

			*(pos) = x;
			_finish++;
		}

		/*void insert(size_t pos, const T& x)
		{
			assert(pos < size());


			if (_finish == _endofstorage)
			{
				size_t _capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(_capacity);
			}

			memmove(_start + pos + 1, _start + pos, sizeof(T) * (_finish - (_start + pos)));

			_start[pos] = x;
			_finish++;

		}*///

		void erase(iterator pos)
		{

			assert(pos < _finish);
			assert(pos > _start);

			memmove(pos, pos+1, sizeof(T) * (_finish - pos));
			_finish--;
		}


		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}



	private:

		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

}
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

		//template <class InputIterator>//使用迭代器进行赋值
		//vector(InputIterator first, InputIterator last)
		//{
		//	//w.reserve(last - first);
		//	while (first != last)
		//	{
		//		push_back(*first);
		//		++first;
		//	}

		//}

		vector(size_t n, const T& val = T())//用vector大小跟初始值初始化
		{
			reserve(n);
			while (_finish != _endofstorage)
			{
				*_finish = val;
				_finish++;
			}

			/*for (size_t i = 0; i < n; i++)
			{
				*_finish = val;
				_finish++;
			}*/

			/*for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}*/
		}

		vector(const vector<T>& s)
		{
			reserve(s.capacity());

			for (auto& e : s)
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

		size_t size()const
		{
			return _finish - _start;
		}

		size_t capacity()const
		{
			return _endofstorage - _start;
		}

		//void resize(size_t vale_size, T vale = 0)
		//{
		//	size_t sz = size();
		//	size_t sz_capacity = capacity()
		//	if (sz > vale_size) // 如果原vector长度大于vale_size，将数据拷贝字节改变为vale_size；
		//		sz = vale_size;
		//	else
		//		sz_capacity = vale_size;
		//	T* tmp = new T[vale_size]{ vale };
		//	std::copy(_start, _start + sz, tmp);//memcpy(tmp, _start, sizeof(T) * sz);
		//	delete[] _start;
		//	_start = tmp;
		//	_finish = _start + vale_size;
		//	_endofstorage = _start + sz_capacity;
		//}

		/*template<class type>
		void swap(type& t1, type& t2)
		{
			type temp = t1;
			t1 = t2;
			t2 = temp;
		}*/

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);

		}

		vector<T>& operator=(vector<T> tmp)//形参
		{
			swap(tmp);

			return *this;
		}

		//非常冗余的两段代码

		void resize(size_t vale_size, const T& val = T())
		{
			if (vale_size <= size())
			{
				_finish = _start + vale_size;
			}
			else
			{
				reserve(vale_size);
				while (_finish < _start + vale_size)
				{
					*_finish = val;
					++_finish;
				}
			}
		}


		void reserve(size_t vale_size)
		{
			if (vale_size > capacity())//n > capacity()
			{
				size_t sz = size();
				//size_t capacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[vale_size];

				if (_start != nullptr)
				{
					memcpy(tmp, _start, sizeof(T)*sz);
				}
				delete[] _start;
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + vale_size;

			}
		}

		//void push_back(T vale)
		void push_back(const T& vale)//减少程序拷贝
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
			assert(pos >= _start);

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
			assert(pos >= _start);

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
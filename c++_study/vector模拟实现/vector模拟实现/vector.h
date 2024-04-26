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

		vector(int n, const T& val = T())
			//处理两个都是int size_t类型的传参
			// 编译器就会调用最匹配的函数去调用
		{
			reserve(n);
			while (_finish != _endofstorage)
			{
				*_finish = val;
				_finish++;
			}
		}

		template <class InputIterator>//使用迭代器进行赋值
		vector(InputIterator first, InputIterator last)
		{
			//w.reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				++first;
			}
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

		void swap(vector<T>& v)//等同于vector& v  但是建议写全
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
					//memcpy(tmp, _start, sizeof(T)*sz);//导致深层次的浅拷贝

					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
						//每一个string对象去调用库里面的拷贝构造函数，进行对string对象的深拷贝，
						//也就是说对于有自己空间的对象，不能使用memcpy拷贝
					}
					delete[] _start;
				}
				
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

		/*iterator*/void insert(iterator pos, const T& x)//返回插入位置的迭代器，防止迭代器失效
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

			//return pos;
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

		iterator erase(iterator pos)//返回当前位置的迭代器,防止迭代器失效
		{

			assert(pos < _finish);
			assert(pos >= _start);

			memmove(pos, pos+1, sizeof(T) * (_finish - pos));
			_finish--;

			return pos;
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

		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstorage = nullptr;//缺省值，防止忘写初始化导致崩溃
	};

}
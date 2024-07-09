#pragma once
#include<cstdbool>
#include<cassert>


namespace str
{
	class string
	{

	public:
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		void swap(string& temp)
		{
			std::swap(_str, temp._str);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}

		string(const string& str)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string temp(str._str);
			swap(temp);

		}

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
			_str = nullptr;
		}

		/*Lose one's mind*/
		/*string& operator=(const string& str)
		{
			if (this != &str)
			{
				char* temp = new char[str._capacity + 1];
				strcpy(temp, str._str);
				delete[] _str;

				_str = temp;
				_size = str._size;
				_capacity = str._capacity;
			}
		}*/

		string& operator=(string& str)
		{
			swap(str);
			return *this;
		}


		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& operator+=(char str)
		{
			push_back(str);
			return *this;
		}

		char& operator[](size_t pos)
		{
			assert(pos > 0 && pos < _size);

			//return *(_str + pos);

			return _str[pos];//_str本来就是 char* 
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);

			/*return *(_str + pos);*/

			return _str[pos];
		}

		size_t capacity()
		{
			return _capacity;
		}

		size_t size()
		{
			return _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strcpy(_str, temp);
				delete[] _str;
				_str = temp;
				_capacity = n;
			}
		}

		void push_back(char str)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size++] = str;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t size = strlen(str);
			if (_size + size >= _capacity)
			{
				reserve(_size + size);
			}
			strcpy(_str + _size, str);
			_size += size;
		}

		/*strcpy 函数，memmove 函数
		memmove 更为健壮和高效，特别是在处理重叠内存区域时。*/

		void insert(size_t pos, char ch)
		{
			assert(pos > 0 && pos < _size);
			/*if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}*/

			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			/*strcpy(_str + pos + 1, _str + pos);*/

			memmove(_str + pos + 1, _str + pos, _size - pos);
			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos > 0 && pos < _size);
			size_t size = strlen(str);
			if (_size + size >= _capacity)
			{
				reserve(_size + size);
			}
			memmove(_str + pos + size, _str + pos, _size - pos);
			//strcpy(_str + pos, str);
			memmove(_str + pos, str, size);
			_size++;

		}

		void erase(size_t pos, size_t len = npos)//用静态成员才能调用
		{
			assert(pos > 0 && pos < _size);
			if (len==npos||len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				memmove(_str + pos, _str + pos + len, _size - pos - len);
				_size -= len;
				_str[_size] = '\0';
			}
		}

		size_t find(const char* str, size_t pos = npos)
		{
			assert(pos >= 0 && pos < _size);
			const char* p = strstr(_str + pos, str);//匹配字符串

			if (p == nullptr)
				return npos;
			else
				return p - _str;//指针相减返回距离
		}

		string substr(size_t pos = 0, size_t len = npos) const //取子串
		{
			string temp;
			size_t size = pos + len;
			if (len == npos || pos + len >= _size)
			{
				size = _size;
			}

			for (size_t i = pos; i < size; i++)
			{
				temp += _str[i];
			}

		}



	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;
	};

}

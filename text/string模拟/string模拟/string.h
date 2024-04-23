#pragma once
#include<assert.h>

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

		/*string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{}*/

		~string()
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
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

		iterator begin()const
		{

			return _str;
		}

		iterator end()const
		{

			return _str + _size;
		}

		void clear()
		{
			_str[0] = '\0';
			_size = 0;
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
			assert(pos < _size);

			/*return *(_str + pos);*/

			return _str[pos];
		}

		const char& operator[](size_t pos)const
		{
			assert(pos < _size);

			/*return *(_str + pos);*/

			return _str[pos];
		}

		size_t capacity() const
		{
			return _capacity;
		}

		size_t size() const
		{
			return _size;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* temp = new char[n + 1];
				strcpy(temp, _str);
				delete[]_str;
				_str = temp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(2 * _capacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';//重要！！！！
		}

		void append(const char* c)
		{
			size_t len = strlen(c);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}

			strcpy(_str + _size, c);

			_size += len;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos < _size);

			if (_size >= _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			//size_t end = _size;
			/*while (end >= pos)
			{
				_str[end + 1] = _str[end];
				end--;
			}*/
			memmove(_str + pos + 1, _str + pos, _size - pos); 
			_str[pos] = ch;

			_size++;
		}


		void insert(size_t pos, const char* str)
		{

			size_t len = strlen(str);//长度

			assert(pos < _size);

			if (_size + len >= _capacity)
			{
				reserve(_size + len);
			}

			memcpy(_str + pos + len, _str + pos, _size - pos);
			memcpy(_str + pos, str, strlen(str));

			_size += strlen(str);
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos)
			{
				_str[pos] = '\0';
			}
			else
			{
				//memmove(_str + pos, _str + pos + npos, _size - pos - npos);
				memmove(_str + pos, _str + pos + len, _size - pos - len);
				_size -= len;
				_str[_size] = '\0';
			}


		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1;
	};


	ostream& operator<<(ostream& out, const string& s)
	{
		/*string::iterator it = s.begin();

		while (it != s.end())
		{
			out << *it;
			it++;
		}*/

		for (auto ch : s)
		{
			out << ch;
		}

		out << endl;

		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();


		char ch = ' ';
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
 	}

}
#pragma once
#include<assert.h>

namespace str
{
	class string
	{

	public:

		/*string()
			:_str(new char[1]{'\0'})
			,_size(0)
			,_capacity(0)
		{}*/

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}

		/*string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);


			_size = s._size;
			_capacity = s._capacity;
		}*/

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string temp(s._str);

			swap(temp);
		}

		// =的重载 函数的写法

		/*void operator=(const string& s)
		{
			if ( this!=&s)
			{
				char* temp = new char[s._capacity + 1];
				strcpy(temp, s._str);
				delete[] _str;

				_str = temp;
				_size = s._size;
				_capacity = s._capacity;
			}
		}*/

		//string& operator=(const string& s)
		//{
		//	if (/*_str != s._str*/ this!=&s)
		//	{
		//		string temp(s._str);
		//		swap(temp);
		//		return *this;
		//	}
		//	
		//}


		string& operator=(string temp)
		{
			swap(temp);
			return *this;
		}


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

			if (len == npos || pos + len > _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//memmove(_str + pos, _str + pos + npos, _size - pos - npos);
				memmove(_str + pos, _str + pos + len, _size - pos - len);
				_size -= len;
				_str[_size] = '\0';
			}
		}

		size_t find(const char* str, size_t pos = npos)
		{

			const char* p = strstr(_str+pos, str);

			if (p != NULL)
			{
				return p - _str;
			}
			else
			{
				return npos;
			}
		}

		/*string substr(size_t pos = 0, size_t len = npos) const
		{

			string temp;

			if (npos + pos >= _size||len == npos)
			{
				size_t len = _size - pos;
				temp.reserve(len);
				for (size_t i = pos; i < _size; i++)
				{
					temp += _str[i];
				}
			}
			else
			{
				temp.reserve(len);
				for (size_t i = pos; i < pos+len; i++)
				{
					temp += _str[i];
				}
			}

			temp._str[_size] = '\0';
		}*/

		string substr(size_t pos = 0, size_t len = npos) const
		{

			string temp;
			size_t size = pos + len;
			if (npos + pos >= _size || len == npos)
			{
				len = _size - pos;
				size = _size;
			}

			temp.reserve(len);

			for (size_t i = pos; i < size; i++)
			{
				temp += _str[i];
			}

			temp._str[_size] = '\0';
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
		}

		out << endl;*/
		for (auto ch : s)
		{
			out << ch;
		}
		out << endl;
		return out;
	}

	//istream& operator>>(istream& in, string& s)
	//{
	//	s.clear();


	//	char ch = ' ';
	//	ch = in.get();//防止<<无法接收 ' ' 和 '\n' 
	//	while (ch != ' ' && ch != '\n')
	//	{
	//		s += ch;
	//		ch = in.get();
	//	}

	//	return in;
	//}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		char buttf[129];

		char ch = ' ';
		ch = in.get();//防止<<无法接收 ' ' 和 '\n' 
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{

			buttf[i++] = ch;
			if (i == 128)
			{
				buttf[i] = '\0';

				s += buttf;
				i = 0;
			}

			ch = in.get();
		}

		if (i != 0)
		{
			buttf[i] = '\0';

			s += buttf;
			i = 0;
		}

		return in;
	}

}
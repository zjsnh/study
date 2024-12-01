#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>

namespace paper
{
	class string
	{
	public:
		// 构造函数
		// 析构函数
		// 重载函数
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1]; //" /0 ";
			strcpy(_str, str);
		}

		void swap(string& temp)
		{
			std::swap(_str, temp._str);
			std::swap(_capacity, temp._capacity);
			std::swap(_size, temp._size);
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
			_capacity = 0;
			_size = 0;
		}


		string& operator=(string& str)
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
		}

		char& operator[](size_t pos)
		{
			assert(pos > 0 && pos < _size);
			return _str[pos];
		}

	private:
		char* _str;
		int _capacity;
		int _size;
	};

	struct list_node
	{
		int val;
		list_node* next;
		list_node* prev;

		list_node(const int& _val = 0)
			:val(_val),
			next(nullptr),
			prev(nullptr)
		{
		}
	};

	struct _iterator
	{
		typedef list_node* Node;
		Node node;

		_iterator(Node _node)
			:node(_node)
		{
		}

		bool operator!=(const _iterator& it)
		{
			return node != it.node;
		}

		int operator*()
		{
			return node->val;
		}

		int* operator->()
		{
			return &(node->val);
		}
		 
		_iterator operator++(int) //后置
		{
			_iterator temp(this->node);
			node = node->next;
			return temp;
		}

		_iterator operator++() //前置
		{
			node = node->next;
			return *this;
		}

		_iterator operator++() //后置
		{
			node = node->prev;
			return *this;
		}
	};

	class list
	{
	public:
		typedef list_node Node;
		typedef _iterator iterator;

		iterator begin()
		{
			return _head->next;
		}

		iterator end()
		{
			return _head;
		}

		void I_empty()
		{
			_head = new Node();
			_head->next = _head;
			_head->prev = _head;


			size = 0;
		}

		list(const int& _val = 0)
		{
			I_empty();

			_head->val = _val;
		}

		list(list& l)
		{
			I_empty();

			for (auto e : l)
			{
				push_back(e);
			}
		}

		~list()
		{

		}

		void push_back(const int& val)
		{
			insert(end(), val);
		}

		void push_front(const int& val)
		{
			insert(begin(), val);
		}

		iterator insert(const iterator& pos,const int& x)
		{
			Node* cur = pos.node;
			Node* newnode = new Node(x);

			Node* prev = cur->prev;
			prev->next = newnode;
			newnode->prev = prev;

			cur->prev = newnode;
			newnode->next = cur;

			++size;

			return newnode;
		}
		
		iterator earse(const iterator& pos)
		{
			Node* cur = pos.node;
			Node* prev = cur->prev;
			Node* next = cur->next;

			delete cur;
			prev->next = next;
			next->prev = prev;

			--size;

			return next;  //注意迭代器失效问题
		}

	private:
		list_node* _head;
		size_t size;
	};
}

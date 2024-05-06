#pragma once
/*
* 
* 带头循环双向链表
*/
#include<cstdbool>

namespace lt
{
	template<class T>
	struct list_node
	{
		T data;
		list_node<T> *_next;
		list_node<T> *_prev;


		list_node(const T& val=T())
			:data(val),
			_next(nullptr),
			_prev(nullptr)
		{}
	};


	template<class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T> seft;

		Node* _node;


		_list_iterator(Node* node)
			:_node(node)
		{

		}

		seft& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		T& operator*()
		{
			return _node->data;
		}
		T* operator->()
		{
			return &_node->data;
		}

		bool operator==(const seft& it)
		{
			/*return *this == it;*/

			return _node == it._node;
		}

		bool operator!=(const seft& it)
		{
			/*return *this == it;*/

			return _node != it._node;
		}



	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T> iterator;

	public:
		iterator begin()
		{
			//return iterator(head);

			return head->_next;
		}

		iterator end()
		{
			return head;
		}

		void empty_init()
		{
			head = new Node;
			head->_next = head;
			head->_prev = head;


			size = 0;

		}

		list()
		{
			empty_init();
		}

		/*list<T>& operator=(list<T> ls)
		{
			if (*this != ls)
			{
				clear();
				for (auto it : ls)
				{
					push_back(it);
				}
			}

			return *this;
		}*/

		void swap(list<T>& ls)
		{
			std::swap(this->head, ls.head);
			std::swap(this->size, ls.size);
		}

		list<T>& operator=(list<T> ls)
		{
			swap(ls);

			return *this;
		}




		list(const list<T>& ls)//拷贝构造  但是需要 const_iterator  
		{
			empty_init();
			for (auto it : ls)
			{
				push_back(it);
			}

		}



		~list()
		{
			clear();

			delete head;
			head = nullptr;

		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(T data)
		{
			insert(end(), data);
		}

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* newnode = new Node(x);

			Node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			++size;

			return iterator(newnode);//返回新插入位置的迭代器
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;

			--size;

			return iterator(next);//防止迭代器失效
		}



	private:
		Node* head;
		size_t size;
	};
}
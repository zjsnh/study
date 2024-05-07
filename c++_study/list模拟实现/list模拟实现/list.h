#pragma once
/*
*
* 带头循环双向链表
*/
#include<cstdbool>

namespace lt
{
	//template<class T>
	//struct list_node
	//{
	//	T data;
	//	list_node<T> *_next;
	//	list_node<T> *_prev;


	//	list_node(const T& val=T())
	//		:data(val),
	//		_next(nullptr),
	//		_prev(nullptr)
	//	{}
	//};


	///*template<class T>
	//struct _list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef _list_iterator<T> seft;
	//	Node* _node;
	//	_list_iterator(Node* node)
	//		:_node(node)
	//	{
	//	}
	//	seft& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	T& operator*()
	//	{
	//		return _node->data;
	//	}
	//	T* operator->()
	//	{
	//		return &_node->data;
	//	}
	//	bool operator==(const seft& it)
	//	{
	//		return *this == it;
	//		return _node == it._node;
	//	}

	//	bool operator!=(const seft& it)
	//	{
	//		return *this == it;

	//		return _node != it._node;
	//	}
	//};*/

	//template<class T,class ref,class ptr >
	//struct _list_iterator
	//{
	//	typedef list_node<T> Node;
	//	typedef _list_iterator<T, ref, ptr> seft;

	//	typedef ref reference;
	//	typedef ptr pointer;

	//	Node* _node;


	//	_list_iterator(Node* node)
	//		:_node(node)
	//	{}

	//	seft& operator++()
	//	{
	//		_node = _node->_next;
	//		return *this;
	//	}

	//	pointer operator*()
	//	{
	//		return _node->data;
	//	}

	//	reference operator->()
	//	{
	//		return &_node->data;
	//	}

	//	bool operator==(const seft& it)
	//	{
	//		/*return *this == it;*/

	//		return _node == it._node;
	//	}

	//	bool operator!=(const seft& it)
	//	{
	//		/*return *this == it;*/

	//		return _node != it._node;
	//	}
	//};

	//template<class T>
	//class list
	//{
	//	typedef list_node<T> Node;
	//public:
	//	typedef _list_iterator<T, T*, T&> iterator;
	//	typedef _list_iterator<T, const T*, const T&> const_iterator;

	//public:

	//	const_iterator begin() const
	//	{
	//		//return iterator(head);

	//		return const_iterator(head->_next);
	//	}

	//	const_iterator end() const
	//	{
	//		return head;
	//	}


	//	iterator begin()
	//	{
	//		//return iterator(head);

	//		return head->_next;
	//	}

	//	iterator end()
	//	{
	//		return head;
	//	}

	//	

	//	void empty_init()
	//	{
	//		head = new Node;
	//		head->_next = head;
	//		head->_prev = head;


	//		size = 0;

	//	}

	//	list()
	//	{
	//		empty_init();
	//	}

	//	/*list<T>& operator=(list<T> ls)
	//	{
	//		if (*this != ls)
	//		{
	//			clear();
	//			for (auto it : ls)
	//			{
	//				push_back(it);
	//			}
	//		}

	//		return *this;
	//	}*/

	//	void swap(list<T>& ls)
	//	{
	//		std::swap(this->head, ls.head);
	//		std::swap(this->size, ls.size);
	//	}

	//	list<T>& operator=(list<T> ls)
	//	{
	//		swap(ls);

	//		return *this;
	//	}

	//	list(const list<T>& ls)//拷贝构造  但是需要 const_iterator  
	//	{
	//		empty_init();
	//		for (auto it : ls)
	//		{
	//			push_back(it);
	//		}

	//	}

	//	~list()
	//	{
	//		clear();

	//		delete head;
	//		head = nullptr;

	//	}

	//	void clear()
	//	{
	//		iterator it = begin();
	//		while (it != end())
	//		{
	//			it = erase(it);
	//		}
	//	}

	//	void push_back(T data)
	//	{
	//		insert(end(), data);
	//	}

	//	iterator insert(iterator pos, const T& x)
	//	{
	//		Node* cur = pos._node;
	//		Node* newnode = new Node(x);

	//		Node* prev = cur->_prev;

	//		// prev newnode cur
	//		prev->_next = newnode;
	//		newnode->_prev = prev;

	//		newnode->_next = cur;
	//		cur->_prev = newnode;

	//		++size;

	//		return iterator(newnode);//返回新插入位置的迭代器
	//	}

	//	iterator erase(iterator pos)
	//	{
	//		Node* cur = pos._node;
	//		Node* prev = cur->_prev;
	//		Node* next = cur->_next;

	//		delete cur;
	//		prev->_next = next;
	//		next->_prev = prev;

	//		--size;

	//		return iterator(next);//防止迭代器失效
	//	}



	//private:
	//	Node* head;
	//	size_t size;
	//};

	template<class T>
	struct list_node
	{
		T _data;
		list_node<T>* _next;
		list_node<T>* _prev;

		list_node(const T& x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	// T T& T*
	// T cosnt T& const T*
	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}


		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;

			return tmp;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;

			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//typedef __list_const_iterator<T> const_iterator;

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		iterator begin()
		{
			//return iterator(_head->_next);
			return _head->_next;
		}

		iterator end()
		{
			//return iterator(_head->_next);
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		// lt2(lt1)
		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		// lt3 = lt1
		list<int>& operator=(list<int> lt)
		{
			swap(lt);

			return *this;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
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

			++_size;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			delete cur;
			prev->_next = next;
			next->_prev = prev;

			--_size;

			return iterator(next);
		}

		size_t size()
		{
			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};


	void test_list4()
	{
		list<int> lt;
		list<int>::const_iterator it =  lt.begin();
	}
}
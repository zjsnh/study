#pragma once
#include<cstdbool>

namespace lt
{
	template<class T>
	struct list_node
	{
		T _data;
		list_node* _next;
		list_node* _prev;


		//list_node()
		//	:_data(const T& x = T())
		//	, _next(nullptr)
		//	, _prev(nullptr)
		//{}

		list_node(const T& val = T())
			:_data(val)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template <class T>
	struct _list_iterator
	{
		typedef list_node<T> Node;
		typedef _list_iterator<T> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		self& operator++()
		{
			_node = _node->_next;
			return _node;
		}

		T& operator*()
		{
			return _node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef _list_iterator<T> iterator;

		iterator end()
		{
			return _head;
		}

		iterator begin()
		{
			return _head->_prev;
		}

		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void push_back(const T& data)
		{
			
			/*Node* tmp = new Node;
			tmp->_data = data;
			_head->_prev->_next = tmp;
			tmp->_prev = _head->_prev;
			tmp->_next = _head;*/

			insert(end(), data);

		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* tmp = new Node(x);

			Node* prev = cur->_prev;

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;

			newnode->_next = cur;
			cur->_prev = newnode;

			++_size;

			return iterator(newnode);
		}

		iterator earse(iterator pos)
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
		size_t size;
	};
}
#pragma once
#include<cstdbool>
//#include<cassert>


namespace lt
{
	template<class T>
	struct ListNode
	{
		T _val;
		ListNode<T>* _next;
		ListNode<T>* _prev;

		ListNode(const T&val =T())
			:_val(val),
			_next(nullptr),
		    _prev(nullptr)
		{		}

	};

	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T>* Node;
		typedef __list_iterator<T, Ref, Ptr> sef;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		typedef Ref reference;
		typedef Ptr pointer;

		Node _node;

		__list_iterator(Node node)
			:_node(node)
		{	}

		__list_iterator(const iterator& it)
			:_node(it._node)
		{	}

		bool operator==(const sef& it)
		{
			return _node == it._node;
		}

		bool operator!=(const sef& it)
		{
			return _node != it._node;
		}

		reference operator*() const   /* " * "返回val的别名 & 引用返回*/
		{
			return (*_node)._val;
		}

		pointer operator->() const /* " -> " 返回指针 */
		{
			
			return &operator*();
		}

		sef operator++(int)
		{
			sef temp(*this);
			_node = _node->_next;

			return temp;
		}

		sef operator++()
		{
			_node = _node->_next;

			return *this;
		}

		sef operator--(int)
		{
			sef temp(*this);
			_node = _node->_prev;

			return temp;
		}

		sef operator--()
		{
			_node = _node->_prev;

			return *this;
		}


	};

	template<class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T,const T&,const T*> iterator;

		///*    --- list  Lead two-way linked list 	*/

		iterator begin()
		{
			return _head->_next;
			//retunr iterator(_head->_next);
		}

		iterator end()
		{
			return _head;
		}

		iterator begin() const 
		{
			return _head->_next;
			//retunr iterator(_head->_next);
		}

		iterator end() const 
		{
			return _head;
		}

		iterator cbegin() const
		{
			return _head->_next;
			//retunr iterator(_head->_next);
		}

		iterator cend() const
		{
			return _head;
		}

		list()
		{
			I_empty();
		}

		~list()
		{
			clear();
		}

		list(const list& l)
		{
			I_empty();
			for (auto it : l)
			{
				push_back(it);
			}
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it=erase(it);
				
			}

		}

		void swap(list<T> l)
		{
			std::swap(_head, l._head);
			std::swap(_size, l._size);
		}

		list<T>& operator=(list<T>& l)
		{
			swap(l);
			return 0;
		}

		void I_empty()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;


			_size = 0;
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_front()
		{
			erase(--end());
		}

		size_t size()
		{
			return _size;
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


	private:
		Node* _head;
		size_t _size;
	};
}

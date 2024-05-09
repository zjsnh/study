#pragma once
#include<cstdbool>
#include<cassert>


namespace lt
{
	template<class T>
	struct ListNode
	{
		T _val;
		ListNode* _next;
		ListNode* _prev;

		ListNode(const T&val =T())
			:_val(val),
			_next = nullptr,
		    _prev = nullptr
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
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	private:
		Node* _head;
		size_t _size;
	};
}

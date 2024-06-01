#pragma once

#include<assert.h>



template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _left;
	
	pair<K, V> _kv;
	int _pf;

	AVLTreeNode(const pair<K,V>& kv)
		:_parent(nullptr)
		, _right(nullptr)
		, _left(nullptr)
		, _kv(kv)
		, _pf(0)
	{}

};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool insert(const pair<K,V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else(parent->_kv.first < kv.first)
		{
			parent->right = cur;
			cur->_parent = parent;
		}

		while ()
		{
			if (parent->_left = cur)
			{
				parent->_pf--;
			}
			else (parent->_right = cur)
			{
				parent->_pf++;
			}


			if (parent->_pf == 0)
			{
				break;
			}
			else if (parent->_pf == -1 || parent->_pf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_pf == -2 || parent->_pf == 2)
			{
				//Ðý×ª
			}
			else
			{
				assert(false);
			}
		}

	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		//subRL->_parent = parent;
		parent->_right = subRL;
		subR->_left = parent;

		Node* Parent = parent->_parent;
		parent->_parent = subR;
		if (subRL)
			subRL->_parent = parent;

		if (Parent == _root)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (Parent->_left == parent)
			{
				Parent->_left = subR;
			}
			else
			{
				Parent->_right = subR;
			}
		}


		subR->_pf = parent->_pf = 0;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;

		Node* Parent = parent->_parent;
		parent->_parent = subR;

		if (subLR)
			subLR->_parent = parent;

		if (Parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (Parent->_left == parent)
			{
				Parent->_left = subL;
			}
			else
			{
				Parent->_right = subL;
			}
		}

		subL->_pf = parent->_pf = 0;

	}

private:
	Node* _root=nullptr
};

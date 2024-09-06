#pragma once
#include<assert.h>


template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _parent;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _left;


	pair<K, V> _kv;
	int _bf;


	AVLTreeNode(const pair<K,V>& kv)
		:_parent(nullptr)
		,_right(nullptr)
		,_left(nullptr)
		,_kv(kv)
		,_bf(0)
	{}

};


template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}


		//与二叉搜索树一样的插入
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
		cur->_bf = 0;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;

				//往上判断
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				//旋转

				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf = 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf = -1)
				{
					RotateRL(parent);
				}

			}
		}

		void RotateR(Node * pParent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			subL->_right = parent;
			Node* Parent = parent->_parent;
			parent->_parent = subL;
			subL->_parent = Parent;

			if (Parent == nullptr)
			{
				_root = subL;
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

			subL->_bf = parent->_bf = 0;
		}

		void RotateL(Node * parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			parent->_right = subRL;
			if (subRL) subRL->_parent = parent;

			subR->_left = parent;
			Node* Parent = parent->_parent;
			parent->_parent = subR;
			subR->_parent = Parent;

			if (Parent == nullptr)
			{
				_root = subR;
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

			subR->_bf = parent->_bf = 0;
		}

		void RotateLR(Node * parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(subL);
			RotateR(parent);

			if (1 == bf)
				subL->_bf = -1;
			else if (-1 == bf)
				parent->_bf = 1;
		}


	}

private:
	Node* _root = nullptr;
};
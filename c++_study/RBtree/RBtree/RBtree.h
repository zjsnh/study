#pragma once

#include<assert.h>



// key_value;
enum colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _parent;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _left;

	pair<K, V> _kv;
	colour _colour;

	RBTreeNode(const pair<K, V>& kv)
		:_parent(nullptr)
		, _right(nullptr)
		, _left(nullptr)
		, _kv(kv)
		, _colour(RED)
	{}

};


template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;

public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_colour = BLACK;
			return  true;
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
		cur->_colour = RED;
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

		while (parent && parent->_colour == RED)
		{

			//      g
			//   p     u
			//c
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;

				if (uncle && uncle->_colour == RED)
				{
					//更换颜色
					parent->_colour = uncle->_colour = BLACK;	
					grandfather->_colour = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					//单旋
					//       g
					//    p
					// c

					//双旋
					//       g
					//    p
					//       c
					if (cur==parent->_left)
					{
						RotateR(grandfather);
						grandfather->_colour = RED;
						parent->_colour = BLACK;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						grandfather->_colour = RED;
						cur->_colour = BLACK;
					}


					break;
					
				}
			}
			else
			{
				Node* uncle = grandfather->_left;

				if (uncle && uncle->_colour == RED)
				{
					//更换颜色
					parent->_colour = uncle->_colour = BLACK;
					grandfather->_colour = RED;

					cur = grandfather; 
					parent = cur->_parent;
				}
				else
				{
					//单旋
					//  g
					//     p
					//        c

					//双旋
					// g
					//    p
					// c
					if (cur==parent->_right)
					{
						RotateL(grandfather);
						grandfather->_colour = RED;
						parent->_colour = BLACK;
					}
					else
					{
						RotateR(parent);
						RotateL(grandfather);
						grandfather->_colour = RED;
						cur->_colour = BLACK;
					}

					break;

				}
			}

		}

		_root->_colour = BLACK;
		return true;
	}

	void RotateL(Node* parent)
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

	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR) subLR->_parent = parent;

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
	}

	void InOrder()
	{
		_InOrder(_root);

		return;
	}

	bool IsBlance()
	{
		if (_root == nullptr)
			return  true;

		if (_root->_colour == RED)
			return false;

		//参考值
		int refVal = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_colour == BLACK)
			{
				++refVal;
			}

			cur = cur->_left;
		}

		int blacknum = 0;

		return check(_root, blacknum, refVal);

	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << "->"<<root->_colour << endl;
		_InOrder(root->_right);
	}

	bool check(Node* root, int blacknum, int refVal)
	{
		if (root == nullptr)
		{
			if (blacknum == refVal)
			{
				return true;
			}
			else
			{
				cout << "黑色节点个数不同" << endl;
				return false;
			}
		}

		if (root->_colour == RED && root->_parent->_colour == RED)
		{
			cout << "红色节点相连" << endl;
			return false;
		}

		if (root->_colour == BLACK)
		{
			++blacknum;
		}

		return check(root->_left, blacknum, refVal)
			&& check(root->_right, blacknum, refVal);
	}

private:
	Node* _root = nullptr;
};
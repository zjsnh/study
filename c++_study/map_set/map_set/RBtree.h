#pragma once

#include<assert.h>

// key_value;
enum colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _parent;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _left;

	T _data;
	colour _colour;

	RBTreeNode(const T& data)
		:_parent(nullptr)
		, _right(nullptr)
		, _left(nullptr)
		, _data(data)
		, _colour(RED)
	{}

};

//数据类型
//key_value   key
// set->RBTree<K, K, SetKeyOfT> _t;
// map->RBTree<K, pair<K, T>, MapKeyOfT> _t;
template<class T>
struct __Treeiterator
{
	//typedef __Treeiterator<T> iterator;

	typedef RBTreeNode<T> Node;
	typedef __Treeiterator<T> seft;

	Node* _node;


	__Treeiterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &(_node->_data);
	}

	//seft& operator--();

	seft& operator++()
	{
		if (_node->_right)
		{
			//右子树的最左节点
			Node* cur = _node->_right;
			while (cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			Node* cur = _node;
			Node* parent = _node->_parent;

			//右树找到组先是先出右子树，此时该组先左指向其父亲
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	bool operator!=(const seft& s)
	{
		return _node != s._node;
	}

	bool operator==(const seft& s)
	{
		return _node == s._node;
	}


};

template<class K,class V,class KetOfT>
class RBTree
{
	typedef RBTreeNode<V> Node; //pair<K,V> 

public:
	typedef __Treeiterator<V> iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}


	pair<iterator,bool> insert(const V& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_colour = BLACK;
			return  make_pair(iterator(_root), true);
		}

		Node* parent = nullptr;
		Node* cur = _root;
		Node* newNode = cur;

		KetOfT key;

		while (cur)
		{
			if (key(cur->_data) < key(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key(cur->_data) > key(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return make_pair(iterator(cur), false);
			}
		}

		cur = new Node(data);
		cur->_colour = RED;
		if (key(parent->_data) > key(data))
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
					if (cur == parent->_left)
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
					if (cur == parent->_right)
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
		return make_pair(iterator(newNode), true);
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

	int Height()
	{
		return _Height(_root);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = _Height(root->_left);
		int rightHeight = _Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	size_t Size()
	{
		return _Size(_root);
	}

	size_t _Size(Node* root)
	{
		if (root == NULL)
			return 0;

		return _Size(root->_left)
			+ _Size(root->_right) + 1;
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		KetOfT ket;
		while (cur)
		{
			if (ket(cur->_data)< key)
			{
				cur = cur->_right;
			}
			else if (ket(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return NULL;
	}

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << "->" << root->_colour << endl;
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
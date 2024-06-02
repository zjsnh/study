#pragma once

#include<assert.h>


// key_value;
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
		, _right(nullptr)
		, _left(nullptr)
		, _kv(kv)
		, _bf(0)
	{}

};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
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
			}
			else if (parent->_bf == -2 || parent->_bf == 2)
			{
				// 旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}

				break;
			}
			else
			{
				assert(false);
			}
		}

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

		subR->_bf = parent->_bf = 0;
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

		subL->_bf = parent->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(subR);
		RotateL(parent);

		if (bf == 0)
		{
			parent->_bf = subR->_bf = subRL->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subRL->_bf = 0;
			subR->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = subL->_bf = subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subLR->_bf = 0;
			subL->_bf = 1;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}


	int _Hight(Node* root)
	{
		if (root == nullptr)
			return 0;

		int right_Hight = _Hight(root->_right);
		int left_Hight = _Hight(root->_left);

		return (right_Hight > left_Hight ? right_Hight : left_Hight) + 1;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	bool balance(Node* root)
	{
		if (root->_bf<2 && root->_bf>-2)
		{
			return true;
		}

		return false;
	}

	bool _IsBalance(Node* root)
	{
		/*if (root == nullptr)
		{
			return true;
		}
		if (!balance(root))           
		{
			cout << "平衡因子异常";
			return false;
		}
		return _IsBalance(root->_left) && _IsBalance(root->_right);*/

		bool _IsBalance(Node * root)
		{
			if (root == nullptr)
			{
				return true;
			}

			// 检查当前节点的平衡因子是否在范围内（-1, 0, 1）
			int bf = balance(root); // 假设 balance 函数返回节点的平衡因子
			if (bf < -1 || bf > 1)
			{
				cout << "平衡因子异常，节点值：" << root->_kv.first << "，平衡因子：" << bf << endl;
				return false;
			}

			// 递归检查左右子树
			return _IsBalance(root->_left) && _IsBalance(root->_right);
		}



	}

	/*if (root == nullptr)
		return true;

	int leftHeight = _Height(root->_left);
	int rightHeight = _Height(root->_right);
	if (rightHeight - leftHeight != root->_bf)
	{
		cout << root->_kv.first << "平衡因子异常" << endl;
		return false;
	}

	return abs(rightHeight - leftHeight) < 2
		&& _IsBalance(root->_left)
		&& _IsBalance(root->_right);*/

private:
	Node* _root = nullptr;
};

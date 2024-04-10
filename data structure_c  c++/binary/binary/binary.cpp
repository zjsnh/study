#include"binary.h"

BTNode::BTNode()
{
	head = nullptr;
}

BTNode::~BTNode()
{
	destroy(head);
}


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BinaryTree* BTNode::BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return nullptr;
	}

	BinaryTree* node = (BinaryTree*)malloc(sizeof(BinaryTree));
	if (node == nullptr)
	{
		perror("malloc");
		exit(-1);

	}

	node->_data = a[(*pi)++];

	node->_left=BinaryTreeCreate(a, 0, pi);
	node->_right=BinaryTreeCreate(a, 0, pi);

	return node;

}

// 二叉树节点个数
int BTNode::BinaryTreeSize(BinaryTree* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BTNode::BinaryTreeLeafSize(BinaryTree* root)
{

	if (root == nullptr)
	{
		return 0;
	}

	if (root->_left == nullptr && root->_right==nullptr)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right) + 0;
}

// 二叉树第k层节点个数
int BTNode::BinaryTreeLevelKSize(BinaryTree* root, int k)
{
	if (root == nullptr)//重点
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->_left, k - 1) +
		BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BinaryTree* BTNode::BinaryTreeFind(BinaryTree* root, BTDataType x)//重点
{

	if (root == nullptr)
	{
		return nullptr;
	}
	
	if (root->_data == x)
	{
		return root;
	}

	BinaryTree* Lnode = BinaryTreeFind(root->_left, x);
	if (Lnode != nullptr)
	{
		return Lnode;
	}


	return BinaryTreeFind(root->_right, x);

}

// 二叉树前序遍历 
void BTNode::BinaryTreePrevOrder(BinaryTree* root)
{
	if (root == nullptr)
	{
		return;
	}

	cout << root->_data;
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);

}

// 二叉树中序遍历
void BTNode::BinaryTreeInOrder(BinaryTree* root)
{
	if (root == nullptr)
	{
		return;
	}

	BinaryTreePrevOrder(root->_left);
	cout << root->_data;
	BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BTNode::BinaryTreePostOrder(BinaryTree* root)
{
	if (root == nullptr)
	{
		return;
	}

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	cout << root->_data;
}

// 层序遍历
void BTNode::BinaryTreeLevelOrder(BinaryTree* root)
{

	assert(root);

	queue<BinaryTree*> BT;
	BT.push(root);
	while (!BT.empty())
	{
		BinaryTree* temp = BT.front();
		BT.pop();

		cout << temp->_data<<" ";

		if (temp->_left != nullptr)
		{
			BT.push(temp->_left);
		}

		if (temp->_right != nullptr)
		{
			BT.push(temp->_right);
		}

	}
}

// 判断二叉树是否是完全二叉树
bool BTNode::BinaryTreeComplete(BinaryTree* root)
{
	assert(root);

	queue<BinaryTree*> BT;
	BT.push(root);
	while (!BT.empty())
	{
		BinaryTree* temp = BT.front();
		BT.pop();

		if (temp)
		{
			BT.push(temp->_left);
			BT.push(temp->_right);
		}
		else
		{
			break;
		}
	}

	while (!BT.empty())
	{
		BinaryTree* temp = BT.front();
		BT.pop();
		if (temp != nullptr)
		{
			return false;
		}
	}

	return true;
}


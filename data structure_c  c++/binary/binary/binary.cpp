#include"binary.h"

BTNode::BTNode()
{
	head = nullptr;
}

BTNode::~BTNode()
{
	destroy(head);
}


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

// �������ڵ����
int BTNode::BinaryTreeSize(BinaryTree* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
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

// ��������k��ڵ����
int BTNode::BinaryTreeLevelKSize(BinaryTree* root, int k)
{
	if (root == nullptr)//�ص�
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

// ����������ֵΪx�Ľڵ�
BinaryTree* BTNode::BinaryTreeFind(BinaryTree* root, BTDataType x)//�ص�
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

// ������ǰ����� 
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

// �������������
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

// �������������
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

// �������
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

// �ж϶������Ƿ�����ȫ������
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


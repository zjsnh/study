#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<iostream>
#include<queue>
using namespace std;

typedef char BTDataType;

class BinaryTree
{
	friend class BTNode;

private:
	BTDataType _data;
	BinaryTree* _left;
	BinaryTree* _right;
};

class BTNode
{
	BTNode();
	~BTNode();

	// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
	BinaryTree* BinaryTreeCreate(BTDataType* a, int n, int* pi);
	
	// 二叉树节点个数
	int BinaryTreeSize(BinaryTree* root);
	// 二叉树叶子节点个数
	int BinaryTreeLeafSize(BinaryTree* root);
	// 二叉树第k层节点个数
	int BinaryTreeLevelKSize(BinaryTree* root, int k);
	// 二叉树查找值为x的节点
	BinaryTree* BinaryTreeFind(BinaryTree* root, BTDataType x);
	// 二叉树前序遍历 
	void BinaryTreePrevOrder(BinaryTree* root);
	// 二叉树中序遍历
	void BinaryTreeInOrder(BinaryTree* root);
	// 二叉树后序遍历
	void BinaryTreePostOrder(BinaryTree* root);
	// 层序遍历
	void BinaryTreeLevelOrder(BinaryTree* root);
	// 判断二叉树是否是完全二叉树
	bool BinaryTreeComplete(BinaryTree* root);

private:

	void destroy(BinaryTree* head)
	{
		while (head)
		{
			destroy(head->_left);
			destroy(head->_right);

			free(head);
			head = nullptr;

		}
	}
	
	BinaryTree* head;
};






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

	// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
	BinaryTree* BinaryTreeCreate(BTDataType* a, int n, int* pi);
	
	// �������ڵ����
	int BinaryTreeSize(BinaryTree* root);
	// ������Ҷ�ӽڵ����
	int BinaryTreeLeafSize(BinaryTree* root);
	// ��������k��ڵ����
	int BinaryTreeLevelKSize(BinaryTree* root, int k);
	// ����������ֵΪx�Ľڵ�
	BinaryTree* BinaryTreeFind(BinaryTree* root, BTDataType x);
	// ������ǰ����� 
	void BinaryTreePrevOrder(BinaryTree* root);
	// �������������
	void BinaryTreeInOrder(BinaryTree* root);
	// �������������
	void BinaryTreePostOrder(BinaryTree* root);
	// �������
	void BinaryTreeLevelOrder(BinaryTree* root);
	// �ж϶������Ƿ�����ȫ������
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






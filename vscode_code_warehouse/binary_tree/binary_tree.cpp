#include"binary_tree.h"
#include<assert.h>


typedef struct Qunode
{
    struct  Qunode* next;
    BinAryNode* data;
}Qunode;

typedef struct Queue
{
    Qunode* front;
    Qunode* rear;
    int size;
}Queue;

void InitQueue(Queue* Qu)
{
    assert(Qu);
    Qu->front = NULL;  
    Qu->rear = NULL;   
}

void DestroyQueue(Queue* Qu)
{
    assert(Qu);
    Qunode* p = NULL;
    while (Qu->front != NULL)
    {
        p = Qu->front;
        Qu->front = Qu->front->next;
        delete p;
    }

    Qu->rear = NULL;
    Qu->size = 0;
}

void QueuePush(Queue* Qu, BinAryNode* data)
{
    assert(Qu);
    Qunode* newnode = new Qunode;
    if (newnode == NULL)
    {
        perror("QueuePush");
        exit(0);
    }
    newnode->data=data;
    newnode->next=NULL;

if (Qu->rear == NULL)
{
	assert(Qu->front==NULL);
	Qu->rear = Qu->front = newnode;
}
else
{
	Qu->rear->next = newnode;
	Qu->rear = newnode;
	
}
Qu->size++;

}




//初始化·二叉树
void BinAryInit(BinAryNode** root)
{
    assert(root);
    *root = NULL;
}

//销毁二叉树
void BinAryDestroy(BinAryNode* root)
{
    assert(root);
}

//二叉树连接
void BinAryConnect(BinAryNode** root, BinAryNode* newnode)
{
    assert(root);
    assert(newnode);

    if (*root == NULL)
    {
        *root = newnode;
        return;
    }

    if (newnode->data > (*root)->data)
    {
        if ((*root)->rchild == NULL)
        {
            (*root)->rchild = newnode;
        }
        else {
            BinAryConnect(&((*root)->rchild), newnode);
        }
    }
    else {
        if ((*root)->lchild == NULL)
        {
            (*root)->lchild = newnode;
        }
        else {
            BinAryConnect(&((*root)->lchild), newnode);
        }
    }
}

//节点创建
void BinAryNodeCreate(BinAryNode** root, ElemType data)
{
    BinAryNode* newnode = new BinAryNode;
    if (newnode == NULL)
    {
        perror("nodeCreate");
        exit(0);
    }

    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;


    BinAryConnect(root, newnode);


}

//二叉树遍历
void BinAryTraverse(BinAryNode* root)
{
    if (root)
    {
        printf("%d ", (root)->data);
        BinAryTraverse((root)->lchild);
        BinAryTraverse((root)->rchild);
    }
}

//二叉树深度
int BinAryDepth(BinAryNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ldepth = BinAryDepth(root->lchild);
    int rdepth = BinAryDepth(root->rchild);
    return ldepth > rdepth ? ldepth + 1 : rdepth + 1;
    //return 1 + (ldepth > rdepth ? ldepth : rdepth);
}

//节点个数
int BinArySize(BinAryNode *root)
{
   
    return root==NULL?1:0+

    1 + BinArySize(root->lchild) + BinArySize(root->rchild);

}

int BinaryLevel(BinAryNode* root, int k) {
    if (root == NULL || k < 1) {
        return 0;
    }
    
    if (k == 1) {
        return 1;
    }

    return BinaryLevel(root->lchild, k-1) + BinaryLevel(root->rchild, k-1);
}

BinAryNode* BinAryFind(BinAryNode*root,int x)
{
    if(root==NULL)
    return NULL;

    if(root->data==x)
    return root;

    if(root->data>x)
    {
        return BinAryFind(root->lchild,x);
    }
    else{
        return BinAryFind(root->rchild,x);
    }

    
}
#include<iostream>
#include<assert.h>
using namespace std;

typedef int ElemType;

typedef struct BinAry
{
    ElemType data;
    struct BinAry *lchild;
    struct BinAry *rchild;

}BinAryNode;

//初始化·二叉树
void BinAryInit(BinAryNode **root);

//节点创建
void BinAryNodeCreate(BinAryNode **root, ElemType data);

//二叉树连接
void BinAryConnect(BinAryNode **root, BinAryNode* newnode);

//二叉树遍历
void BinAryTraverse(BinAryNode *root);

//二叉树深度
int BinAryDepth(BinAryNode *root);

//销毁二叉树
void BinAryDestroy(BinAryNode *root);

//节点个数
int BinArySize(BinAryNode *root);


BinAryNode* BinAryFind(BinAryNode *root, ElemType data);

//二叉树层序遍历
void BinAryLevelTraverse(BinAryNode *root);









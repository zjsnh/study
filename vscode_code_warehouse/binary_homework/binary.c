#include"binary.h"

typedef struct Queue
{
    BTNode* _data;
    struct Queue* _next;
}Qu;

typedef struct QuNode
{
    Qu* _front;
    Qu* _rear;
    int _size;
}QuNode;


void InitQuNode(QuNode* q)
{
    q->_front=NULL;
    q->_rear=NULL;
    q->_size=0;
}

bool EmptyQuNode(QuNode* q)
{
    return q->_size==0;
}

void QuNodePush(QuNode* q, BTNode* data)
{
    assert(q);
    Qu* newnode=(Qu*)malloc(sizeof(Qu));
    if(newnode==NULL)
    {
        perror("malloc error");
        exit(0);
    }
    newnode->_data=data;
    newnode->_next=NULL;


    if(q->_front==NULL)
    {
        q->_front=q->_rear=newnode;
    }
    else{
        q->_rear->_next=newnode;
        q->_rear=newnode;

    }

    q->_size++;

}

BTNode* QuNodePop(QuNode* q)
{
    assert(EmptyQuNode(q));
    assert(q);
    Qu* temp=q->_front;
    BTNode* data=temp->_data;
    q->_front=temp->_next;
    q->_size--;
    free(temp);
    return data;

}



// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
   
    // if(root==NULL)
    // {
    //     perror("root malloc error");
    //     exit(0);
    // }
    if(a[*pi]=='#')
    {
        (*pi)++;
        return NULL;
    } 
    BTNode* root=(BTDataType*)malloc(sizeof(BTDataType));

    root->_data=a[(*pi)++];

    root->_left=BinaryTreeCreate(a,n,pi);
    root->_right=BinaryTreeCreate(a,n,pi);

    return root;

}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
    if((*root)==NULL)
            return;
    
    BinaryTreeDestory((*root)->_left);
    BinaryTreeDestory((*root)->_right);
    free(*root);
    *root=NULL;
    return ;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return BinaryTreeSize(root->_left)+BinaryTreeSize(root->_right)+1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->_left==NULL&&root->_right==NULL)
    {
        return 1;
    }
    return BinaryTreeLeafSize(root->_left)+BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if(root==NULL)
    {
        return 0;
    }
    if(k==1)
    {
        return 1;
    }
    return BinaryTreeLevelKSize(root->_left,k-1)+BinaryTreeLevelKSize(root->_right,k-1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    assert(root);

    if(root->_data==x)
    {
        return root;
    }

    BinaryTreeFind(root->_left,x);
    BinaryTreeFind(root->_right,x);

}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
    if(root)
    {
        printf("%c",root->_data);
        BinaryTreePrevOrder(root->_left);
        BinaryTreePrevOrder(root->_right);
    }
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
    if(root)
    {
        BinaryTreePrevOrder(root->_left);
        printf("%c",root->_data);
        BinaryTreePrevOrder(root->_right);
    }
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if(root)
    {
        BinaryTreePrevOrder(root->_left);
        BinaryTreePrevOrder(root->_right);
        printf("%c",root->_data);
    }
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
    assert(root);

    QuNode q;
    InitQuNode(&q);
    QuNodePush(&q,root);

    while(!EmptyQuNode(&q))
    {
        BTNode* temp=QuNodePop(&q);
        printf("%c",temp->_data);

        if(temp->_left)
        {
            QuNodePush(&q,temp->_left);
        }

        if(temp->_right)
        {
            QuNodePush(&q,temp->_right);
        }
    }
    DestroyQuNode(&q);

    return ;
}
// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
    assert(root);

    QuNode q;
    InitQuNode(&q);
    QuNodePush(&q,root);

    while(!EmptyQuNode(&q))
    {
        BTNode* temp=QuNodePop(&q);
        if(root==NULL);

        if(temp->_left)
        {
            QuNodePush(&q,temp->_left);
        }

        if(temp->_right)
        {
            QuNodePush(&q,temp->_right);
        }
    }
    
    while(!EmptyQuNode(&q))
    {
        BTNode* temp=QuNodePop(&q);
        if(root!=NULL)
        {
            DestroyQuNode(&q);
        return false;
        }
    }

    DestroyQuNode(&q);

    return true ;

}
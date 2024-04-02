#include"binary.h"


int main()
{
    
    BTDataType Ba[]={"A","B","D","#","#","E","#","H","#","#","C","F","#","#","G","#","#"};
    int p1=0;

    BTNode* BT=BinaryTreeCreate(Ba,10,&p1);

    BinaryTreePrevOrder(BT);

    return 0;

    
}
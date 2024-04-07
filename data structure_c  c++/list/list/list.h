#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

typedef int DateType;


// 定义链表节点结构体
struct ListNode {
    DateType _data;
    ListNode* _next;
};

class List {
public:

    List();
    ~List();
    void Pushback(DateType data);
    void Pushfront(DateType data);
    ListNode* Seek(int target);
    void Insert(ListNode* node, DateType data);
    void Remove(ListNode* node);

private:

    ListNode* create(DateType data);
    ListNode* _head;
    ListNode* _tail;
};

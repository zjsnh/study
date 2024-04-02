#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

typedef int DateType;


// 定义链表节点结构体
struct ListNode {
    DateType _date;
    ListNode* _next;
};

class List {
public:

    List();
    ~List();
    void Pushback(DateType date);
    void Pushfront(DateType date);
    void Seek();
    void Insert(ListNode* node, DateType date);
    void Remove(ListNode* node);

private:

    ListNode* create(DateType date);
    ListNode* _head;
    ListNode* _tail;
};

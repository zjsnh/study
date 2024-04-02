#include<iostream>
#include<assert.h>
#include<stdlib.h>
using namespace std;

typedef int DateType;


// ��������ڵ�ṹ��
struct ListNode {
    DateType _date;
    ListNode* _next;
};

class List {
public:

    List();
    ~List();
    void ListPushback(DateType date);
    void ListPushfront(DateType date);
    void Seek();
    void ListInsert(ListNode* node, DateType date);
    void ListRemove(ListNode* node);

private:

    ListNode* create(DateType date);
    ListNode* _head;
    ListNode* _tail;
};

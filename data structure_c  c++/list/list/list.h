#include<iostream>
using namespace std;

typedef int DataType;


typedef class List
{
public:
	List();
	~List();
	void ListPush(DataType data);

private:
	DataType _data;
	ListNode* Next;
}ListNode;
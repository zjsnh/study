#include<iostream>
using namespace std;

struct link_node
{
	link_node* next;
	link_node* prev;
};

struct task_struct1
{
	int image;
	link_node Node;
};

struct task_struct2
{
	link_node Node;
	int a;
	int b;
};

int main()
{
	task_struct1 ts1;
	ts1.image = 5;
	task_struct2 ts2;
	ts2.a = 1;
	ts2.b = 3;

	ts1.Node.next = &(ts2.Node);
	ts1.Node.prev = &(ts2.Node);

	ts2.Node.next = &(ts1.Node);
	ts2.Node.prev = &(ts1.Node);

	cout << ((task_struct2*)(((char*)ts1.Node.next - (char*)(&(((task_struct2*)(0))->Node)))))->a;

	// 使用指针运算来计算 task_struct2 指针
	//task_struct2* ts2_ptr = (task_struct2*)((char*)ts1.Node.next - (char*)(&(((task_struct2*)0)->Node)));
	cout << ts2_ptr->a;

	return 0;
}

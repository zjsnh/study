#include"list.h"

List::List()
{
	_tail = _head = nullptr;
}

List::~List()
{
	ListNode* cur = _head;

	while (cur != nullptr)
	{
		ListNode* temp = cur->_next;
		free(cur);
		cur = temp;
	}
	_head = nullptr;
	_tail = nullptr;

}

ListNode* List::create(DateType data)
{
	ListNode* temp = (ListNode*)malloc(sizeof(List));
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}
	temp->_data = data;
	temp->_next = nullptr;

	return temp;

}

void List::Pushback(DateType data)
{
	if (_head == nullptr)
	{
		_head = create(data);
		_tail = _head;
		return;
	}

	ListNode* cur = create(data);

	_tail->_next = cur;
	_tail = cur;
}

void List::Pushfront(DateType data)
{

	ListNode* temp = create(data);
	if (_head == nullptr)
	{
		_head = temp;
		_tail = _head;
		return;
	}
	
	temp = _head->_next;
	_head = temp;

	if (_head = _tail)
	{
		_tail = temp->_next;
	}
}


//ListNode* List::Seek()
//{
//	/*ListNode* cur = _head;
//	while (cur != nullptr)
//	{
//		cout << cur->_data << " ";
//		cur = cur->_next;
//	}
//	cout << endl;*/
//
//}

ListNode* List::Seek(int target) {
	ListNode* current = _head;  // 从链表头节点开始遍历
	while (current != nullptr) {
		if (current->_data == target) {
			return current;  // 找到节点，返回节点指针
		}
		current = current->_next;  // 移动到下一个节点
	}
	return nullptr;  // 没有找到节点，返回空指针
}


void List::Insert(ListNode* node, DateType data)
{
	ListNode* cur = _head;
	while (cur != node)
	{
		cur = cur->_next;
	}

	ListNode* temp = create(data);

	temp->_next = cur->_next;
	cur->_next = temp;

}


void List::Remove(ListNode* node)
{
	ListNode* cur = _head;
	ListNode* tail = cur;
	while (cur != node)
	{
		tail = cur;
		cur = cur->_next;
	}
	tail->_next = cur->_next;
	free(cur);

	cur = nullptr;

}
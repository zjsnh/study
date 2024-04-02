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

ListNode* List::create(DateType date)
{
	ListNode* temp = (ListNode*)malloc(sizeof(List));
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}
	temp->_date = date;
	temp->_next = nullptr;

	return temp;

}

void List::Pushback(DateType date)
{
	if (_head == nullptr)
	{
		_head = create(date);
		_tail = _head;
		return;
	}

	ListNode* cur = create(date);

	_tail->_next = cur;
	_tail = cur;
}

void List::Pushfront(DateType date)
{

	ListNode* temp = create(date);
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


void List::Seek()
{
	ListNode* cur = _head;
	while (cur != nullptr)
	{
		cout << cur->_date << " ";
		cur = cur->_next;
	}
	cout << endl;

}
void List::Insert(ListNode* node, DateType date)
{
	ListNode* cur = _head;
	while (cur != node)
	{
		cur = cur->_next;
	}

	ListNode* temp = create(date);

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
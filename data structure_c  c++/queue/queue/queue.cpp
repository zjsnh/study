#include"queue.h"

Queue::Queue()
{
	front = nullptr;
	tail = nullptr;
}

Queue::~Queue()
{
	queueNode* node = front;
	while (node != nullptr)
	{
		queueNode* temp = node->next;
		free(node);
		node = temp;
	}

	front = tail = nullptr;
}

bool Queue::empty()
{
	return front == nullptr;
}
int Queue::size()
{
	int size = 0;

	queueNode* node = front;
	while (node != nullptr)
	{
		size++;
		node = node->next;
	}
	return size;
}


Datetype Queue::Front()
{
	assert(!empty());
	return front->_data;
}


Datetype Queue::Back()
{
	assert(!empty());
	return tail->_data;
}

queueNode* create(Datetype x)
{

	queueNode* newNode = new queueNode;
	newNode->_data = x;
	newNode->next = nullptr;
	return newNode;

}


void Queue::push_back(Datetype x)
{
	queueNode* temp = create(x);
	if (front == nullptr)
	{
		front = temp;
		tail = front;

		return;
	}

	tail->next = temp;
	tail = temp;

}
void Queue::pop_front()
{
	assert(!empty()); 

	queueNode* temp = front; 

	if (front == tail)
	{
		front = tail = nullptr; 
	}
	else // 如果队列中有多个节点
	{
		front = front->next; 
	}

	free(temp);
	temp = nullptr;

}

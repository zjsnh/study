#include"Sqlist.h"

Sqlist::Sqlist(int capacity = 4)
{
	_capacity = capacity;
	Datatype* temp = (Datatype*)malloc(sizeof(Datatype) * _capacity);
	if (temp == nullptr)
	{
		perror("malloc");
		exit(-1);
	}
	_data = temp;

	_size = 0;
}

Sqlist::~Sqlist()
{
	free(_data);
	_data = nullptr;
	_capacity = _size = 0;

}

void Sqlist::Newcapacity() {
	_capacity *= 2;
	Datatype* newData = (Datatype*)realloc(_data, sizeof(Datatype) * _capacity);
	if (newData == nullptr) {
		perror("realloc");
		exit(-1);
	}

	else {
		_data = newData;
	}
}


void Sqlist::Insert(Datatype data)
{
	if (_size == _capacity)//�жϵ�ǰ���Ա��Ƿ�����
	{
		Newcapacity();//�������Ա��С
	}

	_data[_size++] = data;

}

int Sqlist::seek(Datatype data)
{
	for (int i = 0; i < _size; i++)
	{
		if (_data[i] == data)
		{
			return i;
		}
	}

	cout << "false";
	return -1;
}

void Sqlist::Erase(int index) {
	assert(index >= 0 && index < _size); 

	// ��ָ��λ�ú����Ԫ����ǰ�ƶ�һ��λ�ø��Ǳ�ɾ����Ԫ��
	for (int i = index; i < _size - 1; ++i) {
		_data[i] = _data[i + 1];
	}

	--_size; 
}

void Sqlist::Alter(int index, Datatype newData) {
	assert(index >= 0 && index < _size); // ȷ�������Ϸ�

	_data[index] = newData; // ��ָ��λ�õ�Ԫ���滻Ϊ�µ�����
}




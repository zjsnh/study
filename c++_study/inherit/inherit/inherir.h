#pragma once

class Person
{
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "peter"; 
	int _age = 18;
};
// �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���

class Student : public Person
{
protected:
	int _stuid; // ѧ��
};
class Teacher : public Person
{
protected:
	int _jobid; // ����
};



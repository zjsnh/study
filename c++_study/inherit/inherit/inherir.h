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
// 继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了

class Student : public Person
{
protected:
	int _stuid; // 学号
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号
};



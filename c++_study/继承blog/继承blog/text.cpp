#include<iostream>
using namespace std;
#include<string>

//�̳� ����
// �̳й�ϵ
//�̳��������Ի���ĸ�ֵ
//��������ڻ������Ĵ���������ʱ��
// ���� �����������ת��
//�̳� ��Ԫ static
//��̳�
//���μ̳�
//��̬





typedef void(*Fun)();

//��̬
class animal  //����
{
public:
	virtual void call()
	{
		cout << "animal: ���" << endl;
	}

	string _animal = "anminal";
};

class dog : public animal
{
public:

	void call() override
	{
		cout << "dog : ����" << endl;
	}

	string _dog = "dog";
};

void VFun(Fun* a)
{
	for (size_t i = 0; a[i] != 0; i++)
	{
		cout << i << ":" << a[i] << endl;
		Fun f = a[i];
		(*f)();
	}
	cout << endl;
}


int main()
{
	dog D;
	animal A;
	D._dog;


	//cout << &(D.call_dog()) << endl;
	//cout << (Fun)(*(int*)&D);
	cout << &D << endl;
	printf("%p: D.call:\n", &dog::call);
	printf("%p ���:\n", *((int*)&D));
	/*Fun a = (Fun)(*((int*)&D));
	a();*/
	Fun* a = (Fun*)(*((int*)&D));
	//(&a)();

	VFun((Fun*)(*((int*)&D)));
	return 0;
}
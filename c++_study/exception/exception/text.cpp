#include<iostream>
using namespace std;
//
//double Division(int a, int b)
//{
//	// ��b == 0ʱ�׳��쳣
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//
//void Func()
//{
//	// ������Կ������������0�����׳��쳣�����������arrayû�еõ��ͷš�
//	// �������ﲶ���쳣�󲢲������쳣���쳣���ǽ������洦�����ﲶ������
//	// �����׳�ȥ��
//	int* array1 = new int[10];
//	int* array2 = new int[20];
//
//	// �쳣��ȫ����
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array1 << endl;
//		delete[] array1;
//
//		cout << "delete []" << array2 << endl;
//		delete[] array2;
//
//		throw;  // ����ʲô��ʲô
//	}
//	/*catch (const char* errmsg)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//
//		throw errmsg;
//	}*/
//
//	cout << "delete []" << array1 << endl;
//	delete[] array1;
//
//	cout << "delete []" << array2 << endl;
//	delete[] array2;
//}


//smartPtr

template<class T>
class SmartPtr {
public:
    SmartPtr(T* ptr = nullptr)
        : _ptr(ptr)
    {}

    ~SmartPtr()
    {
        if (_ptr)
            delete _ptr;
    }

   
    //��ָ��һ��ʹ��
    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    //��ֹ�������Զ����� ������ֵ =��������غ���
    SmartPtr(const SmartPtr<T>& sp) = delete;
    SmartPtr<T>& operator=(const SmartPtr<T>& sp) = delete;
    
private:
    T* _ptr;
};


double Division(int a, int b) /*throw(const char*)*/
{
    // ��b == 0ʱ�׳��쳣
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (double)a / (double)b;
}

void func()
{
    SmartPtr<int> sp(new int);
    SmartPtr<double> sp2(new double);


    cout << (void*)(new int) << endl;   //new ����һ���ڴ��ָ��

    int len, time;
    cin >> len >> time;
    Division(len,time);


}


int main()
{
    try{
        func();
    }
    catch (const char* str)
    {
        cout << str << endl;
    }

    return 0;
}


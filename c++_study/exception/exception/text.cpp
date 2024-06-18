#include<iostream>
using namespace std;
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
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
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array1 = new int[10];
//	int* array2 = new int[20];
//
//	// 异常安全问题
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
//		throw;  // 捕到什么抛什么
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

   
    //像指针一样使用
    T& operator*()
    {
        return *_ptr;
    }

    T* operator->()
    {
        return _ptr;
    }

    //禁止编译器自动生成 拷贝赋值 =运算符重载函数
    SmartPtr(const SmartPtr<T>& sp) = delete;
    SmartPtr<T>& operator=(const SmartPtr<T>& sp) = delete;
    
private:
    T* _ptr;
};


double Division(int a, int b) /*throw(const char*)*/
{
    // 当b == 0时抛出异常
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


    cout << (void*)(new int) << endl;   //new 返回一块内存的指针

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


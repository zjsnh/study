#include<iostream>
using namespace std;
#include<string>

//继承 概念
// 继承关系
//继承子类对象对基类的赋值
//子类对象内基类对象的创建，销毁时间
// 基类 派生类的类型转换
//继承 友元 static
//多继承
//菱形继承
//多态

//class animal
//{
//public:
//	void _cry()
//	{
//		cout << "....." << endl;
//		cout << _animal << endl;
//	}
//protected:
//	string _type = "_animal";
//private:
//	string _animal = "animal";
//};
//
//class dog : private animal
//{
//public:
//	string __animal = _type;
//
//	void cry()
//	{
//		cout << "汪汪汪" << endl;
//		_cry();
//		cout << animal::_type << endl;
//		cout << __animal << endl;
//	}
//
//
//private:
//	string _dog = "_dog";
//};
//
//int main()
//{
//	dog D;
//	D.cry();
//	//D._cry();
//
//	return 0;
//}

#include <iostream>
#include <string>

using namespace std;
//
//class Animal {
//public:
//    void cry() {
//        cout << "Animal cry..." << endl;
//    }
//
//
//protected:
//    string _type = "Animal";
//
//private:
//    string _animal = "_animal";
//};
//
//class DogPublic : public Animal {
//public:
//    void showType() {
//        cout << "Type: " << _type << endl;  // 可以访问基类的 protected 成员
//        cry();  // 可以调用基类的 public 成员函数
//    }
//
//    // 提供公有方法来访问基类成员
//    void callCry() {
//        cry();  // 可以访问基类的 public 成员函数
//    }
//};
//
//class DogProtected : protected Animal {
//public:
//    void showType() {
//        cout << _type << endl;
//
//        cout << "Type: " << _type << endl;  // 可以访问基类的 protected 成员
//        cry();  // 可以调用基类的 public 成员函数
//    }
//
//    // 提供公有方法来访问基类成员
//    void callCry() {
//        cry();  // 可以访问基类的 public 成员函数
//    }
//};
//
//class DogPrivate : private Animal {
//public:
//    void showType() {
//        cout << _type << endl;
//
//        cout << "Type: " << _type << endl;  // 可以访问基类的 protected 成员
//        cry();  // 可以调用基类的 public 成员函数
//    }
//
//    // 提供公有方法来访问基类成员
//    void callCry() {
//        cry();  // 可以访问基类的 public 成员函数
//    }
//};
//
//int main() {
//    DogPublic d;
//    d.showType();
//    d.callCry();
//    d.cry();
//
//    DogProtected d1;
//    d1.showType();  
//    d1.callCry();   
//
//    DogPrivate d2;
//    d2.showType();  
//    d2.callCry(); 
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Base {
//public:
//    Base() {
//        cout << "Base default constructor" << endl;
//    }
//
//    Base(int value) : _value(value) {
//        cout << "Base parameterized constructor" << endl;
//    }
//
//    ~Base() {
//        cout << "Base destructor" << endl;
//    }
//
//    Base(const Base& other) : _value(other._value) {
//        cout << "Base copy constructor" << endl;
//    }
//
//    Base& operator=(const Base& other) {
//        if (this != &other) {
//            _value = other._value;
//            cout << "Base assignment operator" << endl;
//        }
//        return *this;
//    }
//
//private:
//    int _value = 0;
//};
//
//class Derived : public Base {
//public:
//    Derived() : Base() {
//        cout << "Derived default constructor" << endl;
//    }
//
//    Derived(int baseValue, int derivedValue) : Base(baseValue), _derivedValue(derivedValue) {
//        cout << "Derived parameterized constructor" << endl;
//    }
//
//    ~Derived() {
//        cout << "Derived destructor" << endl;
//    }
//
//    Derived(const Derived& other) : Base(other), _derivedValue(other._derivedValue) {
//        cout << "Derived copy constructor" << endl;
//    }
//
//    Derived& operator=(const Derived& other) {
//        if (this != &other) {
//            Base::operator=(other);
//            _derivedValue = other._derivedValue;
//            cout << "Derived assignment operator" << endl;
//        }
//        return *this;
//    }
//
//private:
//    int _derivedValue = 0;
//};
//
//int main() {
//    cout << "Creating d1" << endl;
//    Derived d1;
//
//    cout << "Creating d2 with parameters" << endl;
//    Derived d2(10, 20);
//
//    cout << "Creating d3 as a copy of d2" << endl;
//    Derived d3(d2);
//
//    cout << "Assigning d2 to d1" << endl;
//    d1 = d2;
//
//    return 0;
//}



//class A
//{
//public:
//	int _a;
//};
//
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
//class D : public B , public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 1;
//	d._c = 2;
//	d._d = 3;
//	return 0;
//}
//

//typedef void(*Fun)();
//
////多态
//class animal  //基类
//{
//public:
//	virtual void call() = 0;
//
//};
//
//class dog : public animal
//{
//public:
//	void call() override
//	{
//		cout << "dog : 汪汪！" << endl;
//	}
//
//};
//
//
//class cat : public animal
//{
//public:
//	void call() override
//	{
//		cout << "cat : 喵~" << endl;
//	}
//
//};
//
//void animal_call(animal& _animal)
//{
//	_animal.call();
//	return;
//}
//
//int main()
//{
//	dog D;
//	cat C;
//	animal_call(D);
//	animal_call(C);
//
//	return 0;
//}

//
//class animal  //基类
//{
//public:
//	void call()
//	{
//		cout << "你好" << endl;
//	}
//
//};
//
//class dog : public animal
//{
//public:
//	void call() 
//	{
//		cout << "dog : 汪汪！" << endl;
//	}
//
//};
//
//
//class cat : public animal
//{
//public:
//	void call() 
//	{
//		cout << "cat : 喵~" << endl;
//	}
//
//};
//
//int main()
//{
//	dog D;
//	cat C;
//	cout << &(dog::call) << endl;
//	cout << &(cat::call) << endl;
//
//	return 0;
//}



//void VFun(Fun* a)
//{
//	for (size_t i = 0; a[i] != 0; i++)
//	{
//		cout << i << ":" << a[i] << endl;
//		Fun f = a[i];
//		(*f)();
//	}
//	cout << endl;
//}
//
//
//int main()
//{
//	dog D;
//	animal A;
//	D._dog;
//
//
//	//cout << &(D.call_dog()) << endl;
//	//cout << (Fun)(*(int*)&D);
//
//	/*cout << &D << endl;
//	printf("%p: D.call:\n", &dog::call);
//	printf("%p 虚表:\n", *((int*)&D));*/
//	/*Fun a = (Fun)(*((int*)&D));
//	a();*/
//
//	Fun* a = (Fun*)(*((int*)&D));
//	//(&a)();
//
//	VFun((Fun*)(*((int*)&D)));
//	return 0;
//}
#include <iostream>

class Base {
public:
    virtual ~Base() {  // 基类析构函数是虚函数
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() override {  // 派生类析构函数
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base* obj = new Derived();  // 基类指针指向派生类对象
    delete obj;  // 调用 Derived 析构函数，然后调用 Base 析构函数
    return 0;
}



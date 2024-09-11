#pragma once
template<class V>
void fun(V const& a)
{
	cout << "2: fun() " << a << endl;
}

void f2()
{
	fun(1);
	fun(1.2);
}

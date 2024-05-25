#include"binarysearchtree.h"
#include<string>


//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	key::BStree<int> bs;
//	for (auto e : a)
//	{
//		bs.InsertR(e);
//	}
//
//	bs.InOrder();
//
//	bs.EraseR(8);
//	bs.InOrder();
//
//	for (auto e : a)
//	{
//		bs.EraseR(e);
//		bs.InOrder();
//	}
//
//	return 0;
//}


int main()
{
	key_value::BStree<string, string> kv;
	kv.Insert("insert", "插入");
	kv.Insert("right", "右边");
	kv.Insert("left", "左边");
	kv.Insert("hello", "你好");
	kv.Insert("destory", "销毁");

	string str;
	while (cin >> str)
	{
		key_value::BStreeNode<string, string>* ret = kv.Find(str);
		if (ret)
		{
			cout << ret->_value << endl;
		}
		else
		{
			cout << "未知字符" << endl;
		}
	}

	return 0;
}
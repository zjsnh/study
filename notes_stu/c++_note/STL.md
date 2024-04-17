# STL

## STL六大组键

![image-20240414164141334](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240414164141334.png)

类似于数据结构

## string

![image-20240414165216928](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240414165216928.png)

- [C++98](javascript:switch1.select(1)) 构造函数

|       default (1) | `string(); `                                                 |
| ----------------: | ------------------------------------------------------------ |
|          copy (2) | `string (const string& str); `                               |
|     substring (3) | `string (const string& str, size_t pos, size_t len = npos); ` |
| from c-string (4) | `string (const char* s); `                                   |
| from sequence (5) | `string (const char* s, size_t n); `                         |
|          fill (6) | `string (size_t n, char c); `                                |
|         range (7) | `template <class InputIterator>  string  (InputIterator first, InputIterator last);` |

```c++
s2.push_back(' ');
s2.push_back('!');//char  字符

s2.append("zws");//cosnt char  常量字符串

s2 += ' ';
s2 += "  ";
s2 += "hello";
s2 += "  !";
```

## capacity

对于不同的编译器，string对于capacity的扩容是不一样的

```c++
int main()
{
	string s;

	size_t sz = s.capacity();
	cout << "sz.capacity()=" << sz << endl;//没有扩容的大小

	for (size_t t = 0; t < 100; t++)
	{
		s.push_back('c');

		if (sz != s.capacity())
		{
			cout << "sz.capacity()=" << s.capacity()<< endl;

			sz = s.capacity();
		}
	}

}
```

### vs2022

```c++
sz.capacity()=15
sz.capacity()=31
sz.capacity()=47
sz.capacity()=70
sz.capacity()=105
```

vs先使用 _buf 并给其赋予16（斜杠零）字节的空间，如果后续需要的内存大于16，系统就会使用 *Ptr  并为其分配空间，而__buf内只是存储随机值

### g++

```c++
sz.capacity()=0
sz.capacity()=1
sz.capacity()=2
sz.capacity()=4
sz.capacity()=8
sz.capacity()=16
sz.capacity()=32
sz.capacity()=64
sz.capacity()=128
```

## reserve

对于已知大小的字符串存储，可以使用reserve，把空间一次性给够，减少扩容，提高效率

```c++
int main()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "sz.capacity()=" << sz << endl;//没有扩容的大小
	for (size_t t = 0; t < 100; t++)
	{
		s.push_back('c');

		if (sz != s.capacity())
		{
			cout << "sz.capacity()=" << s.capacity()<< endl;
c++
			sz = s.capacity();
		}
	}
	return 0;

}
```

但是，vs可能为了内存对齐，分配的空间可能比100大，但是，gcc会直接分配100的空间

## resize

分配内存，并初始化，（）缺省值是0，

```c++
int main()
{
	string s1 = "hello word";

	s1.reserve(100);
	cout << s1.capacity()<<endl;
	cout << s1.size() << endl;

	string s2 = "hello word";

	s2.resize(100);
	cout << s2.capacity() << endl;
	cout << s2.size() << endl;

	return 0;

}
```

![image-20240414203247400](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240414203247400.png)

但是不会缩小capacity

![image-20240414203400093](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240414203400093.png)

缩容，但是会降低效率

## 迭代器

```c++
string s1("!:@#$ $%%^");
string::iterator it = s1.begin();//begin 第一个位置的指针
while (it != s1.end())//end 最后一个位置的下一个位置
{
	cout << *it << " ";
	++it;
}

cout << endl;

for (auto ch : s1)
{
	cout << ch << " ";
}

cout << endl;
```

可以先理解为指针，，范围for  本质来说就是迭代器

![image-20240414205340662](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240414205340662.png)

反向迭代器

```c++
reverse_iterator 
```

![image-20240417134655412](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417134655412.png)

const_iterator

不能修改，只能读，遍历

![image-20240417135320376](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417135320376.png)

## []  at

```c++
a[100];
a.at(100);
```

对于越界的数据，在string类中，重载后会直接中止，at会抛异常，可以被捕获

## assign

赋值

## insert

插入

std::[string](https://legacy.cplusplus.com/reference/string/string/)::insert

|           string (1) | ` string& insert (size_t pos, const string& str); `          |
| -------------------: | ------------------------------------------------------------ |
|        substring (2) | ` string& insert (size_t pos, const string& str, size_t subpos, size_t sublen); ` |
|         c-string (3) | ` string& insert (size_t pos, const char* s); `              |
|           buffer (4) | ` string& insert (size_t pos, const char* s, size_t n); `    |
|             fill (5) | ` string& insert (size_t pos, size_t n, char c);    void insert (iterator p, size_t n, char c); ` |
| single character (6) | `iterator insert (iterator p, char c); `                     |
|            range (7) | `template <class InputIterator>   void insert (iterator p, InputIterator first, InputIterator last);` |

插入空格,但

![image-20240417141816701](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417141816701.png)

## erase

### std::[string](https://legacy.cplusplus.com/reference/string/string/)::erase

|  sequence (1) | ` string& erase (size_t pos = 0, size_t len = npos); ` |
| ------------: | ------------------------------------------------------ |
| character (2) | `iterator erase (iterator p); `                        |
|     range (3) | `     iterator erase (iterator first, iterator last);` |

len 长度

![image-20240417141336171](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417141336171.png)

## find/rfind

返回第一次匹配的位置

![image-20240417153721048](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417153721048.png)

![image-20240417153928433](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417153928433.png)

![image-20240417154100930](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417154100930.png)

## swap

![image-20240417154649562](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417154649562.png)

一个是类模板，一个是string单独实现的swap

单独实现的是改变指针的指向，类模板是深拷贝

## 打印

c_str()返回字符串的指针，但是打印是按字符串打印

c_str(）遇到  \0 截至 

![image-20240417155334441](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417155334441.png)

![image-20240417155405754](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417155405754.png)

c_str(),是为了与c语言的函数接口兼容比如 

fopen  

![ ](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417155643532.png)

## substr

取子串

### std::[string](https://legacy.cplusplus.com/reference/string/string/)::substr

```c++
string substr (size_t pos = 0, size_t len = npos) const;
```

![image-20240417160236622](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417160236622.png)

## find_first_of

![image-20240417161218434](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417161218434.png)

![image-20240417161201217](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417161201217.png)

## ==

![image-20240417161658870](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417161658870.png)

## getline

### std::getline (string)

|  (1) | `istream& getline (istream& is, string& str, char delim); ` |
| ---: | ----------------------------------------------------------- |
|  (2) | `istream& getline (istream& is, string& str);`              |

cin>> 在输入有空格的时候，就会分割，getline只会因为换行分割

![image-20240417162548280](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417162548280.png)







![image-20240417163710085](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417163710085.png)

![image-20240417163727720](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417163727720.png)

 

![image-20240417164011859](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417164011859.png)

转换为字符

![image-20240417164113747](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417164113747.png)

额外处理

![image-20240417164724180](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417164724180.png)

![image-20240417164737766](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417164737766.png)

1：空间先开辟

2：尾插后逆置

# 逆置

### std::reverse

[Bidirectional iterators](https://legacy.cplusplus.com/BidirectionalIterator) to the initial and final positions of the sequence to be reversed. The range used is , which contains all the elements between and , including the element pointed by but not the element pointed by .

```
template <class BidirectionalIterator>
  void reverse (BidirectionalIterator first, BidirectionalIterator last);
```

reverse（）迭代器区间，，左闭右开

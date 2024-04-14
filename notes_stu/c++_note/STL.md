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

可以线理解为指针，，范围for  本质来说就是迭代器


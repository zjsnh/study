## c++命名

```c++
::
```

作用域符号

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240328162757684.png" alt="image-20240328162757684" style="zoom:50%;" />

可以通过namespace（命名空间）来同时命名不同作用，但变量名相同的变量，解决了我们自己的命名冲突跟我们命名时跟c++库里的名字冲突，命名空间里也可以定义函数与结构体，在我们工作时可以更加独立，不与其他人的命名空间冲突指定命名空间就减少程序中因为命名的一部分冲突，命名空间可以嵌套

### 展开命名空间 

using namespace (命名空间的名字)

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240328164057571.png" alt="image-20240328164057571" style="zoom:50%;" />

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240328164233043.png" alt="image-20240328164233043" style="zoom:50%;" />

一般不要展开，可能会导致程序命名冲突和程序运行慢

std  是官方命名空间

## iostrem

c++新的输入输出流，兼容printf scanf 

cout(console 控制台)  输出到控制台  

<<  流插入 （随便写）

```c++
cout<<i<<""<<'\n'<<endl;
```

自动识别类型

![image-20240328165258551](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240328165258551.png)

![image-20240328170219580](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240328170219580.png)

控制数据各种特征的函数(输出的精度，宽度)比较麻烦，要是控制也可以使用printf

## 缺省参数

c++定义函数时，可以在函数类型后给一个预定值，若传参时没有给值，，函数就会调用

预定值

```c++
int add(int a=10,int b=10)
```

## 重载函数

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329125441644.png" alt="image-20240329125441644" style="zoom:50%;" />

函数重载是相同的函数名，但不同的参数，在c++中，编译器会对函数进行修饰，以达到相同函数名，但调用不同参数时，达到不同调用，在汇编层面，我们可以看到系统调用的修饰名

环境：vs2022

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329131105492.png" alt="image-20240329131105492" style="zoom:80%;" />

环境：g++

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329132153812.png" alt="image-20240329132153812" style="zoom:60%;" />

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329132222490.png" alt="image-20240329132222490" style="zoom:65%;" />

不同的编译器的修饰规则不一样

返回值不同不时重载

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329130306453.png" alt="image-20240329130306453" style="zoom:80%;" />

在c语言中

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329132723531.png" alt="image-20240329132723531" style="zoom:67%;" />

函数修饰只有名字，这就导致编译器无法通过其他方式找到调用的函数

重载函数，可以通过，参数个数，参数类型的不同来重载函数

## 引用

& 

给变量去别名，可以在函数返回时，不在拷贝一份占用空间



## c++新的遍历数组的方式

```c++
for(auto i:arry[])
{
    cout<<i;
}
```

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240329133540286.png" alt="image-20240329133540286" style="zoom:50%;" />

## auto

智能的变量

编译器会根据代码推断你写的是什么类型变量

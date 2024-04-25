# vector

## 初始化

![image-20240425153414141](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425153414141.png)

无参，空间和初始化 ，迭代器区间，一般是需要匹配变量类型，但是编译器可以隐式转换，但可能导致数据出现问题，其他vector对象

## 遍历

[]

迭代器

范围for

## 扩容

![image-20240425155150997](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425155150997.png)

vs1.5倍

g++ 2倍



resize

reserve

![image-20240425155835365](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425155835365.png)



![image-20240425154517855](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425154517855.png)

find 库函数模板

![image-20240425160810092](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425160810092.png)

![image-20240425160741109](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425160741109.png)

![image-20240425172650397](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425172650397.png)

问题所在 start先被改变了

![image-20240425172817234](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425172817234.png)

迭代器的位置注意好！！！！

![image-20240425172936193](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425172936193.png)

先记录size的位置
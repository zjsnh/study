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

迭代器

![image-20240425220741306](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240425220741306.png)

迭代器可能会失效，因为再insert中我们不知vector是否会扩容，所以，迭代器可能会改变位置

![image-20240426152306659](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426152306659.png)

memcpy导致的深层次的浅拷贝问题

![image-20240426154421236](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426154421236.png)

![image-20240426154544545](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426154544545.png)

![image-20240426160545247](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426160545247.png)

![image-20240426160801262](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426160801262.png)

编译器会调用最匹配的函数，

![image-20240426162557935](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426162557935.png)

![image-20240426162615567](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426162615567.png)

![image-20240426163837851](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426163837851.png)

每一次递归，遍历递归所有的字符，进行拼接，str获得当前数字下保存的字符串，然后遍历，如果我们递归的层数等于传入的数字串的个数的时候，就尾插vector返回即可，递归参数不好想 num是映射获得字符串

+不会改变自己，所以就可以进行下一次循环，再次用之前未完成遍历的字符串进行拼接

![image-20240426163548991](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240426163548991.png)

多路递归！
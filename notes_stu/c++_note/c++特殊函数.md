# 默认成员函数

## 构造函数

在c++中 自默认生成的构造函数对内置参数类型是不做处理的

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402185556770.png" alt="image-20240402185556770" style="zoom:50%;" />

我们需要自己显示的写出来

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402191444130.png" alt="image-20240402191444130" style="zoom:50%;" />



## 拷贝构造

对于系统默认生成的拷贝构造是“浅拷贝” 只是拷贝数据，对于指针，或者需要空间的数据，就造成了拷贝后指向同一块空间，调用析构函数时，可能会调用两次，或者是数据相互影响，因为他们指向同一块空间，对于这样的拷贝，我们需要手动写“深拷贝” 拷贝构造函数

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402191154146.png" alt="image-20240402191154146" style="zoom:75%;" />

让他们有各自独立的空间

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402191626775.png" alt="image-20240402191626775" style="zoom:67%;" />

设计资源管理

这里的自定义类型，系统会根据这个自定义类型定义的构造函数，拷贝构造去自动生成这个自定义类型的构造函数

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402192637966.png" alt="image-20240402192637966" style="zoom:50%;" />

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402192651886.png" alt="image-20240402192651886" style="zoom:50%;" />

自定义类型

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402193502520.png" alt="image-20240402193502520" style="zoom:50%;" />

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402193518092.png" alt="image-20240402193518092" style="zoom:50%;" />

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402193734902.png" alt="image-20240402193734902" style="zoom:50%;" />

## 运算符重载

==

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402195701459.png" alt="image-20240402195701459" style="zoom: 50%;" />

对于=这种需要可能连续赋值，保持运算符的特性

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402200951189.png" alt="image-20240402200951189" style="zoom:50%;" />

前置++ 与后置++

语法为了区别这两者运算符重载的区别，将后置++的重载函数加上一个 int  用于区别



<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240402201653531.png" alt="image-20240402201653531" style="zoom:50%;" />
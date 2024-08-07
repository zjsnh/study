# list

# 迭代器

![image-20240427165306889](picture/image-20240427165306889.png)

![image-20240427165314456](picture/image-20240427165314456.png)

算法里的sort只是支持随机访问的迭代器，对于list  双向访问的迭代器可能会报错

所以list中会有sort函数 默认升序

reverse逆置函数



排序 sort

![image-20240427170403343](picture/image-20240427170403343.png)

仿函数，

![image-20240427170427499](picture/image-20240427170427499.png)

默认是升序，而对于降序，可以使用 greater 

![image-20240427171348242](picture/image-20240427171348242.png)

如果直接使用list的排序时间太长，我们可以将数据拷贝到vector，使用算法的sort ，如果list的数据量小，就可以使用list的sort

# merge

对于归并函数，两个链表需要有序

# splice

![image-20240427172306450](picture/image-20240427172306450.png)

转移，将一个链表的一部分，转移到另外一个链表

![image-20240427173712875](picture/image-20240427173712875.png)

![image-20240427174714304](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240427174714304.png)

给匿名对象初始化防止编译器不通过

![image-20240427175312389](picture/image-20240427175312389.png)

![image-20240427175639161](picture/image-20240427175639161.png)



迭代器的作用

![image-20240427180456033](picture/image-20240427180456033.png)

![image-20240427180749996](picture/image-20240427180749996.png)

![image-20240427180838558](picture/image-20240427180838558.png)

![image-20240427180949050](picture/image-20240427180949050.png)

返回时强制转换（因为，迭代器就是对指针的模拟，也就是说，迭代器中模拟的行为都是指针可以实现的行为，这也就是强制转换不会丢失数据的原因）

对于自定义类型的流处理

![image-20240506205409987](picture/image-20240506205409987.png)

![image-20240506205505920](picture/image-20240506205505920.png)

重载->

![image-20240506205805883](picture/image-20240506205805883.png)

const_iterator

![image-20240507195523668](picture/image-20240507195523668.png)

![image-20240507195841839](picture/image-20240507195841839-172300265426419.png)

![image-20240507200119983](picture/image-20240507200119983.png)

![image-20240507200208422](picture/image-20240507200208422.png)

模板 typename class的区别

![image-20240507201426018](picture/image-20240507201426018.png)

没有被实例化的类模板，编译器无法确定类：：后内部是什么，这时候需要typename

![image-20240507201921641](picture/image-20240507201921641.png)

![image-20240507202243218](picture/image-20240507202243218.png)

模板（泛型编程）本质，将我们需要编译的代码，交给编译器处理
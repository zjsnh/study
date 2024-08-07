最小栈

![image-20240507215113229](picture/image-20240507215113229.png)

![image-20240507214836403](picture/image-20240507214836403.png)

![image-20240507214930519](picture/image-20240507214930519.png)

当后面插入值小于等于时，就进行栈的插入

![image-20240507215432676](picture/image-20240507215432676.png)

![image-20240507220059166](picture/image-20240507220059166.png)

![image-20240507222002171](picture/image-20240507222002171.png)

![image-20240507222133971](picture/image-20240507222133971.png)

![image-20240507223322557](picture/image-20240507223322557.png)

![image-20240509201038248](picture/image-20240509201038248.png)

![image-20240509201005846](picture/image-20240509201005846.png)

逆波兰表达式

![image-20240509201421232](picture/image-20240509201421232.png)

![image-20240509201701620](picture/image-20240509201701620.png)

![image-20240509203124621](picture/image-20240509203124621.png)

![image-20240509203628574](picture/image-20240509203628574.png)

![image-20240509205036806](picture/image-20240509205036806.png)

## stack

![image-20240509212753430](picture/image-20240509212753430.png)

两个模板参数

```C++
template<class T,class Container>
```

Container 适配器

可以使用不同的数据类型 比如vector list 都可以实现

![image-20240509212932077](picture/image-20240509212932077.png)

![image-20240509213004085](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240509213004085.png)

提供这些接口即可

![image-20240509213152978](picture/image-20240509213152978.png)

deque 双端队列 不是队列，只是普通容器 

![image-20240509213548509](picture/image-20240509213548509.png)

![image-20240509214216749](picture/image-20240509214216749.png)

![image-20240509214650708](picture/image-20240509214650708.png)

![image-20240509215601767](picture/image-20240509215601767.png)

assign   赋值，可以使用迭代器

![image-20240510172539185](picture/image-20240510172539185.png)

deque可以使用库里的sort 阴天他的迭代器被分类成随机访问跌打去 redom iterator  

deque 在实现stack和queue上，比vector list更好的 头尾插入删除的性能更强，但其他的更能性能并不行

![image-20240510174240517](picture/image-20240510174240517.png)
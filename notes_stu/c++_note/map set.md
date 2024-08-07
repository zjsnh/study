# map set 

![image-20240530160603840](picture/image-20240530160603840.png)



![image-20240530160857790](picture/image-20240530160857790.png)	![image-20240530162018925](picture/image-20240530162018925.png)

insert 返回值 pair

![image-20240530162520175](picture/image-20240530162520175.png)

对于erase 使用迭代器删除不存在的，将会报错，使用值删除没有报错

同时我们可以通过接收erase返回值判断是否正确删除

## lower_bound upper_bound

![image-20240530163927591](picture/image-20240530163927591.png)

erase右是开区间

## equal_range

![image-20240530164419646](picture/image-20240530164419646.png)

返回这个数存在的左右区间（左闭右开）

## count

也可以判断key在不在，

![image-20240530164557551](picture/image-20240530164557551.png)

**set不支持修改**

# multiset

![image-20240530164814329](picture/image-20240530164814329.png)

允许多个相同的key插入

![image-20240530164852415](picture/image-20240530164852415.png)

## find

![image-20240530165610002](picture/image-20240530165610002.png)

因为multiset允许存在多个相同的值，这时候，equal__range就可以一次性删除所有的val，count也可以在这里找到val右几个

![image-20240530165928932](picture/image-20240530165928932.png)

同时可以通过接收erase的返回值判断删除几个val

```C++
size_t n=s.erase(2);
```

这些函数返回size_t的原因就是multiset存在多个相同的val，判断 

# map

key_value类型

![image-20240530170351253](picture/image-20240530170351253.png)

## insert

```c++
map<string,string> m;
m.insert(pair<string,string> ("sort","排序"));
```

![image-20240530170818665](picture/image-20240530170818665.png)

![image-20240530172036091](picture/image-20240530172036091.png)

## nake_pair

函数模板

![image-20240530172444454](picture/image-20240530172444454.png)

![image-20240530172424979](picture/image-20240530172424979.png)

 

## iterator

![image-20240530173311251](picture/image-20240530173311251.png)

![image-20240530173326634](picture/image-20240530173326634.png)

![image-20240530173332062](picture/image-20240530173332062.png)

![image-20240530173338886](picture/image-20240530173338886.png)

![image-20240530173819747](picture/image-20240530173819747.png)

但是这时候是深拷贝，消耗较大

使用&就不用拷贝了

![image-20240530174009878](picture/image-20240530174009878.png)

## [ ]（重要）

![image-20240530174532328](picture/image-20240530174532328.png)

传入key 返回value的引用

![image-20240530180012788](picture/image-20240530180012788.png)

![image-20240530180254452](picture/image-20240530180254452.png)

# multi_map

就是允许键值冗余

![image-20240531184123659](picture/image-20240531184123659.png)

<img src="picture/image-20240531184200118.png" alt="image-20240531184200118" style="zoom:150%;" />

也不支持[]  因为key可能会一样

![image-20240531190418552](picture/image-20240531190418552.png)

pair支持sort

![image-20240531185820120](picture/image-20240531185820120.png)

但是比较方式是比较一个小就小

![image-20240531190149689](picture/image-20240531190149689.png)

![image-20240531191639954](picture/image-20240531191639954.png)

写仿函数来获取自己需要的比较方式

##  稳定排序库函数

![image-20240531191448280](picture/image-20240531191448280.png)

sort不稳定

![image-20240531191726082](picture/image-20240531191726082.png)

![image-20240531192247761](picture/image-20240531192247761.png)

两个数据类型相同就可以使用迭代器区间初始化

## set的作用：排序+去重

![image-20240531193328624](picture/image-20240531193328624.png)

![image-20240531193443891](picture/image-20240531193443891.png)

![image-20240531193632591](picture/image-20240531193632591.png)

自动备份，自动同步

![image-20240531194424630](picture/image-20240531194424630.png)

![image-20240531194708989](picture/image-20240531194708989.png)


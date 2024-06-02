# AVL tree

![image-20240531201846454](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240531201846454.png)

![image-20240531202007689](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240531202007689.png)

![image-20240531202250343](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240531202250343.png)

![image-20240531204549714](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240531204549714.png)

#  旋转！！！！！

![image-20240601154054431](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601154054431.png)

![image-20240601154927622](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601154927622.png)

## 左单旋

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601155312777.png" alt="image-20240601155312777" style="zoom:150%;" />

![image-20240601155454398](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601155454398.png)

![image-20240601160039637](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601160039637.png)

![image-20240601162044983](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601162044983.png)

![image-20240601163310617](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240601163310617.png)

![image-20240602195909425](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602195909425.png)

## 判断旋转状态

左单选   parent->_pf==2 ,cur->_pf==1

单纯右边高同理，右单旋相反

**旋转之后，总体（最高）高度没有改变，作为子树，对于上层的高度差没有影响也就不用向上影响了**

![image-20240602200651191](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602200651191.png)

# 双旋 

![image-20240602201504168](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602201504168.png)

   ![image-20240602202056174](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602202056174.png)

![image-20240602202319922](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602202319922.png)

![image-20240602204536028](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602204536028.png)

![image-20240602204810554](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602204810554.png)

![image-20240602205202651](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602205202651.png)

![image-20240602212343795](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602212343795.png)

# 测试

![image-20240602212709259](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240602212709259.png)

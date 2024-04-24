# string 模拟实现

编写文字的编码



![image-20240423152426863](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423152426863.png)

![image-20240423155225679](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423155225679.png)

![image-20240423155500789](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423155500789.png)

![image-20240423160317871](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423160317871.png)

头文件展开

![image-20240423161645245](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423161645245.png)

![image-20240423162501260](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423162501260.png)

![image-20240423162739444](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423162739444.png)

![image-20240423163242413](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423163242413.png)

![image-20240423163320960](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423163320960.png)

 

![image-20240423164231594](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423164231594.png)

静态变量

![image-20240423165024520](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423165024520.png)

只有无符号整型可以

![image-20240423170023598](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423170023598.png)

![image-20240423170603925](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423170603925.png)

![image-20240423171532242](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423171532242.png)

![image-20240423171737065](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423171737065.png)

空格和换行都不作为字符输入，导致char类型的ch无法拿到空格进行结束判断

![image-20240423172412566](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423172412566.png)

![image-20240423172624352](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423172624352.png)

![image-20240423205312244](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423205312244.png)

strstr

![image-20240423213254653](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423213254653.png)

![image-20240423213813211](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423213813211.png)

![image-20240423215254463](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240423215254463.png)

![image-20240424191312659](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424191312659.png)

![image-20240424191359778](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424191359778.png)

提前对内置类型处理![image-20240424191516050](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424191516050.png)

![image-20240424191928009](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424191928009.png)

交换后tmp指向的是this指向的空间，而出作用域后tmp析构，将之前this交换之前的空间销毁，同时this指向新空间

![image-20240424192058083](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424192058083.png)

就是delete[] _str

![image-20240424192223562](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424192223562.png)

更加极致，在传参的过程中，调用拷贝构造，然后交换空间，析构函数销毁tmp

流插入，减少开空间的次数

![image-20240424193309341](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424193309341.png)

每次字符大于128时插入一次

![image-20240424204825545](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424204825545.png)

防止内存碎片



引用计数

![image-20240424205515957](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424205515957.png)

![image-20240424205932479](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424205932479.png)

vs下是 深拷贝



![image-20240424210051082](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424210051082.png)

g++下是浅拷贝

![image-20240424210831202](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424210831202.png)

浅拷贝后对字符串进行写时拷贝

![image-20240424210901833](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424210901833.png)

编译器就会进行浅拷贝

![image-20240424211507959](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240424211507959.png)

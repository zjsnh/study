# make/makefile

make是命令，makefile是文件，当前目录下的文件

![image-20240417210733188](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417210733188.png)

makefile的自动化推导，依赖关系与依赖方法，栈式结构

![image-20240417212111650](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417212111650.png)

clean无依赖关系，有依赖方法，独自存在

make默认执行第一个目标文件，也可以加执行文件取执行相应的依赖方法，同时会检测文件是否被更新过，没有更新过就不会重新编译，多个依赖文件，空格间隔即可

## 怎么做到的：

比较修改时间！！！！！

![image-20240417213115269](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417213115269.png)

![image-20240417214837854](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417214837854.png)

我们可以通过touch更新文件的时间，并灭有修改文件内容，make后发现，无法make

## 伪目标

.PHONY

对于修饰的文件可以不受限次被编译（总是会执行）

![image-20240417215344805](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417215344805.png)

但是不推荐目标文件用伪目标修饰，可以将清理文件进行伪目标修饰

## 特殊符号

```c++
$@ $^
```

前一个是依赖关系左边  一个是依赖关系右边的字符

![image-20240417220055217](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417220055217.png)

```
@
```

使命令不显示

![image-20240417220420439](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417220420439.png)

## 进度条

![image-20240417222803573](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417222803573.png)

![image-20240417223446735](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417223446735.png)out

ffush  将缓冲区的信息直接刷新输出到 输出流  stdout 是标准输出流

#### 倒计时

![image-20240417223747348](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240417223747348.png)

```c++
%2d//显示两个字符，防止输出流字符时，第二个显示字符不被更新，%-2d 从左边开始写入
```

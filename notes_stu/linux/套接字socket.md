# 套接字socket

![image-20241017095047363](D:\code\study\notes_stu\c++_note\picture\image-20241017095047363.png)

路由强接收到报文后解析重新封装，这样就可以让以太网封装的报文解包（更换mac地址，更新出发地，目的地）封装发送给令牌环（不在关心底层网络的差别）

![image-20241017095709003](D:\code\study\notes_stu\c++_note\picture\image-20241017095709003.png)

![image-20241017100051999](D:\code\study\notes_stu\c++_note\picture\image-20241017100051999.png)

报文传输在子网中解包封包进行传输到目的服务器

![image-20241017100619423](D:\code\study\notes_stu\c++_note\picture\image-20241017100619423.png)

![image-20241017100917905](D:\code\study\notes_stu\c++_note\picture\image-20241017100917905.png)

windows![image-20241017100954028](D:\code\study\notes_stu\c++_note\picture\image-20241017100954028.png)

## 端口号

![image-20241017103546790](D:\code\study\notes_stu\c++_note\picture\image-20241017103546790.png)

![image-20241017103614935](D:\code\study\notes_stu\c++_note\picture\image-20241017103614935.png)

![image-20241017103905372](D:\code\study\notes_stu\c++_note\picture\image-20241017103905372.png)

![image-20241017104759241](D:\code\study\notes_stu\c++_note\picture\image-20241017104759241.png)

![image-20241017105620221](D:\code\study\notes_stu\c++_note\picture\image-20241017105620221.png)

**这是TCP**

![image-20241017105958570](D:\code\study\notes_stu\c++_note\picture\image-20241017105958570.png)

客户端必须知道服务器端口号

![image-20241017110814640](D:\code\study\notes_stu\c++_note\picture\image-20241017110814640.png)

**这些描述都是中性词，并没有褒贬的意思**，可靠传输需要做出更多复杂的操作，更加难以维护

![image-20241017150627711](D:\code\study\notes_stu\c++_note\picture\image-20241017150627711.png)

**因为无法通过协议来表示某一段数据是大端还是小端(无法解析），所以规定数据在发送时转化为大端即网络字节序**

![image-20241017151308101](D:\code\study\notes_stu\c++_note\picture\image-20241017151308101.png)

## socket接口

![image-20241017151508092](D:\code\study\notes_stu\c++_note\picture\image-20241017151508092.png)

![image-20241017152542651](D:\code\study\notes_stu\c++_note\picture\image-20241017152542651.png)

![image-20241017155458462](D:\code\study\notes_stu\c++_note\picture\image-20241017155458462.png)

![image-20241017160048507](D:\code\study\notes_stu\c++_note\picture\image-20241017160048507.png)

![image-20241017160058612](D:\code\study\notes_stu\c++_note\picture\image-20241017160058612.png)

**UDP**

![image-20241017161628551](D:\code\study\notes_stu\c++_note\picture\image-20241017161628551.png)

将指定的指针初始化为0

![image-20241017162849222](D:\code\study\notes_stu\c++_note\picture\image-20241017162849222.png)

![image-20241017164615768](D:\code\study\notes_stu\c++_note\picture\image-20241017164615768.png)

网络序列， 字符串 ，类型转化接口

![image-20241017165304952](D:\code\study\notes_stu\c++_note\picture\image-20241017165304952.png)

![image-20241017165532853](D:\code\study\notes_stu\c++_note\picture\image-20241017165532853.png)

绑定socket和定义的sockaddr

![image-20241017165939733](D:\code\study\notes_stu\c++_note\picture\image-20241017165939733.png)

在函数内部会根据family字段判断是哪种通信

![image-20241017170442014](D:\code\study\notes_stu\c++_note\picture\image-20241017170442014.png)

UDP读取数据（因为UDP是面向数据报的，read等接口是面向字节流的）

![image-20241017171015275](D:\code\study\notes_stu\c++_note\picture\image-20241017171015275.png)

![image-20241017171419892](D:\code\study\notes_stu\c++_note\picture\image-20241017171419892.png)

![image-20241017172217142](D:\code\study\notes_stu\c++_note\picture\image-20241017172217142.png)

我们构建服务器的时候不能之间绑定某一个公网ip，因为那样只会导致服务器只能收到这一个ip地址发来的信息，我们只需要绑定为0只好（接收到任何ip发来的信息）

![image-20241018170056065](D:\code\study\notes_stu\c++_note\picture\image-20241018170056065.png)

任意ip都可以，因为是全0写不写 htonl都可以了

![image-20241018170639551](D:\code\study\notes_stu\c++_note\picture\image-20241018170639551.png)

对于绑定的端口

![image-20241018171210905](D:\code\study\notes_stu\c++_note\picture\image-20241018171210905.png)

一般绑定1024以上的端口号 绑到8000以上差不多，非要绑定的话就需要使用sudo去绑定

![image-20241018171604679](D:\code\study\notes_stu\c++_note\picture\image-20241018171604679.png)

**通过命令行参数传入端口号**

**客户端一定要绑定端口和ip，不需要用户的显示bind，一般由os自由选择**

![image-20241018173605002](D:\code\study\notes_stu\c++_note\picture\image-20241018173605002.png)

![image-20241018174957549](D:\code\study\notes_stu\c++_note\picture\image-20241018174957549.png)

基本dome

![image-20241018174315085](D:\code\study\notes_stu\c++_note\picture\image-20241018174315085.png)

![image-20241018181554680](D:\code\study\notes_stu\c++_note\picture\image-20241018181554680.png)

![image-20241018182008113](D:\code\study\notes_stu\c++_note\picture\image-20241018182008113.png)

使用这个函数执行命令

![image-20241018182433645](D:\code\study\notes_stu\c++_note\picture\image-20241018182433645.png)

![image-20241018182531899](D:\code\study\notes_stu\c++_note\picture\image-20241018182531899.png)

![image-20241018182724751](D:\code\study\notes_stu\c++_note\picture\image-20241018182724751.png)

![image-20241019165300179](D:\code\study\notes_stu\c++_note\picture\image-20241019165300179.png)

过滤，检查命令信息

![image-20241019174829905](D:\code\study\notes_stu\c++_note\picture\image-20241019174829905.png)

![image-20241019180143288](D:\code\study\notes_stu\c++_note\picture\image-20241019180143288.png)

**socket允许同时读写**

![image-20241019192209458](D:\code\study\notes_stu\c++_note\picture\image-20241019192209458.png)

解决输入输出在一起的问题（简单终端）

![image-20241019192727852](D:\code\study\notes_stu\c++_note\picture\image-20241019192727852.png)

终端文件

<img src="D:\code\study\notes_stu\c++_note\picture\image-20241019192750494.png" alt="image-20241019192750494" style="zoom:50%;" />

开启多个终端输入输出

![image-20241019193141765](D:\code\study\notes_stu\c++_note\picture\image-20241019193141765.png)

![image-20241019193155382](D:\code\study\notes_stu\c++_note\picture\image-20241019193155382.png)

将终端fd重定向到标准输入，

![image-20241019193241631](D:\code\study\notes_stu\c++_note\picture\image-20241019193241631.png)

这样我们所有的输出就会输出到这个终端里

![image-20241019193429778](D:\code\study\notes_stu\c++_note\picture\image-20241019193429778.png)

重定向到标准错误（因为都是屏幕），把所有的信息打印出来

![image-20241019193605653](D:\code\study\notes_stu\c++_note\picture\image-20241019193605653.png)

第二种：

![image-20241019193927257](D:\code\study\notes_stu\c++_note\picture\image-20241019193927257.png)

**直接重定向  2 表示标准错误输出**

![image-20241019194217036](D:\code\study\notes_stu\c++_note\picture\image-20241019194217036.png)

![image-20241019215221993](D:\code\study\notes_stu\c++_note\picture\image-20241019215221993.png)

![image-20241019195707548](D:\code\study\notes_stu\c++_note\picture\image-20241019195707548.png)

![image-20241019201018346](D:\code\study\notes_stu\c++_note\picture\image-20241019201018346.png)

![image-20241019201047000](D:\code\study\notes_stu\c++_note\picture\image-20241019201047000.png)

![image-20241019201238555](D:\code\study\notes_stu\c++_note\picture\image-20241019201238555.png)

而下面这个函数传入的空间就是为了解决这个问题

## TCP

![image-20241019201302528](D:\code\study\notes_stu\c++_note\picture\image-20241019201302528.png)

![image-20241021090342333](D:\code\study\notes_stu\c++_note\picture\image-20241021090342333.png)

将套接字设置为监听状态，因为TCP需要稳定链接，服务器需要一直等待连接

![image-20241021090909173](D:\code\study\notes_stu\c++_note\picture\image-20241021090909173.png)

![image-20241021091140600](D:\code\study\notes_stu\c++_note\picture\image-20241021091140600.png)

![image-20241021091238519](D:\code\study\notes_stu\c++_note\picture\image-20241021091238519.png)

![image-20241021091402549](D:\code\study\notes_stu\c++_note\picture\image-20241021091402549.png)

对于新创建的套接字只是为了监听连接，而对于accept返回的套接字是为了io

![image-20241021093137611](D:\code\study\notes_stu\c++_note\picture\image-20241021093137611.png)

可以用来测试连接服务器，TCP在云服务器上，也不能绑定公网ip，可以绑定127. 0.0.1

![image-20241021104405659](D:\code\study\notes_stu\c++_note\picture\image-20241021104405659.png)

通信接口会自动转化序列，我们只需要把交给操作系统的转化

![image-20241021094935182](D:\code\study\notes_stu\c++_note\picture\image-20241021094935182.png)

![image-20241021095015047](D:\code\study\notes_stu\c++_note\picture\image-20241021095015047.png)

![image-20241021095614395](D:\code\study\notes_stu\c++_note\picture\image-20241021095614395.png)

![](D:\code\study\notes_stu\c++_note\picture\image-20241021110125381.png)

**直接退出使用孙子进程处理，这个进程退出时会被操作系统回收**

![image-20241021110651758](D:\code\study\notes_stu\c++_note\picture\image-20241021110651758.png)

**使用信号处理将该信号忽略掉**



![image-20241021105750630](D:\code\study\notes_stu\c++_note\picture\image-20241021105750630.png)

创建进程的成本太高了，使用线程来处理

![image-20241021111756869](D:\code\study\notes_stu\c++_note\picture\image-20241021111756869.png)

![image-20241021111921206](D:\code\study\notes_stu\c++_note\picture\image-20241021111921206.png)

静态方法只能访问静态成员，或者方法

![image-20241021112254412](D:\code\study\notes_stu\c++_note\picture\image-20241021112254412.png)

我们也可以使用传入类进行访问

![image-20241021112316092](D:\code\study\notes_stu\c++_note\picture\image-20241021112316092.png)

但是对于系统来说，创建线程也会消耗时间，

**使用线程池**

![image-20241021155231857](D:\code\study\notes_stu\c++_note\picture\image-20241021155231857.png)

![image-20241021160359869](D:\code\study\notes_stu\c++_note\picture\image-20241021160359869.png)

![image-20241021160444458](D:\code\study\notes_stu\c++_note\picture\image-20241021160444458.png)

设置socket属性

![image-20241022161532078](D:\code\study\notes_stu\c++_note\picture\image-20241022161532078.png)

![image-20241022161836944](D:\code\study\notes_stu\c++_note\picture\image-20241022161836944.png)

### 守护进程

**防止因为xshell窗口关掉导致进程关闭**

![image-20241022165323741](D:\code\study\notes_stu\c++_note\picture\image-20241022165323741.png)

**谁拥有标准输入谁是前台进程**

![image-20241022170349678](D:\code\study\notes_stu\c++_note\picture\image-20241022170349678.png)

**fg + 任务号   ：将后台进程提到前台**

jobs查看后台任务数量

![image-20241022171539176](D:\code\study\notes_stu\c++_note\picture\image-20241022171539176.png)

![image-20241022171732693](D:\code\study\notes_stu\c++_note\picture\image-20241022171732693.png)

当前台任务被暂停了，操作系统会自动把bash提到前台，并把这个任务放到后台

bg + 任务号 继续运行后台任务

![image-20241022172055503](D:\code\study\notes_stu\c++_note\picture\image-20241022172055503.png)

**每一个用户登录系统的时候都会有session id**

![image-20241022173345667](D:\code\study\notes_stu\c++_note\picture\image-20241022173345667.png)

一个任务由一个进程组来完成，而这个进程组可能由一个或者多个进程组成

**这个session id就是bash的pid**

![image-20241022174205741](D:\code\study\notes_stu\c++_note\picture\image-20241022174205741.png)

**关闭bash之后，后台进程并没有退出，同时被系统领养，但是标签页没有了，但是有些进程我们并不想受到用户登录退出的影响**

![image-20241022174554462](D:\code\study\notes_stu\c++_note\picture\image-20241022174554462.png)

自成会话

![image-20241022213253944](D:\code\study\notes_stu\c++_note\picture\image-20241022213253944.png)

**创建一个会话，并设置该进程的会话id设置为设置的这个会话id**

同时这个任务组的leader不能调用这个函数

![image-20241022213648580](D:\code\study\notes_stu\c++_note\picture\image-20241022213648580.png)

**让父进程退出，子进程设置守护进程**

![image-20241022214626797](D:\code\study\notes_stu\c++_note\picture\image-20241022214626797.png)

![image-20241022215357938](D:\code\study\notes_stu\c++_note\picture\image-20241022215357938.png)

4：把代码调试信息不显示，而对于日志信息可以打印到文件里

![image-20241023091331755](D:\code\study\notes_stu\c++_note\picture\image-20241023091331755.png)

![image-20241023091348045](D:\code\study\notes_stu\c++_note\picture\image-20241023091348045.png)

**守护进程**

![image-20241023091525342](D:\code\study\notes_stu\c++_note\picture\image-20241023091525342.png)

![image-20241023093147495](D:\code\study\notes_stu\c++_note\picture\image-20241023093147495.png)

系统的守护进程

![image-20241023093323737](D:\code\study\notes_stu\c++_note\picture\image-20241023093323737.png)

![image-20241023093337006](D:\code\study\notes_stu\c++_note\picture\image-20241023093337006.png)

![image-20241023093703109](D:\code\study\notes_stu\c++_note\picture\image-20241023093703109.png)

tcp全双工

![image-20241023094840489](D:\code\study\notes_stu\c++_note\picture\image-20241023094840489.png)

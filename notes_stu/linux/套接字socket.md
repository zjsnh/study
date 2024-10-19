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

![image-20241019195707548](D:\code\study\notes_stu\c++_note\picture\image-20241019195707548.png)

![image-20241019201018346](D:\code\study\notes_stu\c++_note\picture\image-20241019201018346.png)

![image-20241019201047000](D:\code\study\notes_stu\c++_note\picture\image-20241019201047000.png)

![image-20241019201238555](D:\code\study\notes_stu\c++_note\picture\image-20241019201238555.png)

而下面这个函数传入的空间就是为了解决这个问题

## TCP

![image-20241019201302528](D:\code\study\notes_stu\c++_note\picture\image-20241019201302528.png)

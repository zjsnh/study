# TCP

传输控制协议

![image-20241120163116503](D:\code\study\notes_stu\c++_note\picture\image-20241120163116503.png)

![image-20241120164814166](D:\code\study\notes_stu\c++_note\picture\image-20241120164814166.png)

流量控制，服务器无法及时处理客户端发送的数据，发送的数据已经浪费的很多系统资源，客户端可以放慢发送数据的速度，让服务器有一定时间处理

确认应答机制 让客户端知道服务器收到了发送的消息

![image-20241121162051918](D:\code\study\notes_stu\c++_note\picture\image-20241121162051918.png)

16位空间大小使用来确认缓冲区大小，用来流量控制

![image-20241121162417705](D:\code\study\notes_stu\c++_note\picture\image-20241121162417705.png)

### 确认应答

对于正常消息，发出应答确认，但是我们没有必要对应答进行应答确认，我们只需要保证正常的消息收到的这个消息被收到即可

如果没有收到应答

![image-20241121164534885](D:\code\study\notes_stu\c++_note\picture\image-20241121164534885.png)

**当我们没有收到应答的时候，这段数据是不会被丢弃的**TCP的传输关键就是对数据的应答，发送缓冲区也就是因为不能随时丢弃数据而存在的

如果当我们收到消息的同时也想要发送消息，这就叫捎带应答，在整个通信的过程中，单纯的应答的存在是很少的

**对于乱序的数据**

![image-20241121165852440](D:\code\study\notes_stu\c++_note\picture\image-20241121165852440.png)

乱序的数据本身就是不可靠的，如何处理乱序的数据

TCP包头里带有序号用于标识数据包的顺序

![image-20241121165832886](D:\code\study\notes_stu\c++_note\picture\image-20241121165832886.png)

![image-20241121170420623](D:\code\study\notes_stu\c++_note\picture\image-20241121170420623.png)

**确认序号：对收到的序号进行加一进行应答**

**同时这个应答收到之后，我们可以认为这个确认应答的序号之前的所有数据全部都收到了，我们可以允许应答有少量丢失**

**确认序号跟序号两个都需要的原因是因为TCP报文可能即是报文也是应答**

![image-20241121172719891](D:\code\study\notes_stu\c++_note\picture\image-20241121172719891.png)

报文类型

![image-20241125152603003](D:\code\study\notes_stu\c++_note\picture\image-20241125152603003.png)

![image-20241125154920035](D:\code\study\notes_stu\c++_note\picture\image-20241125154920035.png)

**URG** 标识报文中有紧急数据，表示16位紧急指针有效

tcp报文里，紧急数据只有一个字节，紧急指针代表偏移量

![image-20241125160546568](D:\code\study\notes_stu\c++_note\picture\image-20241125160546568.png)

常规数据 ：带内数据

紧急数据 ： 带外数据

## 重传

![image-20241125162830958](D:\code\study\notes_stu\c++_note\picture\image-20241125162830958.png)

![image-20241125174334915](D:\code\study\notes_stu\c++_note\picture\image-20241125174334915.png)

**使用三次握手，让建立连接的成本给到客户端**

![image-20241125174917544](D:\code\study\notes_stu\c++_note\picture\image-20241125174917544.png)

**大量客户端对服务器进行请求**

![image-20241125175100833](D:\code\study\notes_stu\c++_note\picture\image-20241125175100833.png)

连接建立成功跟上层accept无关，三次握手是双方操作系统完成的

![image-20241127163230304](D:\code\study\notes_stu\c++_note\picture\image-20241127163230304.png)

![image-20241127163414296](D:\code\study\notes_stu\c++_note\picture\image-20241127163414296.png)

![image-20241127163420196](D:\code\study\notes_stu\c++_note\picture\image-20241127163420196.png)

客户端认为建立成功了，但是服务端listen第二个参数为1 也就是全连接队列最大为2，那么第三个无法进入到全连接队列

![image-20241127163603460](D:\code\study\notes_stu\c++_note\picture\image-20241127163603460.png)

最后一个ACK发过去了，但是服务器没有接收，丢弃了，因为全链接队列已经满了，因为上层没有使用accept对队列里的连接取走

![image-20241127163746728](D:\code\study\notes_stu\c++_note\picture\image-20241127163746728.png)

过一会后，未建立成功的连接就会断开

![image-20241127163900609](D:\code\study\notes_stu\c++_note\picture\image-20241127163900609.png)

**但是客户端仍然认为连接还存在，这就是客户端与服务器双方连接不一致的情况，如果已经断开的连接对服务器发消息就会收到服务器未建立成功的报文，重新进行三次握手**，这样的连接叫做半连接，如果这样的连接过多，就可能会导致正常的连接连接不上，这就叫syn洪水

![image-20241127164149719](D:\code\study\notes_stu\c++_note\picture\image-20241127164149719.png)

![image-20241127170403323](D:\code\study\notes_stu\c++_note\picture\image-20241127170403323.png)

不能没有：资源不被充分利用

不能太长：硬件资源决定了全连接长度的长度，一般10 16 32

![image-20241127171056561](D:\code\study\notes_stu\c++_note\picture\image-20241127171056561.png)

![image-20241127172518019](D:\code\study\notes_stu\c++_note\picture\image-20241127172518019.png)

![image-20241127172612951](D:\code\study\notes_stu\c++_note\picture\image-20241127172612951.png)

### 绑定失败的原因

当服务器主动断开时，进入time_wait状态，而这个状态会维持一段时间，ip跟port还在被使用，就无法与其他进程与port进行绑定，但是这样会导致服务器无法即使重启

![image-20241127173253112](D:\code\study\notes_stu\c++_note\picture\image-20241127173253112.png)

复用端口

![image-20241127173443250](D:\code\study\notes_stu\c++_note\picture\image-20241127173443250.png)

**一段报文在网络里存在的最长时间为一个 msl   time_wait的时间  防止被动断开的一方没有收到最后一次握手时ACK，确保主动断开的一方可以收到被动断开的一方补发的FIN，从而重发ACK，最大情况保证正常断开**

![image-20241127174946922](D:\code\study\notes_stu\c++_note\picture\image-20241127174946922.png)

![image-20241127175253139](D:\code\study\notes_stu\c++_note\picture\image-20241127175253139.png)

## 滑动窗口

![image-20241127191259173](D:\code\study\notes_stu\c++_note\picture\image-20241127191259173.png)

**网络：图解http  图解tcp/ip**

![image-20241127193402565](D:\code\study\notes_stu\c++_note\picture\image-20241127193402565.png)

![image-20241127194149396](D:\code\study\notes_stu\c++_note\picture\image-20241127194149396.png)

![image-20241127195450025](D:\code\study\notes_stu\c++_note\picture\image-20241127195450025.png)

![image-20241127195840782](D:\code\study\notes_stu\c++_note\picture\image-20241127195840782.png)

![image-20241127195846631](D:\code\study\notes_stu\c++_note\picture\image-20241127195846631.png)

![image-20241128160150977](D:\code\study\notes_stu\c++_note\picture\image-20241128160150977.png)

![image-20241128162222787](D:\code\study\notes_stu\c++_note\picture\image-20241128162222787.png)

延迟应答是为了接收方向发送方应答时回复一个更大的窗口

![image-20241128162701484](D:\code\study\notes_stu\c++_note\picture\image-20241128162701484.png)

![image-20241128164332670](D:\code\study\notes_stu\c++_note\picture\image-20241128164332670.png)

![image-20241128165303095](D:\code\study\notes_stu\c++_note\picture\image-20241128165303095.png)

![image-20241128165459425](D:\code\study\notes_stu\c++_note\picture\image-20241128165459425.png)

### 慢启动

**拥塞窗口**

![image-20241130160654131](D:\code\study\notes_stu\c++_note\picture\image-20241130160654131.png)

![image-20241130162222993](D:\code\study\notes_stu\c++_note\picture\image-20241130162222993.png)

采取较小的窗口

![image-20241130162738174](D:\code\study\notes_stu\c++_note\picture\image-20241130162738174.png)

### 面向字节流

![image-20241130170037193](D:\code\study\notes_stu\c++_note\picture\image-20241130170037193.png)

当用户读取数据后，传来的数据流并不是整个的报文，

**粘包问题**

解决这个问题就需要定制协议，每一个完整的请求需要有自己内容的大小，防止多解析，或者报文不完整时解析

![image-20241130172213289](D:\code\study\notes_stu\c++_note\picture\image-20241130172213289.png)

**tcp**异常

![image-20241130173635953](D:\code\study\notes_stu\c++_note\picture\image-20241130173635953.png)

**UDP可靠性**

![image-20241130173757398](D:\code\study\notes_stu\c++_note\picture\image-20241130173757398.png)

## 文件与socket

![image-20241130182309998](D:\code\study\notes_stu\c++_note\picture\image-20241130182309998.png)

![image-20241130183253385](D:\code\study\notes_stu\c++_note\picture\image-20241130183253385.png)

![image-20241130184445582](D:\code\study\notes_stu\c++_note\picture\image-20241130184445582.png)
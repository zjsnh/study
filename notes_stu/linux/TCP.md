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
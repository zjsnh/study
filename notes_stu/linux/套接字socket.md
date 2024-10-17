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


# HTTP协议

![image-20241029182920106](D:\code\study\notes_stu\c++_note\picture\image-20241029182920106.png)

**对于http（80）或者https（443）都有默认的固定的端口号**

![image-20241030171906937](D:\code\study\notes_stu\c++_note\picture\image-20241030171906937.png)

![image-20241030172319098](D:\code\study\notes_stu\c++_note\picture\image-20241030172319098.png)

![image-20241030172548176](D:\code\study\notes_stu\c++_note\picture\image-20241030172548176.png)

![image-20241030172636296](D:\code\study\notes_stu\c++_note\picture\image-20241030172636296.png)

# http请求与响应

## 请求

![image-20241030174829882](D:\code\study\notes_stu\c++_note\picture\image-20241030174829882.png)

**通过完整读取到报头，报头里包含有正文的长度，来保证整个报文的完整读取**

## 响应

![image-20241030180243840](D:\code\study\notes_stu\c++_note\picture\image-20241030180243840.png)

![image-20241030180336854](D:\code\study\notes_stu\c++_note\picture\image-20241030180336854.png)

**查看请求使用fiddler抓包**

# webserver

![image-20241030184151063](D:\code\study\notes_stu\c++_note\picture\image-20241030184151063.png)

**http请求**

![image-20241031154926971](D:\code\study\notes_stu\c++_note\picture\image-20241031154926971.png)

**网站策略，判断是不是正常客户端，反爬**，同时网站也会通过user-agent判断下载时的匹配版本（智能推荐）

![image-20241031160744495](D:\code\study\notes_stu\c++_note\picture\image-20241031160744495.png)

![image-20241031160258041](D:\code\study\notes_stu\c++_note\picture\image-20241031160258041.png)

浏览器解释正文并显示

![image-20241031160421740](D:\code\study\notes_stu\c++_note\picture\image-20241031160421740.png)

html

![image-20241031161554638](D:\code\study\notes_stu\c++_note\picture\image-20241031161554638.png)

![image-20241031161912872](D:\code\study\notes_stu\c++_note\picture\image-20241031161912872.png)

web根目录，将所有的例如网页的html，图片或者说是什么资源都放到这个根目录下的树状结构

![image-20241031162118414](D:\code\study\notes_stu\c++_note\picture\image-20241031162118414.png)

![image-20241031162540167](D:\code\study\notes_stu\c++_note\picture\image-20241031162540167.png)

**读取相对应文件的内容，返回正文**

![image-20241031162706031](D:\code\study\notes_stu\c++_note\picture\image-20241031162706031.png)

想要修改html，直接修改刷新网页重新获取即可

![image-20241031162848865](D:\code\study\notes_stu\c++_note\picture\image-20241031162848865.png)

![image-20241031171412531](D:\code\study\notes_stu\c++_note\picture\image-20241031171412531.png)

![image-20241031171639681](D:\code\study\notes_stu\c++_note\picture\image-20241031171639681.png)

### stringstream分割字符串

![image-20241031172050546](D:\code\study\notes_stu\c++_note\picture\image-20241031172050546.png)

**按照空格分割字符串**

![image-20241031172222768](D:\code\study\notes_stu\c++_note\picture\image-20241031172222768.png)

wget 底层就是http协议

![image-20241031172518999](D:\code\study\notes_stu\c++_note\picture\image-20241031172518999.png)

![image-20241031173203945](D:\code\study\notes_stu\c++_note\picture\image-20241031173203945.png)

**对于访问的资源路径的处理**

![image-20241031173352136](D:\code\study\notes_stu\c++_note\picture\image-20241031173352136.png)

![image-20241031173358962](D:\code\study\notes_stu\c++_note\picture\image-20241031173358962.png)

![image-20241031173502836](D:\code\study\notes_stu\c++_note\picture\image-20241031173502836.png)

![image-20241031173927177](D:\code\study\notes_stu\c++_note\picture\image-20241031173927177.png)

**网页资源的跳转** html

![image-20241031174238146](D:\code\study\notes_stu\c++_note\picture\image-20241031174238146.png)

![image-20241031174403344](D:\code\study\notes_stu\c++_note\picture\image-20241031174403344.png)

![image-20241031174710905](D:\code\study\notes_stu\c++_note\picture\image-20241031174710905.png)

**复用端口**

# http细节字段

![image-20241031175408562](D:\code\study\notes_stu\c++_note\picture\image-20241031175408562.png)

表单

![image-20241031195117769](D:\code\study\notes_stu\c++_note\picture\image-20241031195117769.png)

通过表单来获取数据

![image-20241031195233081](D:\code\study\notes_stu\c++_note\picture\image-20241031195233081.png)

**提交到给谁**   get方法是通过url来执行的

![image-20241031195956330](D:\code\study\notes_stu\c++_note\picture\image-20241031195956330.png)

**如果是程序就可以通过程序替换来执行，管道通信进行信息通信**

![image-20241101094545976](D:\code\study\notes_stu\c++_note\picture\image-20241101094545976.png)

安全不安全是加密来说的，get方法跟post方法都不安全，get方法不私密因为可以通过url看出来

![image-20241101095403351](D:\code\study\notes_stu\c++_note\picture\image-20241101095403351.png)

### 重定向状态码

![image-20241101102057291](D:\code\study\notes_stu\c++_note\picture\image-20241101102057291.png)

#### 永久重定向，临时重定向

![image-20241101102513603](D:\code\study\notes_stu\c++_note\picture\image-20241101102513603.png)

# Http属性

![image-20241101103812926](D:\code\study\notes_stu\c++_note\picture\image-20241101103812926.png)

![image-20241101155043828](D:\code\study\notes_stu\c++_note\picture\image-20241101155043828.png)

![image-20241101155144516](D:\code\study\notes_stu\c++_note\picture\image-20241101155144516.png)

是否支持长连接  

若干次请求的回复

![image-20241101160319422](D:\code\study\notes_stu\c++_note\picture\image-20241101160319422.png)

![image-20241101160410610](D:\code\study\notes_stu\c++_note\picture\image-20241101160410610.png)

content-type 用来显示你的正文是什么类型的正文，对于图片的二进制数据，就需要显式的告诉content-type

![image-20241101160923634](D:\code\study\notes_stu\c++_note\picture\image-20241101160923634.png)

![image-20241101161623290](D:\code\study\notes_stu\c++_note\picture\image-20241101161623290.png)

二进制读取文件

![image-20241101162941675](D:\code\study\notes_stu\c++_note\picture\image-20241101162941675.png)

### cookie

![image-20241101164618540](D:\code\study\notes_stu\c++_note\picture\image-20241101164618540.png)

![image-20241101170323466](D:\code\study\notes_stu\c++_note\picture\image-20241101170323466.png)

![image-20241101170344255](D:\code\study\notes_stu\c++_note\picture\image-20241101170344255.png)

## cookie

![image-20241118155615950](D:\code\study\notes_stu\c++_note\picture\image-20241118155615950.png)

![image-20241118160429577](D:\code\study\notes_stu\c++_note\picture\image-20241118160429577.png)

![image-20241118160516331](D:\code\study\notes_stu\c++_note\picture\image-20241118160516331.png)

## session文件

![image-20241118162038079](D:\code\study\notes_stu\c++_note\picture\image-20241118162038079.png)

对session验证，拿出相对应的cookie，用来保护用户的cookie信息，拿不到更多的私密信息

seesion id是服务端统一管理的

# Http

http的请求都是明文的，不管是通过url还是post正文传送，都是可以看到的，https就是通过加密的信息传输协议
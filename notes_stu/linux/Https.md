![image-20241118163232990](D:\code\study\notes_stu\c++_note\picture\image-20241118163232990.png)

加密

# Https

![image-20241118170421674](D:\code\study\notes_stu\c++_note\picture\image-20241118170421674.png)

![image-20241118170708798](D:\code\study\notes_stu\c++_note\picture\image-20241118170708798.png)

## 中间人攻击

![image-20241118170936846](D:\code\study\notes_stu\c++_note\picture\image-20241118170936846.png)

![image-20241118171056014](D:\code\study\notes_stu\c++_note\picture\image-20241118171056014.png)

**http的正文会在被明文传输的过程中被更改，导致内容被改变**

## 加密方式

对称加密，非对称加密

![image-20241118172151467](D:\code\study\notes_stu\c++_note\picture\image-20241118172151467.png)

## 数字签名

![image-20241118172604836](D:\code\study\notes_stu\c++_note\picture\image-20241118172604836.png)

![image-20241118173044605](D:\code\study\notes_stu\c++_note\picture\image-20241118173044605.png)

![image-20241118173258346](D:\code\study\notes_stu\c++_note\picture\image-20241118173258346.png)

**session id 的唯一性 数据摘要**

### 百度网盘秒传

**很多用户上传的资源是一样的 也就是说数据摘要是一样的，对于这样的文件就没有必要再次上传**

![image-20241118173857984](D:\code\study\notes_stu\c++_note\picture\image-20241118173857984.png)

## 客户端服务器通信加密

对于只使用对称加密是无法使用的

![image-20241118175235808](D:\code\study\notes_stu\c++_note\picture\image-20241118175235808.png)

这样从服务器到客户端已经是安全的

![image-20241118195518618](D:\code\study\notes_stu\c++_note\picture\image-20241118195518618.png)

![image-20241118195657834](D:\code\study\notes_stu\c++_note\picture\image-20241118195657834.png)

![image-20241118200019414](D:\code\study\notes_stu\c++_note\picture\image-20241118200019414.png)

MITM攻击

![image-20241118200312970](D:\code\study\notes_stu\c++_note\picture\image-20241118200312970.png)

![image-20241118201610079](D:\code\study\notes_stu\c++_note\picture\image-20241118201610079.png)



**客户端无法验证公钥的合法性**

## 证书

![image-20241119163047664](D:\code\study\notes_stu\c++_note\picture\image-20241119163047664.png)

![image-20241119164437355](D:\code\study\notes_stu\c++_note\picture\image-20241119164437355.png)

![image-20241119165013318](D:\code\study\notes_stu\c++_note\picture\image-20241119165013318.png)

由于证书对于证书数据的验证是使用的CA机构的私钥，中间人就算知道公钥对数据进行解密，但是无法对其使用**CA机构的私钥**进行加密，那也就是说，中间人无法对数据进行更改，就算更改后，客户端也能对这个证书的数据进行正确的验证，**这些权威机构的CA公钥会在客户端里存储的，你的电脑出厂的时候就会内置**也就是公开密钥

同时如果中间人将证书给换掉了，也是真的证书，但是证书中是有域名等相关信息的，域名信息匹配不上，这样也会去验证证书是否正确

还有假网站作为中间人，代替去访问真的网站，这种情况无法验证，因为你访问的就是假网站（很像），

![image-20241119174126754](D:\code\study\notes_stu\c++_note\picture\image-20241119174126754.png)

![image-20241119174409415](D:\code\study\notes_stu\c++_note\picture\image-20241119174409415.png)

![image-20241119175935023](D:\code\study\notes_stu\c++_note\picture\image-20241119175935023.png)

![image-20241119180042695](D:\code\study\notes_stu\c++_note\picture\image-20241119180042695.png)

![image-20241119180424941](D:\code\study\notes_stu\c++_note\picture\image-20241119180424941.png)

![image-20241119180804434](D:\code\study\notes_stu\c++_note\picture\image-20241119180804434.png)

![image-20241119181247449](D:\code\study\notes_stu\c++_note\picture\image-20241119181247449.png)
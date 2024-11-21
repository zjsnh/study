# MySQL用户管理

![image-20241119104111453](D:\code\study\notes_stu\c++_note\picture\image-20241119104111453.png)

![image-20241119104527264](D:\code\study\notes_stu\c++_note\picture\image-20241119104527264.png)

![image-20241119105650336](D:\code\study\notes_stu\c++_note\picture\image-20241119105650336.png)

但是当前用户无法进行远程登录

![image-20241119105818577](D:\code\study\notes_stu\c++_note\picture\image-20241119105818577.png)

![image-20241119110003135](D:\code\study\notes_stu\c++_note\picture\image-20241119110003135.png)

%表示用户可以在任意主机上登录，但是一般严格不允许这样做

![image-20241119110036132](D:\code\study\notes_stu\c++_note\picture\image-20241119110036132.png)

```mysql
flush privileges
```

刷新权限

mysql对应的端口号万万不能出现在公网上

![image-20241119110503324](D:\code\study\notes_stu\c++_note\picture\image-20241119110503324.png)

这些修改密码的操作就是对user表进行插入删除修改操作

![image-20241119110856025](D:\code\study\notes_stu\c++_note\picture\image-20241119110856025.png)

使用updata进行修改也可以

## 数据库权限

![image-20241119111339573](D:\code\study\notes_stu\c++_note\picture\image-20241119111339573.png)

![image-20241119111356726](D:\code\study\notes_stu\c++_note\picture\image-20241119111356726.png)

![image-20241119111612875](D:\code\study\notes_stu\c++_note\picture\image-20241119111612875.png)

![image-20241119111658836](D:\code\study\notes_stu\c++_note\picture\image-20241119111658836.png)

![image-20241119111715457](D:\code\study\notes_stu\c++_note\picture\image-20241119111715457.png)

赋予用户权限

### 查看用户权限

![image-20241119111808879](D:\code\study\notes_stu\c++_note\picture\image-20241119111808879.png)

### 回收权限

![image-20241119112018096](D:\code\study\notes_stu\c++_note\picture\image-20241119112018096.png)

![image-20241119112031318](D:\code\study\notes_stu\c++_note\picture\image-20241119112031318.png)

![image-20241119112326604](D:\code\study\notes_stu\c++_note\picture\image-20241119112326604.png)

给予只读权限


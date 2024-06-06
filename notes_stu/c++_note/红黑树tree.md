# 红黑树

![image-20240603164513944](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603164513944.png)

![image-20240603170645308](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603170645308.png)

## 路径是根节点走到空

![image-20240603170656552](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603170656552.png)

![image-20240603172834585](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603172834585.png)

新增插入红色

![image-20240603173735629](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603173735629.png)

# 新增处理

![image-20240603173918143](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603173918143.png)

旋转  变色

![image-20240603174837800](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603174837800.png)

![image-20240603180714669](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240603180714669.png)

  ![image-20240604145252466](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240604145252466.png)

 

```C++
// 根节点->当前节点这条路径的黑色节点的数量
bool Check(Node* root, int blacknum, const int refVal)
{
    if (root == nullptr)
    {
        //cout << balcknum << endl;
        if (blacknum != refVal)
        {
            cout << "存在黑色节点数量不相等的路径" << endl;
            return false;
        }

        return true;
    }

    if (root->_col == RED && root->_parent->_col == RED)
    {
        cout << "有连续的红色节点" << endl;

        return false;
    }

    if (root->_col == BLACK)
    {
        ++blacknum;
    }

    return Check(root->_left, blacknum, refVal)
        && Check(root->_right, blacknum, refVal);
}

bool IsBalance()
{
    if (_root == nullptr)
        return true;

    if (_root->_col == RED)
        return false;

    //参考值
    int refVal = 0;
    Node* cur = _root;
    while (cur)
    {
        if (cur->_col == BLACK)
        {
            ++refVal;
        }

        cur = cur->_left;
    }

    int blacknum = 0;
    return Check(_root, blacknum, refVal);
}
```

set

![image-20240604202800968](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240604202800968.png)

![image-20240604202837267](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240604202837267.png)

typeid  取变量的类型

![image-20240604204057061](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240604204057061.png)

# 带模板参数的构造

![image-20240605213604369](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240605213604369.png)

进行构造的同时，也可以进行不同类型之间的转换

```C++
iterator  const_iterator//之间的转化
```

<img src="C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240605213753377.png" alt="image-20240605213753377" style="zoom:150%;" />

![image-20240605213902491](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240605213902491.png)

![image-20240605220339561](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240605220339561.png)

![image-20240605220356108](C:\Users\30780\AppData\Roaming\Typora\typora-user-images\image-20240605220356108.png)

//username=zhangsan; password=123456

#include <iostream>
#include <unordered_map>
#include <string>

std::string UserName(std::string str)
{
    std::unordered_map<std::string, std::string> cookies;
    std::string cookie = str;

    std::cout << cookie << std::endl;

    size_t pos = 0, idx = 0;
    std::string sep = ";";
    while (true)
    {
        pos = cookie.find(";", idx);
        if (pos == std::string::npos)
            break;

        std::string _str = cookie.substr(idx, pos);
        size_t pos_ = _str.find("=");
        cookies[_str.substr(0, pos_)] = _str.substr(pos_ + 1);

        cookie = cookie.substr(pos + 2);
    }
    if (cookie.empty() == false)
    {
        size_t pos_ = cookie.find("=");
        cookies[cookie.substr(0, pos_)] = cookie.substr(pos_ + 1);
    }

    return cookies["username"];
}

int main()
{
    UserName("username=zhangsan; password=123456");
    return 0;
}
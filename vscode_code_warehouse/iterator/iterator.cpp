#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s("hello world");

    string::iterator it=s.begin();
    while(it!=s.end())
    {
        if(*it==' ')
        {
            s.replace(it,it+1,1,'*');
        }
        ++it;

    }
    cout<<s<<endl;

    getchar();

    return 0;
}
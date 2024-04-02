#include<iostream>
#include<stdlib.h>
using namespace std;


typedef struct Array
{
    int *a;
    int size;
}AY;

int& text(AY&ay,int n)
{
    return ay.a[n];
}

int main()
{
    AY ay;
    ay.size=10;
    ay.a=(int*)calloc(sizeof(int),ay.size);

    for(int i=0;i<ay.size;++i)
    {
        ay.a[i]=10*i+1;
    }

    

    for(int i=0;i<ay.size;++i)
    {
        cout<<text(ay,i)<<endl;
    }

    free(ay.a);
    system("pause");
    return 0;
}
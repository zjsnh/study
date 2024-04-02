#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

// void CreateData(void)
// {
//     int n=10000;
//     srand(time(0));
//     const char* filename="data.txt";
//     FILE* fp=fopen(filename,"w");
//     if(fp==NULL)
//     {
//         perror("fopen,error");
//         return ;
//     }

//     for(int i=0;i<n;i++)
//     {
//         int x=rand()%100000;
//         fprintf(fp,"%d\n",x);
//     }

//     fclose(fp);
// }

void adjust_down(int *a,int n,int i)
{
    int parent=i;
    int child=2*i+1;
    while(child<n)
    {
        if(child+1<n&&a[child]>a[child+1])
        {
            child++;
        }

        if(a[parent]>a[child])
        {
            swap(a[parent],a[child]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }

}

void TopK_sort(int* TopK,int n)
{
    const char* filename="data.txt";
    FILE* fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("fopen,error");
        return ;
    }

    int x;
    while(fscanf(fp,"%d",&x)!=EOF)
    {
        TopK[n++]=x;
        adjust_down(TopK,n,n-1);
    }

    for(int i=(n-2)/2;i>=0;i--)
    {
        adjust_down(TopK,n,i);
    }

    for(int i=n;i<10000;i++)
    {
        int x;
        fscanf(fp,"%d",&x);
        if(TopK[0]<x)
        {
            TopK[0]=x;
            adjust_down(TopK,n,0);
        }
    }


}


int main()
{
    int n=10;
    int *TopK=new int[n];
    
    // CreateData();
    TopK_sort(TopK,n);
    for(int i=0;i<n;i++)
    {
        cout<<TopK[i]<<" ";
    }

    return 0;
}
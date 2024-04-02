#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void adjust_down(int *arr, int n, int i)
{
    int child = 2 * i + 1;
    int parent = i;
    while(child<n)
    {
        if(child+1<n && arr[child]<arr[child+1])
        {
            ++child;
        }

        if(arr[parent]<arr[child])
        {
            swap(arr[parent], arr[child]);
            parent = child; 
            child = 2 * child + 1;
        }
        else{
            break;
        }
    }
}

void Heap_sort(int *arr, int n)
{
    for(int i=(n-2)/2;i>=0;--i)
    {
        adjust_down(arr,n,i);
    }

    while(n>0)
    {
        swap(arr[0], arr[--n]);
        adjust_down(arr, n, 0);
    } 

}

int main()
{
    int arr[10] = {4, 3, 2, 5, 6, 7, 8, 9, 1 ,0} ;
    int n = sizeof(arr)/sizeof(arr[0]);

    Heap_sort(arr,n);

    for(int i=0;i<n;++i)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
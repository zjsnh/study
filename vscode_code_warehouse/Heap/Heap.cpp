#include"Heap.h"

void Init_Hp(Hp* hp)
{
    assert(hp);
    hp->size = 0;
    hp->capacity=0;
    hp->a=NULL;
}

int capacity(Hp* hp)
{
    if(hp->capacity==0)
    {
        hp->capacity=4;
    }
    else{
        hp->capacity=2*hp->capacity;
    }
    return hp->capacity;
}

void Push_Hp(Hp* hp, ElementType a)
{
    if (hp->size == hp->capacity)
    {
        hp->capacity = capacity(hp);
        ElementType* temp = (ElementType*)realloc(hp->a, sizeof(ElementType) * hp->capacity);
        if (temp == NULL)
        {
            perror("realloc temp");
            return;
        }
        hp->a = temp;
    }

    hp->a[hp->size] = a;
    hp->size++;
    adjust_up(hp, hp->size);
}

ElementType Pop_Hp(Hp* hp)
{
    assert(hp);
    assert(hp->size>0);
    ElementType a=hp->a[1];
    hp->a[1]=hp->a[hp->size--];
    adjust_down(hp,0,hp->size);
    return a;
}

void Print_Hp(Hp* hp)
{
    for(int i=1;i<=hp->size;i++)
    {
        printf("%d ",hp->a[i]);
        printf("\n");
    }
}

void adjust_up(Hp* hp,int i)
{
    while(i>0) 
    {
        if(hp->a[i]<hp->a[(i-1)/2])
        {
            swap(hp->a[i],hp->a[(i-1)/2]);
            i=(i-1)/2;
        }
        else{
            break;
        }
        
    }
}

void adjust_down(Hp* hp,int i,int size)
{
    while(2*i+1<=size)
    {
        int j=2*i+2;
        if(j<size&&hp->a[j]<hp->a[j+1])
        {
            j++;
        }
        if(hp->a[i]<hp->a[j])
        {
            swap(hp->a[i],hp->a[j]);
            i=j;
        }
        else{
            break;
        }
    }

}
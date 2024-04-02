#include<iostream>
#include<assert.h>
using namespace std;

typedef int ElementType;

typedef struct heap_node
{
    ElementType* a;
    int size;
    int capacity;
}Hp;

void Init_Hp(Hp* hp);

void Push_Hp(Hp*hp,ElementType a);

ElementType Pop_Hp(Hp* hp);

void Print_Hp(Hp* hp);

void adjust_up(Hp* hp,int i);

void adjust_down(Hp* hp,int i,int size);


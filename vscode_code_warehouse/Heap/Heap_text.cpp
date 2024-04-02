#include"Heap.h"

int main()
{
    Hp hp;
    Init_Hp(&hp);
    

    ElementType arr[] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; ++i)
    {
        Push_Hp(&hp, arr[i]);

    }

    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", Pop_Hp(&hp));
    }

    printf("\n");
    return 0;

}
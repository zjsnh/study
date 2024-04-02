#include<iostream>
#include<assert.h>
using namespace std;

#define N 10

typedef struct Arrey
{
	int data[N];
	int size;
}AY; 

int& PosAt(AY& a, int i)
{
	assert(i < N); 

	return a.data[i];
}
int main()
{
	AY at;
	for(int i=0;i<N;i++)
	{
		at.data[i]=i+1;
	};

	for(int i=0;i<N;i++)
	{
		cout<<PosAt(at,i)<<endl;
	}
	return 0;
}
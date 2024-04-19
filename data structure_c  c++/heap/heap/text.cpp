#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//int main()
//{
//	Heap h;
//	h.Push(7);
//	h.Push(8);
//	h.Push(5);
//	h.Push(3);
//	h.Push(4);
//	h.Push(1);
//	h.Push(2);
//
//
//	cout << h;
//
//	return 0;
//}

void data()
{
	FILE* fp = fopen("data.txt", "w+");
	if (fp == nullptr)
	{
		perror("foprn");
		exit(-1);
	}

	for (int i = 0; i < 10000; i++)
	{
		int d = rand() % 100000;
		fprintf(fp, "%d\n", d);
	}

	fclose(fp);
}


void top_k()
{
	Heap top;

	FILE* fp= fopen("data.txt", "r+");

	/*int ch1 = 0;*/
	int ch = 0;
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d ", &ch);
		/*ch1 = fgetc(fp);*/

		/*printf("%d %d\n", ch1,ch2);*///¶ÁµÄÊÇ¿Õ°××Ö·û
		top.Push(ch);
	}

	int flag = 0;

	while ((flag=fscanf(fp, "%d ", &ch))==1)
	{
		top.TopPush(ch);
	}

	cout << top;

	fclose(fp);

}


int main()
{
	srand((unsigned int)time(nullptr));
	/*data();*/

	top_k();

	return 0;
}
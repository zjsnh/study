#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main()
{
	FILE* fp = fopen("text.txt", "w");
	if (fp == NULL)
	{
		perror("fopen");
		return 1;
	}

	fprintf(fp, "hello world");

	fclose(fp);


	return 0;
}
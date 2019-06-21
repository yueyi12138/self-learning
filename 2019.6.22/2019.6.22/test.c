#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<ctype.h>
//memcpy ÄÚ´æ¿½±´º¯Êý
void*Memcpy(void *dest, const void *src, int count)
{
	void *ret = dest;
	while (count--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)++;
	}
	return ret;
}
int main()
{
	//int arr1[20] = { 0 };
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	memcpy(arr + 2, arr, 16);
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void Sumk(int *arr, int len, int *num1, int *num2,int k)
{
	int i = 0;
	int j = len - 1;
	while (i < j)
	{
		if ((arr[i] + arr[j]) < k)
		{
			i++;
		}
		else if ((arr[i] + arr[j])>k)
		{
			j--;
		}
		else
		{
			*num1 = i;
			*num2 = j;
			break;
		}
	}
}
int main()
{
	int arr[] = { 1, 3, 4, 5, 9, 10, 11 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = -1;
	int j = -1;
	Sumk(arr,len,)
	return 0;
}

#if 0
int MyPow(int x, int y)
{
	int tmp = 0;
	int result = 0;
	if (y = 1)
	{
		return x;
	}
	tmp = MyPow(x, y / 2);
	if (y & 1 == 0)
	{
		result = tmp*tmp;
	}
	else
	{
		result = x*tmp*tmp;
	}
	return result;
}
int main()
{

	return 0;
}


int isPalind(int num)
{
	int newNum = 0;
	int num2 = num;
	while (num != 0)
	{
		newNum = newNum * 10 + num % 10;
		num /= 10;
	}
	if (newNum == num2)
	{

	}

}

int main()
{

	return 0£»
}
#endif
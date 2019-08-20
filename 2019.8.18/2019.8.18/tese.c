#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *DeleteRepeateChar(char * str1, char *str2)
{
	char *p = str1;
	char *q = str1;
	char arr[256] = { 0 };
	while (*str2 != '\0')
	{
		arr[*str2]++;
		str2++;
	}
	
	while (*p!='\0')
	{
		if (arr[*p]!=1)
		{
			//没出现过
			*q++ = *p;
		}
		p++;
	}
	*q = '\0';
	return str1;
}
int main()
{
	char str[] = "Welcome to cvte";
	char *str2 = "come";
	printf("%s\n", DeleteRepeateChar(str,str2));
	return 0;
}

#if 0
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);
	return 0;
}


char FindOnceChar(char *str)
{   //遍历字符串，统计每个字符出现的次数
	int arr[256] = { 0 };
	char *p = str;
	while (*p != '\0')
	{
		arr[*p]++;
		p++;
	}
	//查找第一个出现一次的字符
	p = str;
	while (*p != '\0')
	{
		if (arr[*p] == 1)
		{
			return *p;
		}
		p++;
	}
	return '\0';
}
int main()
{
	/*char str = "abaccdeff";
	char p = FindOnceChar(str);*/
	printf("%c\n", FindOnceChar("bacc"));
	printf("%c\n", FindOnceChar("aabcdcd"));
	printf("%c\n", FindOnceChar("bbaacc"));
	return 0;
}


int MaxArray2(int *arr, int len)//时间复杂度O(n)
{
	int sum = arr[0];
	int max = arr[0];
	int i = 1;
	for (i = 1; i < len; i++)
	{
		if (sum < 0)
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];//4 8 9 5 -1 10 -2
		}
		if (sum>max)
		{
			max = sum;
		}
	}
	return max;
}
int MaxArray(int *arr, int len)  //时间复杂度O(n^2)
{
	if (arr == NULL&&len < 0)
	{
		return -1;
	}
	int maxNum = 0x80000000;
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j<len; j ++)
		{
			sum += arr[j];
			if (sum>=maxNum)
			{
			maxNum = sum ;
			}
		}
	}
	return maxNum;
}


int main()
{
	//int arr[] = { 4, 8, 9, 5, -1, 10, -2 };
	int arr[] = { 1, 2, 3, -1, 4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	MaxArray(arr, len);
	int ret = MaxArray(arr, len);
	printf("%d\n", ret);
	printf("%d\n", MaxArray2(arr, len));
	return 0;
}
#endif

#if 0
int fun(char* s)
{
	char*p = s;
	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}
int main()
{
	printf("%d\n", fun("goodbye!"));
	return 0;
}

int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	return 0;
}

int main()
{
	int i = 1;
	printf("%d, %d\n", sizeof(i++), i);
	return 0;
}


char *mystring()//不能返回一个数组，在char*mystring（）结束之后 栈会自动销毁
{char buffer[6] = { 0 };
	char * s = "Hello World!";
	for (int i = 0; i < (sizeof(buffer)-1); i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	printf("%s\n",mystring());
	return 0;
}


int main()
{
	int x[] = { 1, 2, 3, 4, 5, 6 };
	int *p = x;
	//printf("%d,%d\n", *(p += 2),*++p);
	//printf("%d,%d\n", *(p += 2), *p++);
	//printf("%d,%d\n", *(p += 3), *p);
	printf("%d,%d\n", *(p += 2), ++*p);
	return 0;
}

int main()
{
	char *str[3] = { "stra","strb","strc" };
	char *p = str[0];
	int i = 0;
	while (i < 3)
	{
		printf("%s ", p++);
		i++;
	}
	return 0;
}


int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)(&a + 1);
	int *p2 = (int *)((int)a + 1);
	int *p3 = (int*)(a + 1);
	printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);
	return 0;
}
#endif

#if 0//求数组前k个最小的数字
int Partion(int arr[],int left,int right)
{
	int tmp = arr[left];
	while (left < right)
	{
		while (left<right&&arr[right]>=tmp)
		{
			right--;
		}
		if (left >= right)
		{
			arr[left] = tmp;
			break;
		}
		else
		{
			arr[left] = arr[right];
		}
		while (left < right&&arr[left] <= tmp)
		{
			left++;
		}
		if (left >= right)
		{
			break;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	arr[left] = tmp;
	return left;
}
void PreKNum(int *arr,int len,int k)
{
	int left = 0;
	int right = len - 1;
	int par = Partion(arr,left, right);
	int i = 0;
	while (par != k - 1)
	{
		if (par > k - 1)
		{
			right = par - 1;
			par= Partion(arr, left,right);
		}
		else
		{
			left = par + 1;
			par = Partion(arr, left, right);
		}
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 12, 3, 5, 17, 0, 7 ,14,8,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	PreKNum(arr, len ,5);
	return 0;
}
#endif
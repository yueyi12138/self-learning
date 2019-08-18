#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++;
	b++;
	return(a);
}
int main()
{
	int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k=f(a++);
	}
	printf("%d\n", k);
	return 0;
}


#if 0
int Fabionacio(int n)//1 1 2 3 5 8 13 21 34
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 1;
	int i = 3;
	for (i = 3; i <= n; i++)
	{
		f3 = f1+ f2 ;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	printf("%d\n",Fabionacio(1));
	printf("%d\n", Fabionacio(2));
	printf("%d\n", Fabionacio(3));
	printf("%d\n", Fabionacio(4));
	system("pause");
	return 0;
}



void Move(char pos1,char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
void Hanota(int n, char pos1, char pos2, char pos3)
{
	//终止条件
	if (n == 1)
	{
		printf("%c->%c ", pos1, pos3);
	}
	else
	{
		Hanota(n - 1, pos1, pos3, pos2);
		printf("%c->%c ", pos1, pos3);
		Hanota(n - 1, pos2, pos3, pos1);
	}
	//递归调用
}
int main()
{
	Hanota(1,'A','B','C');
	printf("\n");
	Hanota(2, 'A', 'B', 'C');
	printf("\n");
	Hanota(3, 'A', 'B', 'C');
	printf("\n");
	system("pause");
	return 0;
}



int JumpFloor(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return n;
	}
	else
	{
		return JumpFloor(n - 1) + JumpFloor(n - 2);
	}
}
int main()
{
	printf("n：%d\n", JumpFloor(4));
	system("pause");
	return 0;
}


void ReplaceBlank(char *str, int length)
{
	int len = length;
	int i = 0;
	int NumberBlank = 0;
	if (str == NULL || length <= 0)
	{
		return;
	}
	for (; i <len ;i++)//求空格个数
	{
		if (str[i] == ' ')
		{
			NumberBlank++;
		}
    }
	int newlength = length + NumberBlank * 2;
	int origina_index = length - 1;
	int new_index = newlength - 1;
	while (origina_index > 0 && new_index > origina_index)
	{
		if (str[origina_index] == ' ')
		{
			str[new_index--] = '0';
			str[new_index--] = '2';
			str[new_index--] = '%';
		}
		else
		{
			str[new_index--] = str[origina_index];
		}
		origina_index--;
	}
}
int main()
{
	char str[30] = "abc de f";
	int length = strlen(str) + 1;
	int i = 0;
	int j = 0;
	for (; i < length; i++)
		printf("%c", str[i]);
		printf("\n");
		ReplaceBlank(str, length);
	int newlength = sizeof(str);
	for (; j < newlength; j++)
		printf("%c", str[j]);
		printf("\n");
	system("pause");
	return 0;
}


#define ROW 5
void Func2(int arr[][ROW])
{
	int tmpRow = 0;
	int tmpCol = ROW / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	//2-n^2
	for (i = 2; i <= ROW*ROW; i++)
	{
		//说明上一行 下一列是有数据的
		if (arr[(tmpRow - 1 + ROW) % ROW][(tmpCol + 1) % ROW] != 0)
		{
			//改变行坐标  列不发生改变
			tmpRow = (tmpRow + 1) % ROW;
		}
		else
		{
			tmpRow = (tmpRow - 1 + ROW) % ROW;
			tmpCol = (tmpCol + 1) % ROW;
		}
		//上面语句执行完成之后确定了数字的坐标
		arr[tmpRow][tmpCol] = i;
	}
}
void Show(int arr[][ROW])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < ROW;j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[ROW][ROW] = {0};
	Func2(arr);
	Show(arr);
	system("pause");
	return 0;
}



void Fnid_val(int *arr, int row, int col, int key,int *px,int *py)
{
	int tmpRow = 0;
	int tmpCol = col - 1;

	while (tmpRow < row&&tmpCol >= 0)
	{
		if (arr[tmpRow*col + tmpCol] == key)
		{
			*px = tmpRow;
			*py = tmpCol;
			break;
		}
		else if (arr[tmpRow*col + tmpCol] > key)
		{
			tmpCol --;
		}
		else
		{
			tmpRow++;
		}
	}
}

int main()
{
	//0,3
	int arr[4][4] = { 1, 2, 8, 9,
							2, 4, 9, 12,
							4, 7, 10, 13,
							6, 8, 11, 15 };
	int x = -1;
	int y = -1;
	Fnid_val((int*)arr, 4, 4,7,&x,&y);
	printf("%d,%d\n", x, y);
	system("pause");
	return 0;
}
#endif
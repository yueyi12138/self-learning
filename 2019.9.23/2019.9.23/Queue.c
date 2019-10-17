#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include"Queue.h"
#include<malloc.h>

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (q)
	{
		QueueNode*next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, DateType x)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	//判断是否为第一个插入的元素
	if (q->_front == NULL)
	{
		q->_front = q->_rear = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		//删除出队
		free(q->_front);
		q->_front =next;
		//删除的为最后一个元素
		if (q->_front == NULL)
		{
			q->_rear = NULL;
		}
	}
}

//获取队头元素
DateType QueueFront(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		return q->_front->_data;
	}
	return -1;
}

//获取队尾元素
DateType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->_front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Queueize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		++n;
		cur = cur->_next;
	}
	return n;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void testQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePrint(&q);
	/*QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);
	QueuePop(&q);
	QueuePrint(&q);*/
	QueueDestroy(&q);
}
int main()
{
	testQueue();
	return 0;
}


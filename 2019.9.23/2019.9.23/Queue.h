#define _CRT_SECURE_NO_WARNINGS
typedef int DateType;
typedef struct QueueNode
{
	DateType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q,DateType x);
void QueuePop(Queue* q);
//获取队头元素
DateType QueueFront(Queue* q);
DateType QueueBack(Queue* q);
int QueueEmpty(Queue* q);
int Queueize(Queue* q);
void QueuePrint(Queue* q);




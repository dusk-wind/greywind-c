#include <stdio.h>
#define ElemType int
typedef struct queue
{
    int front;
    int rear;
    int maxSize;
    ElemType *element;
}Queue;
void create(Queue *Q,int mSize)
{
    Q->maxSize=mSize;
    Q->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
    Q->front=Q->rear=0;
}
void Destroy(Queue *Q)
{
    Q->maxSize=0;
    free(Q->element);
    Q->front=Q->rear=-1;
}
int BOOLIsEmpty(Queue *Q)
{
    return Q->front==Q->rear;
}
int BOOLIsFULL(Queue*Q)
{
    return (Q->rear+1)%Q->maxSize==Q->front;
}
int BOOLEnQueue(Queue *Q,ElemType x)
{
    if(BOOLIsFULL(Q))
        return 0;
    Q->rear=(Q->rear+1)%Q->maxSize;
    Q->element[Q->rear]=x;
    return 1;
}
int BOOLDeQueue(Queue *Q)
{
    if(IsEmpty(Q))
        return 0;
    Q->front=(Q->front+1)%Q->maxSize;
        return 1;
}
void Clear(Queue *Q)
{
    Q->front=Q->rear=0;
}



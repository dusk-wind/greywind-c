typedef struct queue
{
    int front;
    int rear;
    int maxSize;
    int *element;
}Queue;

void create(Queue *Q,int mSize)
{
    Q->maxSize=mSize;
    Q->element=(int*)malloc(sizeof(int)*mSize);
    Q->front=Q->rear=0;
}

void Destroy(Queue *Q)
{
    Q->maxSize=0;
    free(Q->element);
    Q->front=Q->rear=-1;
}

BOOL IsEmpty(Queue *Q)
{
    return Q->front==Q->rear;
}

BOOL IsFULL(Queue *Q)
{
    return (Q->rear+1)%Q->maxSize==Q->front
}

BOOL EnQueue(Queue *Q,int x)
{
    if(IsFULL(Q))
        return FALSE;
    Q->rear=(Q->rear+1)%Q->maxSize;
    Q->element[Q->rear]=x;
    return TRUE;
}

BOOL DeQueue(Queue *Q)
{
    if(IsEmpty(Q))
        return FALSE;
    Q->front=(Q->front+1)%Q->maxSize;
    return TRUE;
}

void Clear(Queue *Q)
{
    Q->front=Q->rear=0;
}
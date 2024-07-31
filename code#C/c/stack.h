#define TRUE 1
#define FALSE 0
#include <stdbool.h>

typedef double ElemType;
typedef struct stack
{
    int top;
    int maxSize;
    ElemType *element;
}Stack;

void Creat(Stack *S,int mSize)
{
    S->maxSize=mSize;
    S->element=(ElemType*)malloc(sizeof(ElemType)*mSize);
    S->top=-1;
}

void Destroy(Stack *S)
{
    S->maxSize=0;
    free(S->element);
    S->top=-1;
}

BOOL IsEmpty(Stack *S)
{
    return S->top==-1;
}

BOOL IsFull(Stack *S)
{
    return S->top==S->maxSize-1;
}

BOOL Top(Stack *S,ElemType *x)
{
    if(IsEmpty(S))
        return FAlSE;
    *x=S->element[S->top];
    return TRUE;
}

BOOL Push(Stack *S,ElemType *x)
{
    if(IsFull(S))
        return FALSE;
    S->top++;
    S->element[S->top]=x;
    return TRUE;
}

BOOL Pop(Stack *S)
{
    if(IsEmpty(S))
        return FALSE;
    S->top--;
    return TRUE;
}

void Clear(Stack *S)
{
    s->top=-1;
}
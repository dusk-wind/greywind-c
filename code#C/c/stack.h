#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define FALSE 0
#define TRUE 1
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

int BOOLIsEmpty(Stack *S)
{
    return S->top==-1;
}

int BOOLIsFull(Stack *S)
{
    return S->top==S->maxSize-1;
}

int BOOLTop(Stack *S,ElemType *x)
{
    if(BOOLIsEmpty(S))
        return FAlSE;
    *x=S->element[S->top];
    return TRUE;
}

char BOOLPush(Stack *S,ElemType *x)
{
    if(BOOLIsFull(S))
        return 0;
    S->top++;
    S->element[S->top]=x;
    return 1;
}

int BOOLPop(Stack *S)
{
    if(BOOLIsEmpty(S))
        return FALSE;
    S->top--;
    return TRUE;
}

void Clear(Stack *S)
{
    S->top=-1;
}
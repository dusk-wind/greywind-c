#include <stdio.h>
typedef struct stack
#define ElemType int
{
    int top;
    int maxSize;
    ElemType *element;
}Stack;
void Create(Stack *S,int mSize)
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
int BOOLIsFULL(Stack *S)
{
    return S->top==S->maxSize-1;
}
//获取栈顶元素
int BOOLTop(Stack *S,ElemType *x)
{
    if(IsEmpty(S))
        return 0;
    *x=S->element[S->top];
    return 1;
}
//入栈操作
int BOOLPush(Stack *S,ElemType x)
{
    if(IsFull(S))
        return 0;
    S->top++;
    S->element[S->top]=x;
    return 1;
}
//出栈操作
int BOOLPop(Stack *S)
{
    if (IsEmpty(S))
       return 0;
    S->top--;
    return 1;
}
void Clear(Stack *S)
{
    S->top=-1;
}
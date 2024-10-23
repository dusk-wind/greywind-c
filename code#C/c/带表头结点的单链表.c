#define ERROR 0
#define OK 1
#include <stdio.h>

typedef int ElemType;
typedef int Status;

typedef struct node
{
    ElemType element;
    struct node *link;
}Node;

typedef struct headerList
{
    Node *first;   // 删了报错
    Node *head;
    int n;
}HeaderList;

Status Init(HeaderList *h)
{
    h->head=(Node*)malloc(sizeof(Node));
    if(!h->head)
        return ERROR;
    h->head->link = NULL;
    h->n=0;
    return OK;
}

Status Insert(HeaderList *h,int i,ElemType x)
{
    Node *p,*q;
    int j;
    if(i<-1 || i > h->n-1)
        return ERROR;
    p=h->head;
    for(j=0;j<=i;j++)
        p=p->link;
    q=(Node*)malloc(sizeof(Node));
    q->element=x;
    q->link=p->link;
    p->link=q;
    h->n++;
    return OK;
}

Status Delete (HeaderList *h,int i)
{
    int j;
    Node *p,*q;
    if(!h->n)
        return ERROR;
    if(i<0 || i > h->n-1)
        return ERROR;
    q=h->first;
    for (j=0;j<i;j++)
        q=q->link;
    p=q->link;
    q->link=p->link;
    free(p);
    h->n--;
    return OK;
}



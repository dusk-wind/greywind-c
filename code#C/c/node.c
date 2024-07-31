#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1;
#define ERROR 0;
typedef int Status;
typedef struct node
{
    int element; //数据域
    struct node *link; //指针域
}Node;
typedef struct singleList
{
    Node *first;
    int n;
}SingleList;
Status Init(SingleList *L)
{
    L->first=NULL;
    L->n=0;
    return OK;
}
Status Find(SingleList L, int i,int *x)
{
    Node *p;
    int j;
    if(i<0||i>L.n-1)
        return ERROR;
    p=L.first;
    for(j=0;j<i;j++)
        p=p->link;
    *x=p->element;
    return OK;
}
Status Insert(SingleList *L,int i,int x)
{
    Node *p,*q;
    int j;
    if(i<-1 || i>L->n-1)
        return ERROR;
    p=L->first;
    for(j=0;j<i;j++) p=p->link;
        q=(Node*)malloc(sizeof(Node));
    q->element=x;
    if(i>-1)
    {
        q->link=p->link;
        p->link=q;
    }
    else
    {
        q->link=L->first;
        L->first=q;
    }
    L->n++;
    return OK;
}
Status Delete(SingleList *L,int i)
{
    int j;
    Node *p,*q;
    if(!L->n)
        return ERROR;
    if(i<0 || i>L->n-1)
        return ERROR;
    q=L->first;
    p=L->first;
    for(j=0;j<i-1;j++)
        q=q->link;
    if(i==0)
        L->first=L->first->link;
    else
    {
        p=q->link;
        q->link=p->link;
    }
    free(p);
    L->n--;
    return OK;
}
Status Output(SingleList *L)
{
    Node *p;
    if(!L->n)
        return ERROR;
    p=L->first;
    while(p)
    {
        printf("%d ",p->element);
        p=p->link;
    }
    printf("\n");
    return OK;
}
void Destroy(SingleList *L)
{
    Node *p;
    while (L->first)
    {
        p=L->first->link;
        free(L->first);
        L->first=p;
    }
}
int main()
{
    int i;
    int x;
    SingleList list;
    Init(&list);
    for(i=0;i<9;i++)
        Insert(&list,i-1,i);
    printf("the linklist is:\n");
    Output(&list);
    Delete(&list,0);
    printf("the linklist is:\n");
    Output(&list);
    Find(list,0,&x);
    printf("the value is:\n");
    printf("%d ",x);
    Destroy(&list);
}

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5 //重复元素
typedef struct seqList
{
    int n;
    int maxLength;
    int *element;
}SeqList;
typedef int Status;
Status Init(SeqList *L,int mSize) //初始化
{
    L->maxLength=mSize;
    L->n=0;
    L->element=(int *)malloc(sizeof(int)*mSize);
    return 0;
}
Status Find(SeqList L,int i,int *x)
{
    if(i<0||i>L.n-1)
        return ERROR;
    *x=L.element[i];
       return OK;
}
Status Insert(SeqList *L,int i,int x)
{
    int j;
    if(i<-1||i>L->n-1)
    return ERROR;
    if(L->n==L->maxLength)
    return ERROR;
    for (j=L->n-1;j>i;j--)
        L->element[j+1]=L->element[j];
    L->element[i+1]=x;
    L->n=L->n+1;
    return OK;
}
Status Delete(SeqList *L,int i)
{
    int j;
    if(i<0||i>L->n-1)
        return ERROR;
    if(!L->n)
        return ERROR;
    for(j=i+1;j<L->n;j++)
        L->element[j-1]=L->element[j];
    L->n--;
    return OK;
}
Status Output(SeqList *L)
{
    int i;
    if(L->n==0)
        return ERROR;
    for(i=0;i<=L->n-1;i++)
        printf("%d ",L->element[i]);
    printf("\n");
    return OK;
}
void Destroy(SeqList *L)
{
    L->n=0;
    L->maxLength=0;
    free(L->element);
}
int main()
{
    int i;int x;int len;int choice;
    SeqList list;
    printf("开始初始化列表\n");
    Init(&list,10);
    for(i=0;i<10;i++)
        Insert(&list,i-1,i);
    printf("列表初始化中......\n");
    printf("列表初始化完毕，初始化列表为：\n");
    Output(&list);
    printf("----------------------\n0.销毁列表,退出程序\n1.索引元素\n2.删除元素\n3.输出列表\n4.插入元素\n----------------------\n");
    while(1)
    {printf("请输入对列表的操作选项(数字):");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0: 
            Destroy(&list);
            return 0;
        case 1: 
            printf("请输入要索引元素的下标：");
            scanf("%d",&i);
            if(Find(list,i,&x))
                printf("索引处找到的元素：%d\n",x);
             else
                printf("索引无效\n");
                break;
        case 2:
            printf("请输入要删除元素的下标：");
            scanf("%d",&i);
            Delete(&list,i);
            break;
        case 3: 
            printf("现在列表为:\n");
            Output(&list);
            break;
        case 4:
            printf("请输入插入元素的下标:");scanf("%d",&i);
            printf("请输入插入元素的数值:");scanf("%d",&x);
            Insert(&list,i-1,x);
            break;
        default:
            printf("选择无效，请重新输入！\n");
            break;
    }
    }
}


//第二章第一题
/*#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef struct node
{
   int element;
   struct node *link;
}Node;
typedef struct singleList
{
    Node *first;
    int n;
}SingleList;
int Init(SingleList *L) //单链表的初始化
{
    L->first=NULL;
    L->n=0;
    return OK;
}
int Output(SingleList *L) //单链表的输出
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
void Destroy(SingleList *L) //单链表的撤销
{
    Node *p;
    while (L->first)
    {
        p=L->first->link;
        free(L->first);
        L->first=p;
    }
}
int Insert(SingleList *L,int i,int x) //单链表的插入
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
//算法实现
void SplitList(SingleList *A,SingleList *B) {
    Node *current=A->first,*tailA = NULL, *tailB = NULL; //定义一个遍历A的指针，指向A和B尾部的指针
    int index = 0; //定义索引变量
    while (current) {
        Node *next = current->link; 
        if (index % 2 == 0) {                   //索引为偶数
            if (B->first == NULL) {          
                B->first = current;             //当B的头节点为空时进行初始化
                tailB = current;
            } else {
                tailB->link = current;         //将B的尾节点指向当前节点
                tailB = current;
            }
        } else {                              //索引为奇数
            if(index==1){                     //索引为1重新指向A的头节点
                A->first=current;
                tailA=current;
            }
            else{
                tailA->link = current;        //将A的尾节点指向当前节点
                tailA = current; 
            }
        }
        index++;
        current = next; 
    }
    tailB->link = NULL;                       
    tailA->link = NULL;
    B->n = (A->n + 1) / 2;     //更新A和B的节点数
    A->n = B->n - 1;
}
int main()
{
    int i;
    SingleList A,B;
    Init(&A);
    Init(&B);
    for(i=0;i<10;i++)
        Insert(&A,i-1,i);
    printf("初始链表A:\n");Output(&A);
    SplitList(&A,&B);
    printf("链表分解后:\n");
    printf("链表A:\n");Output(&A);
    printf("链表B:\n"); Output(&B);
    Destroy(&A);Destroy(&B);
    return 0;
}*/

//第二章第二题
/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define N 10
typedef struct seqList
{
    int n;
    int maxLength;
    int *element;
}SeqList;
int Init(SeqList *L,int mSize) //初始化
{
    L->maxLength=mSize;
    L->n=0;
    L->element=(int *)malloc(sizeof(int)*mSize);
    return 0;
}
int Insert(SeqList *L,int i,int x){
    int j;
    if(i<-1||i>L->n-1)
    return 0;
    if(L->n==L->maxLength)
    return 0;
    for (j=L->n-1;j>i;j--)
        L->element[j+1]=L->element[j];
    L->element[i+1]=x;
    L->n=L->n+1;
    return 1;
}
int Output(SeqList *L)
{
    int i;
    if(L->n==0)
        return 0;
    for(i=0;i<=L->n-1;i++)
        printf("%d ",L->element[i]);
    printf("\n");
    return 1;
}
void Destroy(SeqList *L)
{
    L->n=0;
    L->maxLength=0;
    free(L->element);
}
void leftRotate(SeqList *L, int n, int p) {
    int *temp = (int *)malloc(n * sizeof(int)); // 分配临时数组的空间
    if (temp == NULL) {
        printf("内存分配失败！\n");
    }
    
    p = p % n; // 计算实际左移的次数
    
    // 将左移后的元素复制到临时数组中
    for (int i = 0; i < n; i++) {
        temp[(i + p) % n] = L->element[i];
    }
    
    // 将临时数组中的元素复制回原数组
    for (int i = 0; i < n; i++) {
       L->element[i]=temp[i];
    }
    
    free(temp); // 释放临时数组的空间
}
int main()
{
    int i,p;
    SeqList list;
    Init(&list,N);
    for(i=0;i<N;i++)
        Insert(&list,i-1,i);
    printf("初始序列为:");Output(&list);
    printf("请输入序列循环左移的次数p:");
    scanf("%d",&p);
    leftRotate(&list,N,p);
    printf("循环左移后的序列为:");Output(&list);
    Destroy(&list);
    return 0;
}*/
//第三章第三题

/*#include <stdio.h>
void solveHanoi(int n, char fromRod, char toRod, char auxRod) {
    //只有一个盘片的情况下
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    // 递归情况：将顶部n-1个盘片从初始塔座移动到辅助塔座
    solveHanoi(n - 1, fromRod, auxRod, toRod);
    //将第n个盘片从初始塔座移动到目标塔座
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    // 将n-1个盘片从辅助塔座移动到目标塔座
    solveHanoi(n - 1, auxRod, toRod, fromRod);
}
int main()
{
    int n; // 盘片的数量
    printf("Enter the number of disks: "); scanf("%d", &n); //输入盘片的数量
    solveHanoi(n, 'X', 'Z', 'Y'); // X 是初始塔座 , Y 是辅助塔座 , Z 是目标塔座
}*/

#include <stdio.h>
#include <stdlib.h>
// 定义邮件结构体
typedef struct {
    int importance;
} Email;
// 比较函数，用于qsort排序
int compare(const void *a, const void *b) {
    Email *emailA = (Email *)a;
    Email *emailB = (Email *)b;
    return emailB->importance - emailA->importance; // 降序排序
}
int main() {
    // 邮件的重要程度
    int importanceLevels[] = {85, 18, 12, 17, 9, 31, 51};
    int numEmails = 7;
    // 创建邮件数组
    Email emails[numEmails];
    for (int i = 0; i < numEmails; i++) {
        emails[i].importance = importanceLevels[i];
    }
    // 排序邮件
    qsort(emails, numEmails, sizeof(Email), compare);
    // 处理邮件
    for (int i = 0; i < numEmails; i++) {
        printf("处理邮件，重要程度：%d\n", emails[i].importance);
    }

    return 0;
}
#include <stdio.h>
#define ElemType int
typedef struct
{
    int n;
    int maxLength;
    ElemType *element;
}listSet;

// 顺序搜索无序表
int Search(listSet L,ElemType x)
{
    int i;
    for (i=0;i<L.n;i++)
        if(L.element[i]==x)
            return i;
    return -1;
}

// 顺序搜索有序表
int search(listSet L,ElemType x)
{
    int i;
    for (i=0;L.element[i]<x;i++)
        if(L.element[i]==x)
            return i;
    return -1;
}

// 对半搜索:线性表是有序表且用顺序结构存储

// 对半搜索递归算法
int binSearch1(listSet L,ElemType x)
{
    if(low<=high)
    {
        int m=(low+high)/2;
        if (x<L.element[m]) return binSearch1(L,x,low,m-1);
            else if(x>L.element[m]) return binSearch1(L,x,m+1,high);
            else return m;
    }
    return -1;
}
// 对半搜索迭代算法
int binSearch2(listSet L,ElemType x)
{
    int m,low=0,high=L.n-1;
    while (low<=high)
    {
        m=(low+high)/2;
        if (x<L.element[m]) high=m-1;
        else if(x>L.element[m]) low=m+1;
        else return m;
    }
    return -1;
}

//描述对半搜索的二叉树称为二叉判定树

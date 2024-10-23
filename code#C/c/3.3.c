#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 20
#define ITEMSIZE 20
#define POSTFIXSIZE 200
#define FALSE 0
#define TRUE 1

int BOOLIsLegal(char *postfix)
{
    int i;
    char c;
    for(i=0;i<strlen(postfix);i++)
    {
        c=postfix[i];
        if(!((c>='0'&&c<'9')||c=='.'||c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c==' '))
            return FALSE;
    }
    return TRUE;
}

int GetItem(char *postfix,int *curPos, char *item)
{
    int i=0,k=*curPos,flag;
    if(postfix[k]=='.')
        flag=-1;
    else if(postfix[k]>='0'&&postfix[k]<='9')
    {
        while((postfix[k]>='0'&&postfix[k]<='9')||postfix[k]=='.')
            item[i++]=postfix[k++];
        item[i]='\0';
        flag=0;
    }
    else
    {
        item[0]=postfix[k++];
        item[1]='\0';
        flag=1;
    }
    while(postfix[k]==' ')
     k++;
    *curPos = k;
    return flag;
}

void DoOperator(Stack *S,char oper)
{
    double oper1,oper2;
    if(!Top(S,&oper1))
    {
        printf("异常:后缀表达式格式错误,存在多余的操作符！\n");
        exit(0);
    }
    Pop(S);
    if(!Top(S,&oper2))
    {
        printf("异常:后缀表达式格式错误,存在多余的操作符！\n");
        exit(0);
    }
    Pop(S);
    switch(oper)
    {
        case '+':
            Push(S, oper2+oper1);
            break;
        case '-':
            Push(S, oper2-oper1);
            break;
        case '*':
            Push(S, oper2*oper1);
            break;
        case '/':
            if  (fabs(oper1)<1e-6)
            {
                printf("异常:除数不可以为0!\n");
                exit(0);
            }
        else
            Push(S, oper2/oper1);
            break;
        case '^':
            Push(S,pow(oper2,oper1));
            break;
    }
}

double Caculating(char *postfix)
{
    Stack S;
    char item[ITEMSIZE];
    double data;
    int flag=-1;
    int curPos=0;
    while(postfix[curPos]==' ')
     curPos++;
    Creat(&S,STACKSIZE);
    while(curPos<strlen(postfix))
    {
        flag=GetItem(postfix,&curPos,item);
        if(flag==-1)
        {
            printf("异常:后缀表达式元素不合法！\n");
            exit(0);
        }
        else if(flag==1)
        {
            switch(item[0])
            {
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    DoOperator(&S,item[0]);
                    break;
            }
        }
        else
        {
            data=atof(item);
            Push(&S, data);
        }
    }
    if(S.top==0)
        Top(&S,&data);
    else
    {
        printf("异常:后缀表达式格式错误,存在多余操作数!\n");
        exit(0);
    }
    Destroy(&S);
    return data;
}

void main()
{
    char postfix[POSTFIXSIZE];
    printf("请输入后缀表达式(连续的操作数之间用空格隔开):\n");
    gets(postfix);
    if(!IsLegal(postfix))
    {
        printf("异常:中缀表达式中存在非法字符!\n");
        return ;
    }
    printf("%s=%.2f\n",postfix,Caculating(postfix));
}
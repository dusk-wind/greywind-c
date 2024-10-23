#include <stdio.h>

typedef struct pNode
{
    int coef;
    int exp;
    struct pNode* link;
}PNode;

typedef struct polynominak
{
    PNode *head;
}Polynominal;

void Create(Polynominal *p)
{
    PNode *pn,*pre,*q;
    p->head=(PNode*)malloc(sizeof(PNode));
    p->head->exp=-1;
    p->head->link=p->head;
    for(; ;)
    {
        pn=(PNode*)mallloc(sizeof(PNode));
        printf("coef:\n");
        scanf("%d",&pn->coef);
        printf("exp:\n ");
        scanf("%d",&pn->exp);
        if(pn->exp<0) break;
        pre=p->head;
        q=p->head->link;
        while(q&&q->exp>pn->exp)
        {
            pre=q;
            q=q->link;
        }
        pn->link=q;
            pre->link=pn;
    }
}

void Add (Polynominal *px,Polynominal *qx)
{
    PNode *q,*q1=qx->head,*p,*p1,*temp;
    p=px->head->link;
    q=q1->link;
    while(p->exp>=0)
    {
    while(p->exp<q->exp)
    {
        q1=q;
        q=q->link;
    }
    if(p->exp==q->exp)
    {
        q->coef=q->coef+p->coef;
        if(q->coef==0)
        {
            q1->link=q->link;
            free(q);
            q=q1->link;
            p=p->link;
        }
        else
        {
            q1=q;
            q=q->link;
            p=p->link;
        }
    }
    else
    {
        temp=(PNode*)malloc(sizeof(PNode));
        temp->coef=p->coef;
        temp->exp=p->exp;
        temp->link=q1->link;
        q1->link=temp;
        q1=q1->link;
        p=p->link;
    }
    }
}
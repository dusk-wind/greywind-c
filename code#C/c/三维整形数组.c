#define ERROR 0
#define OK 1
#define NotPresent 2
#define Duplicate 3
#define IlleageIndex 4
typedef int Status;
typedef struct tripleArray
{
    int m1,m2,m3;
    int *array;
}TripleArray;
Status CreateArray(TripleArray *tripleArray,int m1, int m2, int m3)
{
    tripleArray->m1=m1;
    tripleArray->m2=m2;
    tripleArray->m3=m3;
    tripleArray->array = (int*)malloc(m1*m2*m3*sizeof(int));
    if(!tripleArray->array)
        return ERROR;
    return OK;
}

Status DestroyArray(TripleArray *triArray)
{
    if(!triArray)
        return ERROR;
    if(triArray->array)
        free(triArray->array);
    return OK;
}

Status RetrieveArray(TripleArray triArray,int i1,int i2,int i3,int *x)
{
    if(!triArray.array)
        return NotPresent;
    if(i1<0||i2<0||i3<0||i1>=triArray.m1||i2>=triArray.m2||i3>=triArray.m3)
        return IlleageIndex;
    *x = *(triArray.array+i1*triArray.m2*triArray.m3+i2*triArray.m3+i3);
    return OK;
}

Status StoreArrayItem(TripleArray *triArray,int i1,int i2,int i3,int x)
{
    if(!triArray->array)
        return NotPresent;
    if(i1<0||i2<0||i3<0||i1>=triArray->m1||i2>=triArray->m2||i3>=triArray->m3)
        return IlleageIndex;
    *(triArray->array+i1*triArray->m2*triArray->m3+i2*triArray->m3+i3)=x;
    return OK;
}

Status OutputArray(TripleArray triArray)
{
    int i1,i2,i3;
    if(!triArray.array)
        return ;
    for(i1=0;i1<triArray.m1;i1++)
        for(i2=0;i2<triArray.m2;i2++)
            for(i3=0;i3<triArray.m3;i3++)
            {
                int value;
                RetrieveArray(triArray,i1,i2,i3,&value);
                printf("array[%d[%d][%d]=%d\n",i1,i2,i3,value);
            }
}

Status CopyArray(TripleArray *triArrayA,TripleArray *triArrayB)
{
    int i1,i2,i3;
    if(!triArrayA->array || !triArrayB->array)
        return NotPresent;
    if(triArrayA->array == triArrayB->array)
        return Duplicate;
    if(triArrayA->m1!=triArrayB->m1||triArrayA->m2!=triArrayB->m2||triArrayA->m3!=triArrayB->m3)
        return ERROR;
    for(i1=0;i1<triArrayA->m1;i1++)
        for(i2=0;i2<triArrayA->m2;i2++)
            for(i3=0;i3<triArrayA->m3;i3++)
            {
                int value;
                RetrieveArray(*triArrayA,i1,i2,i3,&value);
                StoreArrayItem(triArrayB,i1,i2,i3,value);
            }
    return OK;
}

void main()
{
    int i1,i2,i3;
    TripleArray TripleArrayA,TripleArrayB;
    CreateArray(&TripleArrayA,2,2,2);
    CreateArray(&TripleArrayB,2,2,2);
    for(i1=0;i1<TripleArrayA.m1;i1++)
       for(i2=0;i2<TripleArrayA.m2;i2++)
           for(i3=0;i3<TripleArrayA.m3;i3++)
           {
            StoreArrayItem(&TripleArrayA,i1,i2,i3,10);
            StoreArrayItem(&TripleArrayB,i1,i2,i3,5);
           }
    OutputArray(TripleArrayA);
    OutputArray(TripleArrayB);
    CopyArray(&TripleArrayA,&TripleArrayB);
    OutputArray(TripleArrayA);
    OutputArray(TripleArrayB);
}

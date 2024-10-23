#include <stdio.h>
#define N 6
int main()
{
    int i=1;int j;int sum=0;
    int arr[N]={1,3,4,2,5,2};
    
    for(;i<N;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
                sum = sum + arr[j];
        }
    }
    printf("小和：%d ",sum);
    return 0;
}
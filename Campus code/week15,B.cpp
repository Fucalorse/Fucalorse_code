#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int n;
int a[MAX];

int cmp(const void *a,const void *b)
{
    const int x=*(const int *)a;
    const int y=*(const int *)b;
    return x-y;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        
        qsort(a+1,n,sizeof(int),cmp);

        for(int i=1;i<=n;i++)
        {
            if(i>1) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
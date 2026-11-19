#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int cmp(const void *a,const void *b)
{
    const int x=*(const int *)a;
    const int y=*(const int *)b;
    return x-y;
}

int n;
int a[MAX];

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        qsort(a+1,n,sizeof(int),cmp);
        int sumo=0,sume=0;
        for(int i=1;i<=n;i++)
        {
            if(i&1) sumo+=a[i];
            else sume+=a[i];
        }
        printf("%d\n",abs(sumo-sume));
    }
    return 0;
}
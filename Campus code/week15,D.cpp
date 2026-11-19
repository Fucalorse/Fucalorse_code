#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int n,m;
int a[MAX],b[MAX],op[MAX];

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
        int val,qwq=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val);
            op[++qwq]=val;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&val);
            op[++qwq]=val;
        }

        qsort(op+1,qwq,sizeof(int),cmp);

        for(int i=1;i<=qwq;i++)
        {
            if(i>1) printf(" ");
            printf("%d",op[i]);
        }
        printf("\n");
    }
    return 0;
}
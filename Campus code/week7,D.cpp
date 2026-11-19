#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n=0,lena=0,lenb=0;
int num[MAX],a[MAX],b[MAX],ans[MAX];

int cmp(const void *a,const void *b)
{
    int x=*(const int *)a,y=*(const int *)b;
    return x-y;
}

int main()
{
    int val;
    while(scanf("%d",&val)==1) num[++n]=val;
    qsort(num+1,n,sizeof(int),cmp);
    for(int i=1;i<=n;i++)
    {
        if(num[i]&1) a[++lena]=num[i];
        else b[++lenb]=num[i];
    }
    int qwq=0;
    for(int i=lena;i>=1;i--)
        ans[++qwq]=a[i];
    for(int i=1;i<=lenb;i++)
        ans[++qwq]=b[i];
    for(int i=1;i<=qwq;i++)
    {
        if(i!=1) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}
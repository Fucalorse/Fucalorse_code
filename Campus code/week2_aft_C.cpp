#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int op[MAX];

int cmp(const void *a,const void *b)
{
    const int x=*(const int *)a;
    const int y=*(const int *)b;
    return x-y;
}

int find(int x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(op[mid]<=x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int peach(int x)
{
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(op[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return r;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",op+i);
    qsort(op+1,n,sizeof(int),cmp);
    int x;
    scanf("%d",&x);
    int pos=find(x),ans=0;
    for(int i=pos;i<=n;i++)
        if(op[i]!=op[i-1]) ans++;
    printf("%d\n",ans);
    int now=peach(x);
    for(int i=now;i>=1;i--)
        printf("%d ",op[i]);
    return 0;
}
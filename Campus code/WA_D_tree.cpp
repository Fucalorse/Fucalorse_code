#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int a[100010],b[100010];
int lena=0,lenb=0,qwq=0;

int cmp(const void *a,const void *b)
{
    const int x=*(const int*)a;
    const int y=*(const int*)b;
    return (x>y)-(x<y);
}

int find(int x)
{
    int l=1,r=lenb;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(b[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

int main()
{
    int k;
    while(scanf("%d",&k)==1)
    {
        if(k==-1) break;
        a[++lena]=k;
    }
    while(scanf("%d",&k)==1)
    {
        if(k==-1) break;
        b[++lenb]=k;
    }
    qsort(b+1,lenb,sizeof(int),cmp);
    for(int i=1;i<=lena;i++)
    {
        int pos=find(a[i]);
        if(pos<=lenb&&b[pos]==a[i]) continue;
        printf("%d ",a[i]);
        ++qwq;
    }
    printf("\n%d",qwq);
    return 0;
}
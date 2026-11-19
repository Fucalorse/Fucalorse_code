#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

struct tree
{
    int val,l,r;
}op[MAX];

int t,root,qwq,tot;
int ans[MAX],num[MAX];

int update(int pos,int k)
{
    if(!pos)
    {
        op[++qwq].val=k;
        op[qwq].l=op[qwq].r=0;
        return qwq;
    }
    if(k<op[pos].val) op[pos].l=update(op[pos].l,k);
    else op[pos].r=update(op[pos].r,k);
    return pos;
}

void find(int x)
{
    int now=root;
    while(now)
    {
        ans[++tot]=op[now].val;
        if(x==op[now].val) return;
        if(x<op[now].val) now=op[now].l;
        else now=op[now].r;
    }
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        root=qwq=tot=0;

        int tar,n=0,val;
        while(scanf("%d",&val)==1)
        {
            if(val==-1) break;
            num[++n]=val;
            root=update(root,num[n]);
        }
        scanf("%d",&tar);
        find(tar);
        for(int i=1;i<=tot;i++)
        {
            if(i>1) printf("->");
            printf("%d",ans[i]);
        }
        printf("\n%d\n",tot);
    }
    return 0;
}
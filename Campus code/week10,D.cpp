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
    char val;
    int l,r;
}op[MAX];

int t,n,qwq;
char ans[MAX];

void pre(int pos)
{
    if(!pos) return;
    ans[++qwq]=op[pos].val;
    pre(op[pos].l);
    pre(op[pos].r);
}

void mid(int pos)
{
    if(!pos) return;
    mid(op[pos].l);
    ans[++qwq]=op[pos].val;
    mid(op[pos].r);
}

void suf(int pos)
{
    if(!pos) return;
    suf(op[pos].l);
    suf(op[pos].r);
    ans[++qwq]=op[pos].val;
}

int main()
{
    scanf("%d",&t);
    for(int T=1;T<=t;T++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf(" %c%d%d",&op[i].val,&op[i].l,&op[i].r);
        printf("Case %d:\n",T);

        qwq=0;
        pre(1);
        for(int i=1;i<=qwq;i++)
            printf("%c",ans[i]);
        printf("\n");

        qwq=0;
        mid(1);
        for(int i=1;i<=qwq;i++)
            printf("%c",ans[i]);
        printf("\n");

        qwq=0;
        suf(1);
        for(int i=1;i<=qwq;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
}
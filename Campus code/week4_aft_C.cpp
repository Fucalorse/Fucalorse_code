#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

struct ovo
{
    int l,r,val;
}op[MAX];

int qwq=0,root=0,tot=0;
int ans[MAX];

int update(int pos,int k)
{
    if(!pos)
    {
        op[++qwq].val=k;
        return qwq;
    }
    if(op[pos].val==k) return pos;
    if(k<op[pos].val) op[pos].l=update(op[pos].l,k);
    else op[pos].r=update(op[pos].r,k);
    return pos;
}

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    ans[++tot]=op[pos].val;
    print(op[pos].r);
}

int main()
{
    int v;
    while(scanf("%d",&v)==1) root=update(root,v);
    print(root);
    for(int i=1;i<=tot;i++)
    {
        printf("%d",ans[i]);
        if(i<tot) printf(" ");
    }
    return 0;
}
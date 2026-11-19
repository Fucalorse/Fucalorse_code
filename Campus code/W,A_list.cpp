#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct qwq
{
    int l,r,val;
}op[100090];

int n,pos,head;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&op[i].val);
        op[i].l=i-1,op[i].r=i+1;
    }
    head=1;
    op[0].l=0,op[n].r=0;
    scanf("%d",&pos);
    if(pos==n) op[pos].val=0;
    else
    {
        int aft=op[pos].r;
        op[op[pos].l].r=aft;
        op[op[aft].r].l=pos;
        op[aft].l=op[pos].l;
        op[pos].l=aft;
        op[pos].r=op[aft].r;
        op[aft].r=pos;
        if(pos==1) head=aft;
    }
    for(int i=head;i;i=op[i].r)
        printf("%d ",op[i].val);
    return 0;
}
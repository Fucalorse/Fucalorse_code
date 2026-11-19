#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct ovo
{
    int l,r,val;
}op[100090];

int n,head=1;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&op[i].val);
        op[i].l=i-1,op[i].r=i+1;
    }
    op[n].r=0,op[1].l=0;
    int k;
    scanf("%d",&k);
    for(int i=1;i;i=op[i].r)
    {
        if(op[i].val==k)
        {
            op[op[i].l].r=op[i].r;
            op[op[i].r].l=op[i].l;
            if(i==head) head=op[i].r;
        }
    }
    for(int i=head;i;i=op[i].r)
        printf("%d ",op[i].val);
    return 0;
}
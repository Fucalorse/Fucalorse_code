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

int qwq=0,root=0;

int update(int pos,int k)
{
    if(!pos)
    {
        op[++qwq].val=k;
        return qwq;
    }
    if(k<op[pos].val) op[pos].l=update(op[pos].l,k);
    else op[pos].r=update(op[pos].r,k);
    return pos;
}

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    printf("%d ",op[pos].val);
    print(op[pos].r);
}

int main()
{
    int val;
    while(scanf("%d",&val)==1)
    {
        if(val==-1) break;
        root=update(root,val);
    }
    print(root);
    return 0;
}
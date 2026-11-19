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
}op[1090];

int t,qwq;
int ans[MAX];

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    ans[++qwq]=op[pos].val;
    print(op[pos].r);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int val,cnt=0;
        memset(op,0,sizeof op);
        while(scanf("%d",&val)==1)
        {
            if(val==-1) break;
            ++cnt;
            if(val==0) continue;
            op[cnt].val=val;
            if(cnt&1) op[cnt>>1].r=cnt;
            else op[cnt>>1].l=cnt;
        }
        int k=log2(cnt)+1;
        printf("%d ",k);
        qwq=0;
        print(1);
        for(int i=1;i<=qwq;i++)
        {
            if(i>1) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}
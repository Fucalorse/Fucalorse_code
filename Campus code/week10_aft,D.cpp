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
    int l,r,val;
}op[MAX];

int n,f[40],root,qwq;
char pre[MAX],mid[MAX];

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

void dfs(int pos)
{
    if(!pos) return;
    dfs(op[pos].l);
    dfs(op[pos].r);
    printf("%c",mid[op[pos].val]);
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        memset(f,0,sizeof(f));
        root=qwq=0;

        scanf(" %s %s",pre+1,mid+1);
        for(int i=1;i<=n;i++)
            f[mid[i]-'A']=i;
        for(int i=1;i<=n;i++)
            root=update(root,f[pre[i]-'A']);
        dfs(root);
        printf("\n");
    }
    return 0;
}
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
    int l,r;
}op[MAX];

int n;
int depth[MAX],maxn;

int max(int a,int b) { return a>b?a:b; }

void dfs(int ch,int fa)
{
    if(!ch) return;
    depth[ch]=depth[fa]+1;
    maxn=max(maxn,depth[ch]);
    dfs(op[ch].l,ch);
    dfs(op[ch].r,ch);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&op[i].l,&op[i].r);
    dfs(1,0);
    printf("%d %d",maxn,op[n].l);
    return 0;
}
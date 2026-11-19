#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int max(int a,int b) { return a>b?a:b; }
int min(int a,int b) { return a<b?a:b; }

struct tree
{
    int l,r;
}op[MAX];

int n,idx,qwq;
int f[MAX][3],g[MAX][3];
char s[MAX];

int find()
{
    if(idx>n) return 0;
    int now=s[idx++]-'0',pos=++qwq;
    if(!now) return pos;
    if(now>=1) op[pos].l=find();
    if(now==2) op[pos].r=find();
    return pos;
}

void dfs(int ch)
{
    f[ch][0]=g[ch][0]=1;
    if(op[ch].l) dfs(op[ch].l);
    if(op[ch].r) dfs(op[ch].r);
    
    if(op[ch].l&&op[ch].r)
    {
        int l=op[ch].l,r=op[ch].r;
        f[ch][0]=max(f[l][1]+f[r][2],f[l][2]+f[r][1])+1;
        f[ch][1]=max(f[l][0]+f[r][2],f[l][2]+f[r][0]);
        f[ch][2]=max(f[l][0]+f[r][1],f[l][1]+f[r][0]);

        g[ch][0]=min(g[l][1]+g[r][2],g[l][2]+g[r][1])+1;
        g[ch][1]=min(g[l][0]+g[r][2],g[l][2]+g[r][0]);
        g[ch][2]=min(g[l][0]+g[r][1],g[l][1]+g[r][0]);        
    }
    else if(op[ch].l)
    {
        int to=op[ch].l;
        f[ch][0]=max(f[to][1],f[to][2])+1;
        f[ch][1]=max(f[to][0],f[to][2]);
        f[ch][2]=max(f[to][0],f[to][1]);

        g[ch][0]=min(g[to][1],g[to][2])+1;
        g[ch][1]=min(g[to][0],g[to][2]);
        g[ch][2]=min(g[to][0],g[to][1]);
    }
}

void clear()
{
    idx=1,qwq=0;
    for(int i=1;i<=n;i++)
        op[i].l=op[i].r=0;
}

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        n=strlen(s+1);
        clear();
        int root=find();
        dfs(root);
        int maxn=max(f[root][0],max(f[root][1],f[root][2]));
        int minn=min(g[root][0],min(g[root][1],g[root][2]));
        printf("%d %d\n",maxn,minn);         
    }
    return 0;
}
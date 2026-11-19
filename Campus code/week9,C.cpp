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

int t,root,qwq;
int f[40];
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

void pre_dfs(int pos)
{
    if(!pos) return;
    printf("%c",mid[op[pos].val]);
    pre_dfs(op[pos].l);
    pre_dfs(op[pos].r);
}

void suf_dfs(int pos)
{
    if(!pos) return;
    suf_dfs(op[pos].l);
    suf_dfs(op[pos].r);
    printf("%c",mid[op[pos].val]);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        root=qwq=0;
        scanf(" %s %s",pre+1,mid+1);
        int len=strlen(pre+1);
        // printf("%d %s\n",len,pre+1);
        memset(f,0,sizeof(f));
        for(int i=1;i<=len;i++)
            f[mid[i]-'A']=i;
        for(int i=1;i<=len;i++)
            root=update(root,f[pre[i]-'A']);
        pre_dfs(root);
        printf(" ");
        suf_dfs(root);
        printf("\n");
    }
    return 0;
}
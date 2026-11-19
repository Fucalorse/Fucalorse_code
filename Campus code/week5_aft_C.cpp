#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

int n,len=0,tot=0,qwq=0;
int op[MAX],st[MAX],ans[MAX],s[1000][MAX];

void dfs(int cnt)
{
    if(qwq==n)
    {
        ++len;
        for(int i=1;i<=n;i++)
            s[len][i]=ans[i];
        return;
    }
    if(tot)
    {
        int now=st[tot--];
        ans[++qwq]=now;
        dfs(cnt);
        st[++tot]=now;
        --qwq;
    }
    if(cnt<n)
    {
        st[++tot]=op[cnt];
        dfs(cnt+1);
        --tot;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",op+i);
    dfs(0);
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>1) printf(" ");
            printf("%d",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}
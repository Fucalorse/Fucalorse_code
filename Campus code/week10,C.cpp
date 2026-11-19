#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 40
#define LL long long

int n,qwq=0;
int root[MAX][MAX],ans[MAX];
LL num[MAX],dp[MAX][MAX];

void dfs(int l,int r)
{
    if(l>r) return;
    ans[++qwq]=root[l][r];
    dfs(l,root[l][r]-1);
    dfs(root[l][r]+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",num+i);
        dp[i][i]=num[i];
        root[i][i]=i;
    }
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            for(int k=i;k<=j;k++)
            {
                LL a=k==i?1:dp[i][k-1],b=k==j?1:dp[k+1][j];
                if(a*b+num[k]>dp[i][j])
                {
                    dp[i][j]=a*b+num[k];
                    root[i][j]=k;
                }
            }
        }
    printf("%lld\n",dp[1][n]);
    dfs(1,n);
    for(int i=1;i<=qwq;i++)
    {
        if(i>1) printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}
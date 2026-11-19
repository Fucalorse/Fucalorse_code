#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int n;
int dp[100][100];

void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",dp[i]+j);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]|=dp[i][k]&dp[k][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!dp[i][j])
            {
                printf("NO\n");
                return;
            }
    printf("YES\n");
}

int main()
{
    while(scanf("%d",&n)==1) solve();
    return 0;
}
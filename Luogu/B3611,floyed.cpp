#include <bits/stdc++.h>
using namespace std;

const int MAX=150;

int n;
int f[MAX][MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",f[i]+j);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]|=f[i][k]&f[k][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",f[i][j]);
        printf("\n");
    }
    return 0;
}
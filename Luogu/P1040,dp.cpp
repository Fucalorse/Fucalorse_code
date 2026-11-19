#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=40;

int n;
int root[MAX][MAX];
LL dp[MAX][MAX],num[MAX];

void dfs(int l,int r)
{
    if(l>r) return;
    cout<<root[l][r]<<' ';
    dfs(l,root[l][r]-1);
    dfs(root[l][r]+1,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
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
    cout<<dp[1][n]<<endl;
    dfs(1,n);
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=40,inf=2e9;

int t,n,k;
int ans[MAX];

void solve()
{
    cin>>n>>k;
    vector<vector<bool>>dp(n+3,vector<bool>(n*n,false));
    vector<vector<int>>pre(n+3,vector<int>(n*n,inf));

    dp[0][0]=true;
    int ed=n*(n-1)/2;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=ed;j++)
            for(int k=1;k<=i;k++)
            {
                int len=k*(k-1)/2;
                if(j>=len&&dp[i-k][j-len])
                {
                    dp[i][j]=true;
                    pre[i][j]=i-k;
                }
            }
    
    int m=n*(n-1)/2-k;
    if(!dp[n][m]) cout<<0<<endl;
    else
    {
        vector<int>id;
        int i=n,j=m;
        while(i)
        {
            id.push_back(i);
            int l=i-pre[i][j];
            i=pre[i][j],j-=l*(l-1)/2;
        }
        id.push_back(0);

        int num=0;
        for(int i=0;i<(int)id.size()-1;i++)
            for(int j=id[i+1]+1;j<=id[i];j++)
                ans[j]=++num;
        
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
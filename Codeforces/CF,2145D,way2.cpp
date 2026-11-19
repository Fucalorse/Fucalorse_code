#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=500,LEN=30,inf=1e9;

int T,n,k;
bool dp[MAX][MAX];
int pre[MAX][MAX],ans[MAX];

void create()
{
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            pre[i][j]=inf;

    dp[0][0]=true;
    int ed=LEN*(LEN-1)/2;

    for(int i=1;i<=LEN;i++)
        for(int j=0;j<=ed;j++)
            for(int k=1;k<=i;k++)
            {
                int len=k*(k-1)/2;
                if(j-len>=0&&dp[i-k][j-len])
                {
                    dp[i][j]=true;
                    pre[i][j]=i-k;
                }
            }
}

void solve()
{
    cin>>n>>k;

    int m=n*(n-1)/2-k;

    if(dp[n][m])
    {
        int num=0;
        for(int l=pre[n][m],r=n;;)
        {
            for(int i=l+1;i<=r;i++)
                ans[i]=++num;

            // cout<<l<<' '<<r<<endl;
            if(l==0) break;

            int len=(r-l)*(r-l-1)/2;
            m-=len;
            r=l,l=pre[r][m];
        }

        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
    else cout<<0<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}
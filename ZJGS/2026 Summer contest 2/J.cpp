#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

string s;

void solve()
{
    cin>>s;
    int n=s.size();
    s=' '+s;

    vector<vector<int>>lcp(n+3,vector<int>(n+3,0));
    for(int i=n;i>=1;i--)
        for(int j=n;j>=i;j--)
        {
            if(s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
            lcp[j][i]=lcp[i][j];
        }

    vector<int>fufu(n+3,-INF),pos(n+3,-INF);
    vector<vector<int>>dp(n+3,vector<int>(n+3,-INF)),pre(n+3,vector<int>(n+3,0));

    for(int i=1;i<=n;i++)
        dp[1][i]=1;

    auto update=[&](int best_pos,int x,int val)
    {
        if(x>n||val==-INF) return;

        if(val>fufu[x])
        {
            fufu[x]=val;
            pos[x]=best_pos;
        }
    };

    for(int l=2;l<=n;l++)
    {
        fill(fufu.begin(),fufu.end(),-INF);

        for(int k=1;k<l;k++)
        {
            int same_len=lcp[l][k],pre_len=l-k;
            if(same_len>=pre_len) update(k,l+pre_len,dp[k][l-1]);
            else if(s[l+same_len]>s[k+same_len]) update(k,l+same_len,dp[k][l-1]);
        }

        for(int r=l;r<=n;r++)
        {
            update(pos[r-1],r,fufu[r-1]);
            if(fufu[r]!=-INF&&fufu[r]+1>dp[l][r])
            {
                dp[l][r]=fufu[r]+1;
                pre[l][r]=pos[r];
            }
        }
    }

    int maxn=-INF;
    pair<int,int>op;
    for(int i=1;i<=n;i++)
        if(dp[i][n]>maxn)
        {
            maxn=dp[i][n];
            op={i,n};
        }
    // cout<<maxn<<endl;

    vector<pair<int,int>>ans;
    for(int l=op.first,r=op.second;l&&r;)
    {
        ans.push_back({l,r});
        
        int nl=pre[l][r];
        r=l-1;
        l=nl;
    }

    reverse(ans.begin(),ans.end());

    // for(auto &[l,r]:ans)
    //     cout<<l<<' '<<r<<endl;

    cout<<ans.size()<<endl;
    for(auto &[l,r]:ans)
    {
        for(int i=l;i<=r;i++)
            cout<<s[i];
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
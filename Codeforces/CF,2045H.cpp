#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

string s;

vector<int> cal(int pos)
{
    int n=s.size()-1;
    vector<int>z(n+1,0);
    z[pos]=n-pos+1;
    
    for(int i=pos+1,l=pos,r=pos;i<=n;i++)
    {
        if(i<=r) z[i]=min(z[i-l+pos],r-i+1);
        while(i+z[i]<=n&&s[z[i]+pos]==s[i+z[i]]) z[i]++;
        
        if(i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }

    return z;
}

void solve()
{
    cin>>s;s=' '+s;

    int n=s.size()-1;
    vector<vector<int>>lcp(n+1);
    vector<int>best(n+1),pos(n+1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-INF)),pre(n+1,vector<int>(n+1,0));
    
    for(int i=1;i<=n;i++)
        lcp[i]=cal(i);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            lcp[j][i]=lcp[i][j];

    for(int i=1;i<=n;i++)
        dp[1][i]=1;

    auto update=[&](int id,int val,int npos)
    {
        if(id>n||val==-INF) return;

        if(val>best[id])
        {
            best[id]=val;
            pos[id]=npos;
        }
    };

    for(int l=2;l<=n;l++)
    {
        fill(best.begin(),best.end(),-INF);
        fill(pos.begin(),pos.end(),0);

        for(int k=1;k<l;k++)
        {
            if(dp[k][l-1]==-INF) continue;

            int same_len=lcp[l][k],pre_len=l-k;
            if(same_len>=pre_len) update(l+pre_len,dp[k][l-1]+1,k);
            else if(l+same_len<=n&&s[k+same_len]<s[l+same_len]) update(l+same_len,dp[k][l-1]+1,k);
        }

        for(int r=l;r<=n;r++)
        {
            update(r,best[r-1],pos[r-1]);
            if(best[r]>dp[l][r])
            {
                dp[l][r]=best[r];
                pre[l][r]=pos[r];
            }
        }
    }

    int maxn=-INF;
    pair<int,int>ed;
    for(int i=1;i<=n;i++)
        if(dp[i][n]>maxn)
        {
            maxn=dp[i][n];
            ed={i,n};
        }

    vector<pair<int,int>>ans;
    for(int l=ed.first,r=ed.second;l&&r;)
    {
        ans.emplace_back(l,r);
        int pre_pos=pre[l][r];
        r=l-1;
        l=pre_pos;
    }

    reverse(ans.begin(),ans.end());

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
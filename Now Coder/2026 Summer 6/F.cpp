#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define UI unsigned int
const int MAX=2e7+90,LEN=26,MOD=998244353,INF=2e9;

string s;

vector<int> cal()
{
    int n=s.size()-1;
    vector<int>z(n+1,0);

    for(int i=2,l=1,r=0;i<=n;i++)
    {
        if(i<=r) z[i]=min(z[i-l+1],r-i+1);
        while(i+z[i]<=n&&s[1+z[i]]==s[i+z[i]]) z[i]++;
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
    vector<int>z=cal(),deg(LEN,0),mask(LEN,0);
    vector<vector<int>>p(LEN);
    for(int i=2;i<=n;i++)
    {
        if(z[i]==n-i+1)
        {
            cout<<0<<endl;
            return;
        }

        int u=s[1+z[i]]-'a',v=s[i+z[i]]-'a';
        p[u].push_back(v),deg[v]++;
    }

    auto bfs=[&]()
    {
        queue<int>q;
        for(int i=0;i<LEN;i++)
            if(!deg[i]) q.push(i);

        while(q.size())
        {
            int u=q.front();q.pop();

            for(auto &v:p[u])
            {
                mask[v]|=mask[u];
                mask[v]|=1<<u;
                if(--deg[v]==0) q.push(v);
            }
        }

        for(int i=0;i<LEN;i++)
            if(deg[i])
            {
                // cout<<i<<endl;
                return false;
            }

        return true;
    };

    bool not_loop=bfs();
    if(!not_loop)
    {
        cout<<0<<endl;
        return;
    }

    int S=1<<LEN;
    vector<UI>dp(S);
    dp[0]=1;

    for(int k=0;k<S;k++)
        for(int i=0;i<LEN;i++)
        {
            if((k>>i)&1) continue;

            if((mask[i]&k)==mask[i])
            {
                int nxt=k|(1<<i);
                dp[nxt]+=dp[k];
            }
        }

    cout<<dp[S-1]<<endl;
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
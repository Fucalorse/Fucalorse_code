#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int c[MAX];

void solve()
{
    cin>>n>>m;

    vector<vector<int>>num(n+1);
    vector<int>cnt(1<<m,0);
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];

        for(int j=1;j<=c[i];j++)
        {
            int x;
            cin>>x;
            ++cnt[x];
            num[i].push_back(x);
        }
    }

    vector<int>all{0},basis(m,0);

    auto update=[&](int x,vector<int>& f)
    {
        for(int k=m-1;k>=0;k--)
            if((x>>k)&1)
            {
                if(!f[k])
                {
                    f[k]=x;
                    return true;
                }

                x^=f[k];
            }
        return false;
    };

    int timer=0;
    vector<int>vis(1<<m,0),val(1<<m,0);
    vector<vector<int>>base(n+1);

    for(int i=1;i<=n;i++)
    {
        vector<int>f(m,0);
        for(auto &cur:num[i])
            if(update(cur,f)) base[i].push_back(cur);
    }

    while(1)
    {
        int nxt=-1;

        for(int i=1;i<=n;i++)
        {
            vector<int>extra,f=basis;

            for(auto &cur:base[i])
                if(update(cur,f)) extra.push_back(cur);

            if(extra.empty()) continue;

            ++timer;
            for(auto &cur:num[i])
                vis[cur]=timer;

            int len=1<<(int)extra.size();
            val[0]=0;

            for(int mask=1;mask<len;++mask)
            {
                int pre=mask&(mask-1);
                int k=__builtin_ctz(mask);
                val[mask]=val[pre]^extra[k];

                for(auto &cur:all)
                {
                    int now=val[mask]^cur;
                    if(vis[now]!=timer)
                    {
                        nxt=now;
                        break;
                    }
                }

                if(nxt!=-1) break;
            }

            if(nxt!=-1) break;
        }

        if(nxt!=-1)
        {
            int len=all.size();
            for(int i=0;i<len;i++)
                all.push_back(all[i]^nxt);

            update(nxt,basis);
        }
        else break;
    }

    vector<int>operation;
    for(auto &cur:all)
        if(cnt[cur]<n) operation.push_back(cur);

    cout<<operation.size()<<endl;
    for(auto &cur:operation)
        cout<<cur<<' ';
    cout<<endl;
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
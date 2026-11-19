#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m,k;
int f[MAX];

void solve()
{
    cin>>n>>m>>k;

    set<int>st;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i];
        st.insert(f[i]);
    }

    int base=0;
    vector<int>cnt(k+1,0);
    map<pair<int,int>,int>mp;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u>v) swap(u,v);

        if(st.count(u)&&st.count(v)) ++base;
        else
        {
            if(u==v) ++cnt[u];
            else
            {
                if(st.count(u)) ++cnt[v];
                else if(st.count(v)) ++cnt[u];
                else ++mp[{u,v}];
            }
        }
    }

    int ans=base;
    for(auto &[_pair,freq]:mp)
    {
        auto &[u,v]=_pair;
        int now=base+cnt[u]+cnt[v]+freq;
        ans=max(ans,now);
    }

    if(k>=2)
    {
        sort(cnt.begin()+1,cnt.end(),greater<int>());
        ans=max(ans,base+cnt[1]+cnt[2]);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
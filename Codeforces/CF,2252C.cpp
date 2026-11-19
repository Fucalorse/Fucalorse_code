#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
typedef multiset<LL> qwq;
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

int n,m;
LL v[MAX];

void solve()
{
    cin>>n>>m;

    vector<vector<LL>>a(n+1,vector<LL>(m+1,0));
    for(int i=1;i<=n;i++)
        cin>>v[i];

    vector<qwq>st(n+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            st[i].insert(a[i][j]);

            if((int)st[i].size()>m)
            {
                auto it=st[i].begin();
                st[i].erase(it);
            }
        }

    auto merge=[&](qwq &a,qwq &b)
    {
        if(a.size()<b.size()) swap(a,b);
        a.merge(b);
    };

    int ans=m;
    for(int i=n;i>=1;i--)
    {
        int cnt=0;
        LL sum=0;

        for(auto it=st[i].rbegin();it!=st[i].rend();++it)
        {
            ++cnt;
            sum+=*it;
            if(sum>=v[i]||cnt>=m) break;
        }

        ans=min(ans,cnt);
        merge(st[i-1],st[i]);
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
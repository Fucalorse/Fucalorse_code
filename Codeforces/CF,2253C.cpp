#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    int type;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m,x,y;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n>>m>>x>>y;

    map<LL,int>f;
    for(int i=1;i<=x;i++)
    {
        cin>>a[i];
        if(!f.count(a[i])) ++f[a[i]];
    }
    for(int i=1;i<=y;i++)
    {
        cin>>b[i];
        ++f[b[i]];
    }

    vector<qwq>op;

    for(int i=1;i<=x;i++)
    {
        if(f.count(a[i])&&f[a[i]]>=2) op.push_back({2,a[i]});
        else op.push_back({0,a[i]});
    }
    for(int i=1;i<=y;i++)
    {
        if(f.count(b[i])&&f[b[i]]>=2) continue;
        else op.push_back({1,b[i]});
    }

    sort(op.begin(),op.end());

    LL ans=0;
    int c0=0,c1=0,cnt=0,total=n+m-1;
    for(auto &[type,val]:op)
    {
        if(cnt==total) break;

        if(type==0)
        {
            if(c0<n)
            {
                ++c0;
                ++cnt;
                ans+=val;
            }
        }
        else if(type==1)
        {
            if(c1<m)
            {
                ++c1;
                ++cnt;
                ans+=val;
            }
        }
        else
        {
            if(cnt<total)
            {
                ++cnt;
                ans+=val;
            }
        }
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
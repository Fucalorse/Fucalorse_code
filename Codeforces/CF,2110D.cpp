#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+10;

struct qwq
{
    int pos;
    LL cnt;
};

int t,n,m;
LL a[MAX];
vector<pair<int,LL>>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

bool dis(const LL &mid)
{
    vector<LL>f(n+5,0);
    f[1]=min(a[1],mid);
    for(int i=1;i<=n;i++)
        for(auto &[to,cost]:p[i])
        {
            if(f[i]<cost) continue;
            if(to==n) return true;
            f[to]=max(f[to],min(f[i]+a[to],mid));
        }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        clear();
        LL l=0,r=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            r+=a[i];
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            LL cost;
            cin>>u>>v>>cost;
            p[u].push_back({v,cost});
        }
        bool f=false;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            if(dis(mid)) r=mid-1,f=true;
            else l=mid+1;
        }
        if(f) cout<<l<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e18;

int t,n,m;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;
    vector<LL>f,g;
    LL sum=0,max1=-inf,max2=-inf;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]<=0)
        {
            if(i&1) max1=max(max1,a[i]);
            else max2=max(max2,a[i]);
            continue;
        }
        if(i&1) f.push_back(a[i]);
        else g.push_back(a[i]);
    }
    size_t odd=0,even=0;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(b[i]&1) odd++;
        else even++;
    }
    sort(f.begin(),f.end(),greater<LL>());
    sort(g.begin(),g.end(),greater<LL>());
    for(size_t i=0;i<min(f.size(),odd);i++)
        sum-=f[i];
    if(f.empty()&&odd) sum-=max1;
    for(size_t i=0;i<min(g.size(),even);i++)
        sum-=g[i];
    if(g.empty()&&even) sum-=max2;
    cout<<sum<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
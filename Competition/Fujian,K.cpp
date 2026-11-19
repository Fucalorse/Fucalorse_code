#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int n,l=-inf,r=inf;
int depth[MAX],sum[MAX];
vector<pair<int,int>>p[MAX];

void dfs(int ch,int fa)
{
    depth[ch]=depth[fa]+1;
    if(ch!=1)
    {
        if(depth[ch]&1) l=max(l,-sum[ch]);
        else r=min(r,sum[ch]);
    }
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;
        sum[to]=val-sum[ch];
        dfs(to,ch);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }
    dfs(1,0);
    ++l,--r;
    l=max(1,l);
    if(r>=l)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            if(depth[i]&1) cout<<sum[i]+l<<' ';
            else cout<<sum[i]-l<<' ';
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090,MOD=1e9+7,INF=1e7;

int T,n,m;
int a[MAX],f[MAX][MAX],ans[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int opt,u,v;
        cin>>opt>>u>>v;
        f[u][v]=f[v][u]=opt;
    }

    for(int u=1;u<=n;u++)
        for(int v=1;v<=n;v++)
            if(f[u][u]==f[v][v]&&f[u][u]!=f[u][v])
            {
                cout<<"NO"<<endl;
                return;
            }

    vector<vector<pair<int,int>>>p(n+1);
    for(int u=1;u<=n;u++)
    {
        if(f[u][u]==2) continue;

        for(int v=1;v<=n;v++)
        {
            if(u==v||f[v][v]==1) continue;

            if(f[u][v]==1) p[u].push_back({v,0});
            else p[v].push_back({u,-1});
        }
    }

    vector<int>dist(n+1,0),cnt(n+1);
    vector<bool>vis(n+1,false);
    queue<int>q;
    for(int i=1;i<=n;i++)
        q.push(i);

    while(q.size())
    {
        int u=q.front();q.pop();
        vis[u]=false;

        for(auto &[v,val]:p[u])
            if(dist[v]>dist[u]+val)
            {
                dist[v]=dist[u]+val;
                cnt[v]=cnt[u]+1;

                if(cnt[v]>=n)
                {
                    cout<<"NO"<<endl;
                    return;
                }

                if(!vis[v]) vis[v]=true,q.push(v);
            }
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        if(f[i][i]==1) ans[i]=dist[i]+INF;
        else ans[i]=-(dist[i]+INF);
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
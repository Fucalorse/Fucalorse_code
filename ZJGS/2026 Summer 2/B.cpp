#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090,LEN=18;
const double INF=1e30,EPS=1e-6;

int n,m;
int b[MAX],d[MAX];
double a[MAX],c[MAX];
vector<pair<int,double>>p[MAX];

bool check(const double &mid)
{
    double dx=log(mid);
    queue<int>q;
    vector<bool>vis(n+1,false);
    vector<int>f(n+1,0);
    vector<double>dist(n+1,INF);
    q.push(0);
    vis[0]=true,dist[0]=0.00;

    while(q.size())
    {
        int u=q.front();q.pop();
        vis[u]=false;

        for(auto &[v,val]:p[u])
        {
            double w=u==0?val:val-dx;
            
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                f[v]=f[u]+1;

                if(f[v]>n) return false;

                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }

    return true;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        p[b[i]].push_back({d[i],-log(c[i])+log(a[i])});
    }

    for(int i=1;i<=n;i++)
        p[0].push_back({i,0.00});

    double l=0,r=1;
    while(r-l>EPS)
    {
        double mid=(l+r)/2;

        if(check(mid)) l=mid;
        else r=mid;
    }

    cout<<fixed<<setprecision(20);
    cout<<l<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}
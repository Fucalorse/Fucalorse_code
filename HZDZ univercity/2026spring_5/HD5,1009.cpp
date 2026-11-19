#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
typedef pair<int,LL> ovo;
const int MAX=1e4+90,TRAIL=500;
const LL inf=1e18;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

int t,n,m,k;
int a[MAX],c[MAX];
LL e[MAX][10][2],f[MAX][10];
vector<ovo>p[MAX];

bool cmp(const ovo &a,const ovo &b) { return a.second<b.second; }

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]%=k;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            LL val;
            cin>>u>>v>>val;
            p[u].push_back({v,val});
            p[v].push_back({u,val});
        }
        for(int i=1;i<=n;i++)
            sort(p[i].begin(),p[i].end(),cmp);
        LL ans=inf;
        for(int _=1;_<=TRAIL;_++)
        {
            for(int i=1;i<=n;i++)
            {
                c[i]=dist(rng)&1;
                for(int v=0;v<k;v++)
                {
                    f[i][v]=inf;
                    e[i][v][0]=e[i][v][1]=inf;
                }
            }
            for(int u=1;u<=n;u++)
                for(auto &[v,val]:p[u])
                {
                    if(c[u]!=c[v]) continue;
                    for(int j=0;j<2;j++)
                        if(e[u][a[v]][j]==inf)
                        {
                            e[u][a[v]][j]=val;
                            break;
                        }
                }
            for(int u=1;u<=n;u++)
            {
                f[u][a[u]]=0;
                for(auto &[v,val]:p[u])
                {
                    if(c[u]!=c[v]) continue;
                    int num1=(a[u]+a[v])%k;
                    f[u][num1]=min(f[u][num1],val);
                    for(int x=0;x<k;x++)
                    {
                        int num2=(num1+x)%k;
                        LL now=e[v][x][0]==val?e[v][x][1]:e[v][x][0];
                        if(now!=inf) f[u][num2]=min(f[u][num2],now+val);
                    }
                }
            }
            for(int u=1;u<=n;u++)
            {
                ans=min(ans,f[u][0]);
                if(c[u]) continue;
                for(auto &[v,val]:p[u])
                {
                    if(!c[v]) continue;
                    for(int x=1;x<k;x++)
                        ans=min(ans,f[u][x]+f[v][k-x]+val);
                } 
            }
        }
        cout<<(ans==inf?-1:ans)<<endl;
    }
    return 0;
}
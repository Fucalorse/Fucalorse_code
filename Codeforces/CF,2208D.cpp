#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=510;

struct peach
{
    private:
        int fa[MAX];
    public:
        peach(int n)
        {
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
};

int t,n;
char s[MAX];
bool vis[MAX],reach[MAX],f[MAX][MAX];
vector<int>p[MAX];
vector<pair<int,int>>ans;

struct ovo
{
    int id,cnt;
    bool operator<(const ovo &a)const { return cnt>a.cnt; }
}num[MAX];

void clear()
{
    ans.clear();
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void dfs(int u)
{
    reach[u]=true;
    for(auto &v:p[u])
        dfs(v);
}

void solve()
{
    cin>>n;
    clear();
    for(int i=1;i<=n;i++)
    {
        cin>>(s+1);
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            f[i][j]=s[j]-'0';
            cnt+=f[i][j];
        }
        num[i]={i,cnt};
    }
    sort(num+1,num+n+1);
    for(int u=1;u<=n;u++)
    {
        memset(vis,false,sizeof(bool)*(n+3));
        vis[u]=true;
        for(int i=1;i<=n;i++)
        {
            int v=num[i].id;
            if(!vis[v]&&f[u][v])
            {
                ans.push_back({u,v});
                for(int k=1;k<=n;k++)
                    if(f[v][k]) vis[k]=true;
            }
        }
    }
    if((int)ans.size()!=n-1)
    {
        cout<<"NO"<<endl;
        return;
    }
    peach fu(n);
    int total=n;
    for(auto &[u,v]:ans)
    {
        if(fu.find(u)==fu.find(v)) continue;
        p[u].push_back(v);
        fu.combine(u,v);
        --total;
    }
    if(total!=1)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int u=1;u<=n;u++)
    {
        memset(reach,false,sizeof(bool)*(n+3));
        dfs(u);
        for(int v=1;v<=n;v++)
            if(reach[v]!=f[u][v])
            {
                cout<<"NO"<<endl;
                return;
            }
    }
    cout<<"YES"<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
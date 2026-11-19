#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=8090;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int n)
        {
            fa.assign(n+1,0);
            for(int i=1;i<=n;i++)
                fa[i]=i;
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void combine(int x,int y) { fa[find(x)]=find(y); }
};

struct qwq
{
    int pos,cnt;
    bool operator<(const qwq &a)const { return cnt>a.cnt; }
}op[MAX];

int T,n;
bool f[MAX][MAX];
vector<int>p[MAX];

void dfs(int u,vector<bool>&reach)
{
    if(reach[u]) return;

    reach[u]=true;
    for(auto &v:p[u])
        if(!reach[v]) dfs(v,reach);
}

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;s=' '+s;
        
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            cnt+=s[j]=='1';
            f[i][j]=s[j]=='1';
        }

        op[i]={i,cnt};
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<f[i][j];
    //     cout<<endl;
    // }

    sort(op+1,op+n+1);

    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
    {
        int u=op[i].pos;
        vector<bool>vis(n+1,false);
        vis[u]=true;

        for(int j=1;j<=n;j++)
        {
            int v=op[j].pos;

            if(!vis[v]&&f[u][v])
            {
                ans.push_back({u,v});
                vis[v]=true;
                
                if((int)ans.size()>=n)
                {
                    cout<<"NO"<<endl;
                    return;
                }

                for(int k=1;k<=n;k++)
                    if(f[v][k]) vis[k]=true;
            }
        }
    }

    peach fu(n);
    int cnt=n;
    for(auto &[u,v]:ans)
    {
        if(fu.find(u)==fu.find(v)) continue;

        p[u].push_back(v);
        fu.combine(u,v);
        if(--cnt==1) break;
    }

    if(cnt!=1)
    {
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        vector<bool>reach(n+1,false);
        dfs(i,reach);

        for(int j=1;j<=n;j++)
            if(f[i][j]!=reach[j])
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

    cin>>T;
    while(T--) solve();

    return 0;
}
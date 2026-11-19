#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n,k,q;
stack<int>st;
bool vis[MAX];
int dfn[MAX],low[MAX],comb[MAX],scc,tot;
vector<int>p[MAX];

void dfs(int u)
{
    dfn[u]=low[u]=++tot;
    st.push(u);
    vis[u]=true;

    for(auto &v:p[u])
    {
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }

    if(low[u]==dfn[u])
    {
        ++scc;
        while(1)
        {
            int v=st.top();st.pop();
            vis[v]=false;
            comb[v]=scc;

            if(u==v) break;
        }
    }
}

void clear()
{
    scc=tot=0;

    while(st.size()) st.pop();

    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        vis[i]=false;
        dfn[i]=low[i]=comb[i]=0;
    }
}

void solve()
{
    cin>>n>>k>>q;clear();

    vector<vector<int>>a(k+1,vector<int>(n+1,0));
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(j>1) p[a[i][j-1]].push_back(a[i][j]);
        }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);

    vector<vector<LL>>f(k+1,vector<LL>(n+1,0));
    vector<vector<int>>pre(k+1,vector<int>(n+1,0)),suf(k+1,vector<int>(n+1,0));
    for(int i=1;i<=k;i++)
    {
        LL cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(comb[a[i][j-1]]==comb[a[i][j]])
            {
                pre[i][j]=pre[i][j-1];

                f[i][j]=f[i][j-1]+cnt;
                ++cnt;
            }
            else
            {
                pre[i][j]=j,suf[i][j-1]=j-1;

                f[i][j]=f[i][j-1];
                cnt=1;
            }
        }

        suf[i][n]=n;
        for(int j=n-1;j>=1;j--)
            if(comb[a[i][j]]==comb[a[i][j+1]]) suf[i][j]=suf[i][j+1];
    }

    // for(int i=1;i<=k;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<f[i][j]<<' ';
    //     cout<<endl;
    // }

    LL now=0;
    while(q--)
    {
        LL id,l,r;
        cin>>id>>l>>r;

        id=(id+now)%k+1,l=(l+now)%n+1,r=(r+now)%n+1;

        // cout<<id<<' '<<l<<' '<<r<<endl;
        if(suf[id][l]>pre[id][r])
        {
            LL cnt=r-l+1;
            now=cnt*(cnt-1)/2;
        }
        else
        {
            now=f[id][pre[id][r]-1]-f[id][suf[id][l]];
            LL cntl=suf[id][l]-l+1,cntr=r-pre[id][r]+1;
            now+=cntl*(cntl-1)/2+cntr*(cntr-1)/2;
        }

        cout<<now<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    // cout<<3<<endl<<10<<endl<<1<<endl<<1<<endl<<2<<endl;
    cin>>T;
    while(T--) solve();

    return 0;
}
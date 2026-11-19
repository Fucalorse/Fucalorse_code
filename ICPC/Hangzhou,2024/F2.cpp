#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
const int MAX=2e5+90;

int T,n,k,q;
stack<int>st;
bool vis[MAX];
int dfn[MAX],low[MAX],comb[MAX],tot,scc;
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

            comb[v]=scc;
            vis[v]=false;

            if(u==v) break;
        }
    }
}

LL C(int n,int m)
{
    if(n<m) return 0;
    if(n-m<m) m=n-m;

    LL ans=1;
    for(int i=1;i<=m;i++)
        ans=ans*(n-i+1)/i;
    
    return ans;
}

void clear()
{
    tot=scc=0;

    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        vis[i]=false;
        dfn[i]=low[i]=comb[i]=0;
    }

    while(st.size()) st.pop();
}

void solve()
{
    cin>>n>>k>>q;clear();

    vector<vector<int>>a(k+1,vector<int>(n+1));
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];

            if(j>1) p[a[i][j-1]].push_back(a[i][j]);
        }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);

    vector<vector<int>>L(k+1,vector<int>(n+1,0)),R(k+1,vector<int>(n+1,0));
    vector<vector<LL>>sum(k+1,vector<LL>(n+1,0));
    for(int i=1;i<=k;i++)
    {
        for(int l=1,r;l<=n;l=r)
        {
            r=l;
            while(r<=n&&comb[a[i][l]]==comb[a[i][r]]) ++r;
            
            for(int j=l;j<r;j++)
            {
                L[i][j]=l;
                R[i][j]=r-1;
            }
        }
    }

    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
        {
            if(comb[a[i][j]]==comb[a[i][j-1]]) sum[i][j]=sum[i][j-1]+(j-L[i][j]);
            else sum[i][j]=sum[i][j-1];
        }

    // for(int i=1;i<=k;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //         cout<<sum[i][j]<<' ';
    //     cout<<endl;
    // }

    LL ans=0;
    while(q--)
    {
        LL id,l,r;
        cin>>id>>l>>r;
        id=(id+ans)%k+1,l=(l+ans)%n+1,r=(r+ans)%n+1;

        if(R[id][l]>L[id][r])
        {
            ans=C(r-l+1,2);
            cout<<ans<<endl;
        }
        else if(R[id][l]+1>L[id][r]-1)
        {
            int midl=R[id][l],midr=L[id][r];
            ans=C(midl-l+1,2)+C(r-midr+1,2);
            cout<<ans<<endl;
        }
        else
        {
            int midl=R[id][l]+1,midr=L[id][r]-1;
            ans=sum[id][midr]-sum[id][midl-1]+C(midl-l,2)+C(r-midr,2);
            cout<<ans<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
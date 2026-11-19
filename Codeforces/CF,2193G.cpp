#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int ask(int u,int v)
{
    cout<<"? "<<u<<' '<<v<<endl<<flush;
    int col;
    cin>>col;
    return col;
}

int n;

void solve()
{
    cin>>n;
    
    vector<int>deg(n+1,0);
    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u],++deg[v];
    }

    queue<int>q;
    vector<int>op;
    for(int i=1;i<=n;i++)
        if(deg[i]==1) q.push(i);

    auto remove=[&](int u)
    {
        for(auto &v:adj[u])
        {
            if(deg[v]==1) continue;
            if(--deg[v]==1) q.push(v);
        }
    };

    while((int)q.size()>=2)
    {
        bool is_chain=((int)q.size()==2);
        int u=q.front();q.pop();
        int v=q.front();q.pop();
        remove(u),remove(v);

        int col=is_chain?1:ask(u,v);
        if(col==1)
        {
            int x=u,y=v;
            vector<int>wait;
            auto dfs=[&](auto &&self,int u,int from)->bool
            {
                wait.push_back(u);
                if(u==y)
                {
                    op=wait;
                    return true;
                }

                for(auto &v:adj[u])
                {
                    if(v==from) continue;
                    if(self(self,v,u)) return true;
                }

                wait.pop_back();
                return false;
            };
            dfs(dfs,x,0);
            break;
        }
    }

    int ans;
    if(op.size())
    {
        int len=(int)op.size();
        int l=0,r=len-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            int col=ask(op[l],op[mid]);
            if(col==1) r=mid;
            else l=mid+1;
        }
        ans=op[l];
    }
    else ans=q.front();

    cout<<"! "<<ans<<endl<<flush;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
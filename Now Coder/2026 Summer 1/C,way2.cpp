#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0},{0,-1}};

int n,m,q;
bool vis[MAX];
int fa[MAX],maxn[MAX],sz[MAX],op[MAX];

int get_id(int x,int y) { return (x-1)*m+y; }

void create()
{
    for(int i=1;i<=n*m;i++)
    {
        fa[i]=i;
        maxn[i]=-INF;
    }
}

int find(int x)
{
    if(x==fa[x]) return x;

    int p=fa[x];
    fa[x]=find(fa[x]);
    maxn[x]=max(maxn[x],maxn[p]);

    return fa[x];
}

void solve()
{
    cin>>n>>m>>q;create();

    vector<vector<int>>id(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            id[i][j]=get_id(i,j);

    auto check=[&](int x,int y) { return x>=1&&x<=n&&y>=1&&y<=m; };

    int pre=0;
    while(q--)
    {
        int p;
        cin>>p;

        if(p==1)
        {
            int x,y,v;
            cin>>x>>y>>v;
            x^=pre,y^=pre;
            // printf("%d %d\n",x,y);
            int pos=id[x][y];
            
            vector<int>rest;
            for(auto &[dx,dy]:h)
            {
                int nx=x+dx,ny=y+dy;
                if(!check(nx,ny)) continue;

                int npos=find(id[nx][ny]);
                if(!vis[npos]) continue;
                rest.push_back(npos);
            }

            sort(rest.begin(),rest.end());
            rest.erase(unique(rest.begin(),rest.end()),rest.end());

            int ans=0;
            for(auto &cur:rest)
            {
                ans+=sz[cur];
                int now=v-sz[cur]+1;
                maxn[cur]=now;
                fa[cur]=pos;
            }

            vis[pos]=true;
            sz[pos]=ans+1;
            maxn[pos]=-INF;
            op[pos]=v;

            cout<<ans<<endl;
            pre=ans;
        }
        else
        {
            int x,y;
            cin>>x>>y;

            x^=pre,y^=pre;
            // printf("%d %d\n",x,y);
            int pos=id[x][y];
            find(pos);

            int now=max(op[pos],maxn[pos]);

            cout<<now-op[pos]<<endl;
            pre=now-op[pos];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int sz[MAX];
bool vis[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        sz[i]=0;
    }
}

int get_size(int ch,int fa,vector<vector<int>>& adj)
{
    sz[ch]=1;

    for(auto &to:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        sz[ch]+=get_size(to,ch,adj);
    }

    return sz[ch];
}

int get_sent(int root,vector<vector<int>>& adj)
{
    get_size(root,0,adj);
    int half=sz[root]>>1,u=root,fa=0;

    while(1)
    {
        int nxt=-1;

        for(auto &v:adj[u])
        {
            if(v==fa||vis[v]) continue;
            if(sz[v]>half)
            {
                nxt=v;
                break;
            }
        }

        if(nxt==-1) return u;
        fa=u;
        u=nxt;
    }
}

void mark(int ch,int fa,vector<vector<int>>& adj)
{
    vis[ch]=true;

    for(auto &to:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        mark(to,ch,adj);
    }
}

int ask(int u,int v)
{
    cout<<'?'<<' '<<u<<' '<<v<<endl<<flush;
    int t;
    cin>>t;
    return t;
}

void solve()
{
    cin>>n;clear();

    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x)
        {
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
        if(y)
        {
            adj[i].push_back(y);
            adj[y].push_back(i);
        }
    }

    auto get_ans=[&]()
    {
        int now=1;
    
        while(1)
        {
            int sent=get_sent(now,adj);
            get_size(sent,0,adj);

            vector<pair<int,int>>son;
            for(auto &to:adj[sent])
            {
                if(vis[to]) continue;
                son.push_back({to,sz[to]});
            }

            if(son.empty()) return sent;

            if((int)son.size()==1)
            {
                int t=ask(sent,son.front().first);
                if(t==0) return sent;
                else return son.front().first;
            }

            sort(son.begin(),son.end(),[&](const pair<int,int>& a,const pair<int,int>& b){
                if(a.second!=b.second) return a.second>b.second;
                else return a.first<b.first;
            });

            int t=ask(son[0].first,son[1].first);
            if(t==0)
            {
                vis[sent]=true;
                for(auto &[to,size]:son)
                {
                    if(to==son.front().first) continue;
                    mark(to,sent,adj);
                }
                now=son.front().first;
            }
            else if(t==2)
            {
                vis[sent]=true;
                for(auto &[to,size]:son)
                {
                    if(to==son[1].first) continue;
                    mark(to,sent,adj);
                }
                now=son[1].first;
            }
            else
            {
                mark(son[0].first,sent,adj);
                mark(son[1].first,sent,adj);
                now=sent;
            }
        }
    };

    int ans=get_ans();
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
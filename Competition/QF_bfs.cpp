#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e5+90,LEN=60,inf=2e9;

struct edge
{
    int next,to;
}op[MAX];

int head[MAX],cnt=0;
void add(int from,int to)
{
    op[++cnt]={head[from],to};
    head[from]=cnt;
}

struct qwq
{
    int pos,fa,t;
};

int t,n,m,k;
int dist[MAX][2],pre[MAX][2],col[MAX];
vector<vector<int>>comb;

bool bfs(const int &p)
{
    for(int i=1;i<=n;i++)
    {
        dist[i][0]=dist[i][1]=inf;
        pre[i][0]=pre[i][1]=-1;
    }
    queue<qwq>q;
    for(auto &u:comb[p])
    {
        dist[u][0]=0;
        pre[u][0]=u;
        q.push({u,u,0});
    }
    while(q.size())
    {
        auto [pos,fa,val]=q.front();q.pop();
        if(col[pos]==p&&fa!=pos&&val<k) return false;
        for(int i=head[pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(val+1<dist[to][0])
            {
                if(pre[to][0]!=fa)
                {
                    dist[to][1]=dist[to][0];
                    pre[to][1]=pre[to][0];
                }
                dist[to][0]=val+1;
                pre[to][0]=fa;
                q.push({to,fa,val+1});
            }
            else if(val+1<dist[to][1]&&pre[to][0]!=fa)
            {
                dist[to][1]=val+1;
                pre[to][1]=fa;
                q.push({to,fa,val+1});
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cnt=0;
        comb.assign(LEN,vector<int>{});
        for(int i=1;i<=n;i++)
        {
            cin>>col[i];
            head[i]=0;
            comb[col[i]].push_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            if(u==v) continue;
            add(u,v);
        }
        bool g=true;
        for(int i=1;i<=50;i++)
        {
            if(comb[i].empty()) continue;
            g=bfs(i);
            if(!g) break;
        }
        if(g) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
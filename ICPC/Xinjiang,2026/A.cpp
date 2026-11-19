#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
LL tree_con=0;
LL sum[MAX],cnt[MAX],pre_sum[MAX],pre_cnt[MAX];
int deg[MAX];
bool vis[MAX],is_circle[MAX];
vector<int>p[MAX],circle;

void get_circle(int pos,vector<bool>&vis)
{
    vis[pos]=true;
    circle.push_back(pos);

    for(auto &to:p[pos])
    {
        if(vis[to]||!is_circle[to]) continue;

        get_circle(to,vis);
    }
}

void bfs()
{
    queue<int>q;

    for(int i=1;i<=n;i++)
        if(deg[i]==1) q.push(i);

    while(q.size())
    {
        int pos=q.front();q.pop();

        if(vis[pos]) continue;
        vis[pos]=true;

        for(auto &to:p[pos])
        {
            if(vis[to]) continue;

            if(--deg[to]==1) q.push(to);
        }
    }

    for(int i=1;i<=n;i++)
        if(!vis[i]) is_circle[i]=true;

    circle.push_back(182497);
    vector<bool>circle_vis(n+1,false);

    for(int i=1;i<=n;i++)
        if(is_circle[i])
        {
            get_circle(i,circle_vis);
            break;
        }
}

void dfs(int ch,int fa)
{
    if((int)p[ch].size()==1) cnt[ch]=1;

    for(auto &to:p[ch])
    {
        if(to==fa||is_circle[to]) continue;

        dfs(to,ch);

        tree_con+=sum[ch]*cnt[to]+cnt[ch]*(sum[to]+cnt[to]);
        sum[ch]+=sum[to]+cnt[to];
        cnt[ch]+=cnt[to];
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back(v);
        p[v].push_back(u);
        ++deg[u],++deg[v];
    }

    bfs();

    for(int i=1;i<=n;i++)
        if(is_circle[i]) dfs(i,0);
    
    int m=circle.size()-1;
    LL total=0,path_con=0,path_cnt=0;

    for(int i=1;i<=m;i++)
    {
        path_con+=total*cnt[circle[i]]+path_cnt*sum[circle[i]];
        total+=sum[circle[i]];
        path_cnt+=cnt[circle[i]];

        pre_cnt[i]=pre_cnt[i-1]+cnt[circle[i]];
        pre_sum[i]=pre_sum[i-1]+cnt[circle[i]]*i;
    }

    LL ans=path_con+tree_con;

        // cout<<tree_con<<' '<<path_con<<endl;

        // for(auto &cur:circle)
        //     cout<<cur<<' ';
        // cout<<endl;

    for(int i=m+1,j=1;i<=m*2;i++,j++)
    {
        pre_cnt[i]=pre_cnt[i-1]+cnt[circle[j]];
        pre_sum[i]=pre_sum[i-1]+cnt[circle[j]]*i;
    }

    for(int i=1;i<=m;i++)
    {
        int l=i+1,r=i+m/2;

        LL now=pre_sum[r]-pre_sum[l-1]-i*(pre_cnt[r]-pre_cnt[l-1]);
        ans+=now*cnt[circle[i]];
    }
        
        // cout<<endl;
        // for(int i=1;i<=m*2;i++)
        //     cout<<pre_sum[i]<<' '<<pre_cnt[i]<<endl;

    if(m%2==0)
    {
        for(int i=1;i<=m/2;i++)
        {
            LL now=m/2*cnt[circle[i]]*cnt[circle[i+m/2]];
            ans-=now;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}
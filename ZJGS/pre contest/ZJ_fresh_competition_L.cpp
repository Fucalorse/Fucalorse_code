#include <bits/stdc++.h>
using namespace std;

const int MAX=5010;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int pos,t;
};

int n,m,tot;
vector<vector<int>>op,id;
vector<vector<bool>>comb;
vector<int>p[MAX],vis;

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m;
}

void dfs(int i,int j,const int &col)
{
    id[i][j]=tot;
    for(int s=0;s<4;s++)
    {
        int ni=i+dx[s],nj=j+dy[s];
        if(dis(ni,nj)&&op[ni][nj]==col&&!id[ni][nj]) dfs(ni,nj,col);
    }
}

int bfs(const qwq &st,const int &k)
{
    queue<qwq>q;
    q.push(st);
    vis[st.pos]=k;
    int ans=0;
    while(q.size())
    {
        qwq cur=q.front();q.pop();
        ans=max(ans,cur.t);
        for(auto &to:p[cur.pos])
            if(vis[to]!=k)
            {
                vis[to]=k;
                q.push({to,cur.t+1});
            }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    op.assign(n+5,vector<int>(m+5));
    id.assign(n+5,vector<int>(m+5));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)   
            cin>>op[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!id[i][j])
            {
                ++tot;
               dfs(i,j,op[i][j]);
            }
    comb.assign(tot+5,vector<bool>(tot+5));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int s=0;s<4;s++)
            {
                int ni=i+dx[s],nj=j+dy[s];
                if(dis(ni,nj)&&id[ni][nj]!=id[i][j])
                    comb[id[ni][nj]][id[i][j]]=true;
            }
    for(int i=1;i<=tot;i++)
        for(int j=1;j<=tot;j++)
            if(comb[i][j]) p[i].push_back(j);
    vis.assign(tot+5,0);
    int ans=2e9;
    for(int i=1;i<=tot;i++)
        ans=min(ans,bfs({i,0},i));
    cout<<ans<<'\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=106,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0}};

struct qwq
{
    int row,id;
    bool operator<(const qwq &a)const { return row<a.row; }
};

int n,m,k;

void solve()
{
    cin>>n>>m>>k;

    int total=n*m;
    vector<vector<qwq>>op(m+1);
    vector<vector<bool>>block(n+1,vector<bool>(m+1,false));
    vector<vector<bool>>ok(total+1,vector<bool>(total+1,false));
    for(int i=0;i<k;i++)
    {
        int row,col;
        cin>>row>>col;
        op[col].push_back({row,i});
        block[row][col]=true;
    }

    int timer=0;
    vector<vector<int>>vis(n+1,vector<int>(m+1,0));
    auto bfs=[&](int x,int y)->void
    {
        if(block[x][y]) return;
        int st=(x-1)*m+y;
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y]=timer;

        while(q.size())
        {
            auto [x,y]=q.front();q.pop();
            int nxt=(x-1)*m+y;
            ok[st][nxt]=true;
            for(auto &[dx,dy]:h)
            {
                int nx=x+dx,ny=y+dy;
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]!=timer&&!block[nx][ny])
                {
                    vis[nx][ny]=timer;
                    q.push({nx,ny});
                }
            }
        }
    };

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ++timer;
            bfs(i,j);
        }

    for(int i=1;i<=m;i++)
    {
        op[i].push_back({0,-1});
        op[i].push_back({n+1,-1});
        sort(op[i].begin(),op[i].end());
    }

    auto cal=[&](int mask)->int
    {
        vector<int>dp(n+1,0);
        for(int col=2;col<=m;col++)
        {
            int pre=1,L=1,R=n,len=(int)op[col].size();
            bool change=false;
            for(int i=1;i<len-1;i++)
            {
                auto &[row,id]=op[col][i];
                int p=(mask>>id)&1;
                // if(mask==1) cout<<p<<' ';

                if(p==1)
                {
                    if(pre==0) return -1;
                }
                else
                {
                    if(pre==1)
                    {
                        if(change) return -1;
                        change=true;
                        L=op[col][i-1].row+1;
                        R=op[col][i].row-1;
                    }
                }

                pre=p;
            }

            if(!change)
            {
                if((int)op[col].size()==2) L=1,R=n;
                else
                {
                    if(pre==0) L=1,R=op[col][1].row-1;
                    else L=op[col][len-2].row+1,R=n;
                }
            }

            if(L>R) return -1;

            // if(mask==2) cout<<L<<' '<<R<<endl;
            vector<int>ndp(n+1,INF);
            for(int i=1;i<=n;i++)
            {
                if(dp[i]==INF) continue;
                int pre_pos=(i-1)*m+col-1;
                for(int j=L;j<=R;j++)
                {
                    int now_pos=(j-1)*m+col;
                    if(ok[pre_pos][now_pos]) ndp[j]=min(ndp[j],dp[i]+1+abs(i-j));
                }
            }
            
            swap(dp,ndp);
        }

        int minn=INF;
        for(int i=1;i<=n;i++)
            minn=min(minn,dp[i]);
        return minn==INF?-1:minn;
    };
    
    int S=1<<k;
    for(int mask=0;mask<S;mask++)
        cout<<cal(mask)<<' ';
    cout<<endl;
    // for(int mask=0;mask<S;mask++)
    //     cal(mask);
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
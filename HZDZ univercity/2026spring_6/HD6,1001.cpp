#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e17;

int t,n,m;
int f[MAX],st;
bool vis[MAX];
LL s,depth[MAX],maxn;
vector<pair<int,LL>>p[MAX];

void dfs(int ch,int fa)
{
    f[ch]=fa;
    vis[ch]=true;
    for(auto &[to,val]:p[ch])
    {
        if(to==fa) continue;
        depth[to]=depth[ch]+val;
        if(depth[to]>maxn) maxn=depth[to],st=to;
        dfs(to,ch);
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear(),vis[i]=false;
}

void solve()
{
    cin>>n>>m>>s;
    clear();
    for(int i=1;i<=m;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }
    vector<pair<LL,LL>>num;
    LL sum=0,ans=-inf;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            depth[i]=maxn=0,st=0;
            dfs(i,0);
            depth[st]=maxn=0;
            dfs(st,0);
            LL now=inf;
            for(int i=st;i;i=f[i])
                now=min(now,max(depth[i],maxn-depth[i]));
            if(now==inf) now=0;
            ans=max(ans,now);
            // cout<<i<<' '<<now<<endl;
            num.push_back({now,maxn});
            sum+=now;
        }
    int cnt=num.size();
    for(auto &[i,j]:num)
    {
        LL x=(sum-i+s)/(cnt-1),r=(sum-i+s)%(cnt-1);
        LL num1=x+(r>=1),num2=x+(r>=2);
        priority_queue<LL>q;
        q.push(num1),q.push(num2),q.push(i),q.push(j-i);
        LL now=0;
        now+=q.top();q.pop();
        now+=q.top();q.pop();
        ans=min(ans,now);
    }
    cout<<ans<<endl;
}

int main()
{
    int size(256<<20);  // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));

    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    // solve();
    cin>>t;
    while(t--) solve();
    exit(0);
}
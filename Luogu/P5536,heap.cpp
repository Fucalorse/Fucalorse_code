#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int n,k,st,maxn;
int f[MAX],depth[MAX],dp[MAX];
vector<int>p[MAX],op;
priority_queue<int,vector<int>,greater<int>>q;

void dfs(int ch,int fa)
{
    f[ch]=fa;
    dp[ch]=depth[ch];
    for(auto to:p[ch])
        if(to!=fa)
        {
            depth[to]=depth[ch]+1;
            if(depth[to]>maxn) maxn=depth[to],st=to;
            dfs(to,ch);
            dp[ch]=max(dp[ch],dp[to]);
        }
}

int main()
{
    n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1,0);
    depth[st]=maxn=0;
    dfs(st,0);
    for(int i=st;i;i=f[i])
        op.push_back(i);
    int mid=(op.size()+1)/2;
    st=op[mid-1];
    depth[st]=maxn=0;
    memset(dp,0,sizeof dp);
    dfs(st,0);
    for(int i=1;i<=n;i++)
        q.push(dp[i]-depth[i]);
    int ans=0;
    for(int i=k+1;i<=n;i++)
        ans=max(ans,q.top()+1),q.pop();
    printf("%d\n",ans);
    return 0;
}
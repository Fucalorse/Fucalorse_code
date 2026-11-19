#include <bits/stdc++.h>
using namespace std;

const int MAX=5e4+90,LEN=16;

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

int n,k;
int f[MAX][LEN+2],depth[MAX],op[MAX];
vector<int>p[MAX];
struct fucalorse
{
    void dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        f[ch][0]=fa;
        for(auto to:p[ch])
            if(to!=fa) dfs(to,ch);
    }
    void debut()
    {
        dfs(1,0);
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
                f[i][k]=f[f[i][k-1]][k-1];
    }
    void find(int u,int v)
    {
        op[u]++,op[v]++;
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int k=0;k<=LEN;k++)
            if((d>>k)&1) u=f[u][k];
        if(u==v)
        {
            op[u]--,op[f[u][0]]--;
            return;
        }
        for(int k=LEN;k>=0;k--)
            if(f[u][k]!=f[v][k])
            {
                u=f[u][k];
                v=f[v][k];
            }
        op[f[u][0]]--,op[f[u][1]]--;
    }
    int applause(int ch,int fa)
    {
        int ans=0;
        for(auto to:p[ch])
        {
            if(to==fa) continue;
            ans=max(ans,applause(to,ch));
            op[ch]+=op[to];
        }
        return max(op[ch],ans);
    }
}fu;

int main()
{
    n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.debut();
    while(k--)
    {
        int u=read(),v=read();
        fu.find(u,v);
    }
    printf("%d\n",fu.applause(1,0));
    return 0;
}
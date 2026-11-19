#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int,int> ovo;

const int MAX=1e6+90,LEN=20;

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

bool cmp(const ovo &a,const ovo &b) { return a.second>b.second; }

int n;
int f[MAX][LEN+2],depth[MAX],path[MAX],col[MAX];
vector<int>p[MAX];
vector<ovo>op[MAX];

struct fucalorse
{
    int dfs(int ch,int fa)
    {
        depth[ch]=depth[fa]+1;
        f[ch][0]=fa;
        path[ch]=1;
        for(auto &to:p[ch])
        {
            if(to==fa) continue;
            path[ch]+=dfs(to,ch);
        }
        return path[ch];
    }
    void create()
    {
        dfs(1,0);
        for(int k=1;(1<<k)<=n;k++)
            for(int i=1;i<=n;i++)
                f[i][k]=f[f[i][k-1]][k-1];
    }
    int query(int u,int v)
    {
        if(depth[u]<depth[v]) swap(u,v);
        int d=depth[u]-depth[v];
        for(int k=LEN;k>=0;k--)
            if((d>>k)&1) u=f[u][k];
        if(u==v) return u;
        for(int k=LEN;k>=0;k--)
            if(f[u][k]!=f[v][k])
            {
                u=f[u][k];
                v=f[v][k];
            }
        return f[u][0];
    }
}fu;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        col[i]=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    fu.create();
    for(int i=1;i<=n;i++)
        op[col[i]].push_back({i,depth[i]});
    for(int i=1;i<=n;i++)
    {
        if(op[i].empty()) printf("%lld\n",(LL)n*(n-1)/2);
        else if(op[i].size()==1)
        {
            auto pos=op[i].back();
            LL a=path[pos.first],b=path[1]-a+1,suma=0,sumb=0;
            for(auto &j:p[pos.first])
            {
                if(j==f[pos.first][0]) continue;
                suma+=(LL)path[j],sumb+=(LL)path[j]*path[j];
            }
            printf("%lld\n",a*b-1+(suma*suma-sumb)/2);
        }
        else
        {
            sort(op[i].begin(),op[i].end(),cmp);
            int x=op[i][0].first,y=0;
            for(auto &j:op[i])
                if(fu.query(x,j.first)!=j.first)
                {
                    y=j.first;
                    break;
                }
            if(!y)
            {
                y=op[i].back().first;
                LL a=path[x],b=(LL)path[1]-path[y]+1;
                for(auto j:p[y])
                {
                    if(j==f[y][0]||fu.query(x,j)==j) continue;
                    b+=(LL)path[j];
                }
                printf("%lld\n",a*b);
                continue;
            }
            int z=fu.query(x,y);
            LL ans=(LL)path[x]*path[y];
            for(auto &j:op[i])
            {
                int now=j.first;
                if((fu.query(x,now)!=now&&fu.query(y,now)!=now)||depth[now]<depth[z])
                {
                    ans=0;
                    break;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
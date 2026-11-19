#include <bits/stdc++.h>
using namespace std;

const int MAX=350;

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

struct edge
{
    int next,to,val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,int n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

int n,s,st;
int f[MAX],depth[MAX];
vector<pair<int,int>>num;
bool vis[MAX];

void dfs(int ch,int fa)
{
    f[ch]=fa;
    for(int i=head[ch];i;i=op[i].next)
    {
        int p=op[i].to;
        if(p==fa||vis[p]) continue;
        depth[p]=depth[ch]+op[i].val;
        if(depth[p]>depth[st]) st=p;
        dfs(p,ch);
    }
}

void find()
{
    dfs(1,0);
    depth[st]=0;
    dfs(st,0);
    for(int i=st;i;i=f[i])
        num.push_back({i,depth[i]});
    reverse(num.begin(),num.end());
}

int main()
{
    n=read(),s=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
    }
    find();
    int ans=2e9;
    for(size_t l=0,r=0;l<num.size();l++)
    {
        while(r<num.size()&&num[r].second-num[l].second<=s) r++;
        memset(vis,false,sizeof vis);
        for(size_t i=l;i<r;i++) 
            vis[num[i].first]=true;
        int now=0;
        for(size_t i=l;i<r;i++)
        {
            depth[num[i].first]=0;
            st=0;
            dfs(num[i].first,0);
            now=max(now,depth[st]);
        }
        ans=min(ans,now);
    }
    printf("%d\n",ans);
    return 0;
}
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

int n,s;
int l,r,st,maxn;
int f[MAX],depth[MAX];
bool vis[MAX];
vector<pair<int,int>>num;

void dfs(int ch,int fa)
{
    f[ch]=fa;
    for(int i=head[ch];i;i=op[i].next)
    {
        int p=op[i].to;
        if(p==fa||vis[p]) continue;
        depth[p]=depth[ch]+op[i].val;
        if(depth[p]>maxn) maxn=depth[p],st=p;
        dfs(p,ch);
    }
}

bool dis(const int &mid)
{
    for(size_t l=0,r=0;l<num.size();l++)
    {
        while(r<num.size()&&num[r].second-num[l].second<=s) r++;
        int a=num[l].second-num[0].second,b=num.back().second-num[r-1].second;
        if(max(a,b)<=mid) return true;
    }
    return false;
}

int main()
{
    n=read(),s=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
    }
    dfs(1,0);
    depth[st]=maxn=0;
    dfs(st,0);
    r=maxn;
    for(int i=st;i;i=f[i])
    {
        vis[i]=true;
        num.push_back({i,depth[i]});
    }
    reverse(num.begin(),num.end());
    for(auto i:num)
    {
        depth[i.first]=maxn=0;
        dfs(i.first,0);
        l=max(l,maxn);
    }
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(dis(mid)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX=3e5+90;

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

int n,q;
int f[MAX],depth[MAX],path[MAX],son[MAX],top[MAX],cost[MAX];
int dist[MAX],lca[MAX],g[MAX],h[MAX],t[MAX],pre[MAX];

struct fucalorse
{
	int dfs(int ch,int fa)
	{
		f[ch]=fa;
		depth[ch]=depth[fa]+1;
		path[ch]=1;
		int maxn=-1;
		for(int i=head[ch];i;i=op[i].next)
		{
			int &to=op[i].to;
			if(to==fa) continue;
			cost[to]=cost[ch]+op[i].val;
			pre[to]=op[i].val;
			path[ch]+=dfs(to,ch);
			if(path[to]>maxn) maxn=path[to],son[ch]=to;
		}
		return path[ch];
	}
	void find(int pos,int dfn)
	{
		top[pos]=dfn;
		if(!son[pos]) return;
		find(son[pos],dfn);
		for(int i=head[pos];i;i=op[i].next)
		{
			int &to=op[i].to;
			if(to==f[pos]||to==son[pos]) continue;
			find(to,to);
		}
	}
	int query(int u,int v)
	{
		while(top[u]!=top[v])
		{
			if(depth[top[u]]<depth[top[v]]) swap(u,v);
			u=f[top[u]];
		}
		return depth[u]<depth[v]?u:v;
	}
	int cal(int pos)
	{
		for(int i=head[pos];i;i=op[i].next)
		{
			int &to=op[i].to;
			if(to==f[pos]) continue;
			g[pos]+=cal(to);
		}
		return g[pos];
	}
}fu;

bool dis(const int &mid)
{
	int cnt=0,maxn=0;
	memset(g,0,sizeof g);
	for(int i=1;i<=q;i++)
		if(dist[i]>mid)
		{
			g[h[i]]++,g[t[i]]++;
			g[lca[i]]-=2;
			cnt++;
			if(dist[i]>maxn) maxn=dist[i];
		}
	if(!cnt) return true;
	fu.cal(1);
	for(int i=2;i<=n;i++)
		if(g[i]==cnt&&maxn-pre[i]<=mid) return true;
	return false;
}

int main()
{
	n=read(),q=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),val=read();
		add(u,v,val),add(v,u,val);
	}
	fu.dfs(1,0);
	fu.find(1,1);
	int l=0,r=0;
	for(int i=1;i<=q;i++)
	{
		h[i]=read(),t[i]=read();
		lca[i]=fu.query(h[i],t[i]);
		dist[i]=cost[h[i]]+cost[t[i]]-2*cost[lca[i]];
		if(dist[i]>r) r=dist[i];
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
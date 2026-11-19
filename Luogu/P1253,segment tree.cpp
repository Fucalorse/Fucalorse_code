#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90;
const LL inf=-1e18;

LL read()
{
	LL ans=0,f=1;
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

int n,q;
struct fucalorse
{
	struct tree
	{
		LL maxn,add,rep;
	}op[MAX<<2];
	void create(int l,int r,int id)
	{
		op[id].rep=inf;
		if(l==r)
		{
			op[id].maxn=read();
			return;
		}
		int mid=(l+r)>>1;
		int hl=id<<1,hr=id<<1|1;
		create(l,mid,hl);
		create(mid+1,r,hr);
		op[id].maxn=max(op[hl].maxn,op[hr].maxn);
	}
	void down(int id)
	{
		int hl=id<<1,hr=id<<1|1;
		if(op[id].rep!=inf)
		{
			op[hl].maxn=op[id].rep;
			op[hl].rep=op[id].rep;
			op[hl].add=0;

			op[hr].maxn=op[id].rep;
			op[hr].rep=op[id].rep;
			op[hr].add=0;

			op[id].rep=inf;
		}
		if(op[id].add)
		{
			op[hl].maxn+=op[id].add;
			op[hl].add+=op[id].add;

			op[hr].maxn+=op[id].add;
			op[hr].add+=op[id].add;

			op[id].add=0;
		}
	}
	void dfs(int l,int r,int id,const int &st,const int &ed,const int &p,const LL &k)
	{
		if(st<=l&&r<=ed)
		{
			if(p==1) 
			{
				op[id].maxn=op[id].rep=k;
				op[id].add=0;
			}
			else 
			{
				op[id].maxn+=k;
				op[id].add+=k;
			}
			return;
		}
		down(id);
		int mid=(l+r)>>1;
		int hl=id<<1,hr=id<<1|1;
		if(st<=mid) dfs(l,mid,hl,st,ed,p,k);
		if(mid<ed) dfs(mid+1,r,hr,st,ed,p,k);
		op[id].maxn=max(op[hl].maxn,op[hr].maxn);
	}
	LL query(int l,int r,int id,const int &st,const int &ed)
	{
		if(r<st||l>ed) return inf;
		if(st<=l&&r<=ed) return op[id].maxn;
		down(id);
		int mid=(l+r)>>1;
		int hl=id<<1,hr=id<<1|1;
		return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
	}
	void update(const int &st,const int &ed,const int &p,const LL &k)
	{
		dfs(1,n,1,st,ed,p,k);
	}
	LL get(const int &st,const int &ed)
	{
		return query(1,n,1,st,ed);
	}
}fu;

int main()
{
	n=read(),q=read();
	fu.create(1,n,1);
	while(q--)
	{
		int p=read(),st=read(),ed=read();
		if(p<=2) 
		{
			LL k=read();
			fu.update(st,ed,p,k);
		} 
		else printf("%lld\n",fu.get(st,ed));
	}
	return 0;
}
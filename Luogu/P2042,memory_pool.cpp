#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90,inf=2e9;

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

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
	int val,size,sum,maxn,sl,sr,pri,rep,id;
	bool flip;
	qwq *l,*r;
	qwq(int k,int i):val(k),size(1),sum(k),maxn(k),sl(max(0,k)),sr(max(0,k)),
	pri(dist(rng)),rep(inf),id(i),flip(false),l(nullptr),r(nullptr){}
};

struct ovo
{
    private:
        vector<qwq*>pool;
        stack<int>st;
    public:
        ovo()
        {
            pool.resize(MAX,0);
            for(int i=0;i<MAX;i++)
                st.push(i);
        }
        qwq *provide(const int &k)
        {
            int pos=st.top();st.pop();
            if(pool[pos]==nullptr) pool[pos]=new qwq(k,pos);
            else new (pool[pos]) qwq(k,pos);
            return pool[pos];
        }
        void recycle(qwq *pos)
        {
            if(!pos) return;
            recycle(pos->l);
            recycle(pos->r);
            st.push(pos->id);
        }
}fufu;

struct tree
{
	void maintain(qwq* pos)
	{
		if(pos)
		{
			pos->size=1,pos->sum=pos->maxn=pos->val;
			int lmid=pos->val;

			if(pos->l)
			{
				lmid+=pos->l->sr;
				pos->size+=pos->l->size,pos->sum+=pos->l->sum;
				int num=pos->l->sum+pos->val+(pos->r?pos->r->sl:0);
				pos->sl=max(max(pos->l->sl,num),0);
				pos->maxn=max(pos->maxn,pos->l->maxn);
			}
			else pos->sl=max(0,pos->val+(pos->r?pos->r->sl:0));

			if(pos->r)
			{
				lmid+=pos->r->sl;
				pos->size+=pos->r->size,pos->sum+=pos->r->sum;
				int num=pos->r->sum+pos->val+(pos->l?pos->l->sr:0);
				pos->sr=max(max(pos->r->sr,num),0);
				pos->maxn=max(pos->maxn,pos->r->maxn);
			}
			else pos->sr=max(0,pos->val+(pos->l?pos->l->sr:0));

			pos->maxn=max(pos->maxn,lmid);
		}
	}
	void reverse(qwq* pos)
	{
		if(!pos) return;
		swap(pos->l,pos->r);
		swap(pos->sl,pos->sr);
		pos->flip^=1;
	}
	void replace(qwq* pos,const int &k)
	{
		if(!pos) return;
		pos->val=pos->rep=k;
		pos->sum=k*pos->size;
		pos->maxn=max(k,pos->sum);
		pos->sl=max(0,pos->sum),pos->sr=max(0,pos->sum);
	}
	void down(qwq* pos)
	{
		if(pos->rep!=inf)
		{
			replace(pos->l,pos->rep);
			replace(pos->r,pos->rep);
			pos->rep=inf;
		}
		if(pos->flip)
		{
			reverse(pos->l);
			reverse(pos->r);
			pos->flip=false;
		}
	}
	pair<qwq*,qwq*> split(qwq* pos,int k)
	{
		if(!pos) return {nullptr,nullptr};
		down(pos);
		int num=pos->l?pos->l->size:0;
		if(num+1<=k)
		{
			auto p=split(pos->r,k-num-1);
			qwq *left=p.first,*right=p.second;
			pos->r=left;
			maintain(pos);
			return {pos,right};
		}
		else
		{
			auto p=split(pos->l,k);
			qwq *left=p.first,*right=p.second;
			pos->l=right;
			maintain(pos);
			return {left,pos};
		}
	}
	qwq* merge(qwq* left,qwq* right)
	{
		if(!left||!right) return left?left:right;
		if(left->pri>right->pri)
		{
			down(left);
			left->r=merge(left->r,right);
			maintain(left);
			return left;
		}
		else
		{
			down(right);
			right->l=merge(left,right->l);
			maintain(right);
			return right;
		}
	}
	qwq* create(int l,int r)
	{
		if(l==r)
		{
			int a=read();
			return fufu.provide(a);
		}
		int mid=(l+r)>>1;
		qwq *left=create(l,mid),*right=create(mid+1,r);
		return merge(left,right);
	}
};

struct fucalorse
{
	tree op;
	qwq *root;
	fucalorse() { root=nullptr; }
	void update(const int &pos,const int &len)
	{
		if(!len) return;
		qwq *now=op.create(1,len);
		if(!pos) { root=op.merge(now,root); }
		else if(pos==(root?root->size:0)) { root=op.merge(root,now); }
		else
		{
			auto p=op.split(root,pos);
			root=op.merge(p.first,now);
			root=op.merge(root,p.second);
		}
	}
	void remove(const int &pos,const int &len)
	{
		if(!len) return;
		auto p=op.split(root,pos-1);
		auto q=op.split(p.second,len);
		fufu.recycle(q.first);
		root=op.merge(p.first,q.second);
	}
	void cover(const int &pos,const int &len,const int &k)
	{
		if(!len) return;
		auto p=op.split(root,pos-1);
		auto q=op.split(p.second,len);
		op.replace(q.first,k);
		root=op.merge(p.first,q.first);
		root=op.merge(root,q.second);
	}
	void flip(const int &pos,const int &len)
	{
		if(!len) return;
		auto p=op.split(root,pos-1);
		auto q=op.split(p.second,len);
		op.reverse(q.first);
		root=op.merge(p.first,q.first);
		root=op.merge(root,q.second);
	}
	int sum(const int &pos,const int &len)
	{
		if(!len) return 0;
		auto p=op.split(root,pos-1);
		auto q=op.split(p.second,len);
		int ans=q.first->sum;
		root=op.merge(p.first,q.first);
		root=op.merge(root,q.second);
		return ans;
	}
	int maxn() { return root->maxn; }
}fu;

int main()
{
	int n=read(),q=read();
	fu.update(0,n);
	while(q--)
	{
		char s[15];
		scanf(" %s",s);
		if(s[0]=='I')
		{
			int pos=read(),len=read();
			fu.update(pos,len);
		}
		else if(s[0]=='D')
		{
			int pos=read(),len=read();
			fu.remove(pos,len);
		}
		else if(s[0]=='M'&&s[2]=='K')
		{
			int pos=read(),len=read(),k=read();
			fu.cover(pos,len,k);
		}
		else if(s[0]=='R')
		{
			int pos=read(),len=read();
			fu.flip(pos,len);
		}
		else if(s[0]=='G')
		{
			int pos=read(),len=read();
			printf("%d\n",fu.sum(pos,len));
		}
		else printf("%d\n",fu.maxn());
	}
	return 0;
}
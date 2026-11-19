#include <bits/stdc++.h>
using namespace std;

const int MAX=5090,LEN=2e5+90;

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

struct fucalorse
{
    private:
        int fa[MAX+100];
    public:
        fucalorse()
        {
            for(int i=1;i<MAX;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x])
                fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}fu;

struct qwq
{
    int u,v,val;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n,m;
vector<qwq>op;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        op.push_back({u,v,val});
    }
    sort(op.begin(),op.end());
    int ans=0,total=n;
    for(auto &i:op)
    {
        if(fu.find(i.u)==fu.find(i.v)) continue;
        ans+=i.val;
        fu.combine(i.u,i.v);
        if(--total==1) break;
    }
    if(total>1) printf("orz\n");
    else printf("%d\n",ans);
    return 0;
}
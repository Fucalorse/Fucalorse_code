#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

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
        int fa[MAX];
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

int w,n;
vector<qwq>op;

int main()
{
    w=read(),n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int a=read();
            if(i==j) continue;
            if(!a) op.push_back({i,j,w});
            else op.push_back({i,j,min(a,w)});
        }
    sort(op.begin(),op.end());
    int ans=w,total=n;
    for(auto &i:op)
    {
        if(fu.find(i.u)==fu.find(i.v)) continue;
        fu.combine(i.u,i.v);
        ans+=i.val;
        if(--total==1) break;
    }
    printf("%d\n",ans);
    return 0;
}
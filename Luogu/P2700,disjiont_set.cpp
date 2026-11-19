#include <bits/stdc++.h>
using namespace std;

#define LL long long

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
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,k;
bool f[MAX];
vector<qwq>op;

int main()
{
    n=read(),k=read();
    for(int i=1;i<=k;i++)
    {
        int a=read();
        f[a]=true;
    }
    LL total=0,ans=0;
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        op.push_back({u,v,val});
        total+=(LL)val;
    }
    sort(op.begin(),op.end());
    for(auto &i:op)
    {
        int x=fu.find(i.u),y=fu.find(i.v);
        if(f[x]&f[y]) continue;
        ans+=(LL)i.val;
        f[x]|=f[y],f[y]|=f[x];
        fu.combine(x,y);
    }
    printf("%lld\n",total-ans);
    return 0;
}
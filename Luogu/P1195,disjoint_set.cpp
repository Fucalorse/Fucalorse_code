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

int n,m,k;
vector<qwq>op;

int main()
{
    n=read(),m=read(),k=read();
    if(k>n)
    {
        printf("No Answer\n");
        exit(0);
    }
    if(k==n)
    {
        printf("0\n");
        exit(0);
    }
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        op.push_back({u,v,val});
    }
    sort(op.begin(),op.end());
    int total=n,ans=0;
    for(auto &i:op)
    {
        if(fu.find(i.u)==fu.find(i.v)) continue;
        fu.combine(i.u,i.v);
        ans+=i.val;
        total--;
        if(total==k)
        {
            printf("%d\n",ans);
            exit(0);
        }
    }
    printf("No Answer\n");
    return 0;
}
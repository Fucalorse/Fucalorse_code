#include <bits/stdc++.h>
using namespace std;
const int MAX=2e4;

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
        int fa[MAX+90];
    public:
        fucalorse(int n)
        {
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x])
                fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
}f(MAX),fu(MAX);

struct qwq
{
    int u,v,val;
};

bool cmp1(const qwq &a,const qwq &b) { return a.val>b.val; }

bool cmp2(const qwq &a,const qwq &b) { return a.val<b.val; }

int n,m,k;
vector<qwq>op,ans;

int main()
{
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        op.push_back({u,v,val});
    }
    sort(op.begin(),op.end(),cmp1);
    int cnt=0,total=n;
    for(auto &i:op)
    {
        if(f.find(i.u)==f.find(i.v)) continue;
        f.combine(i.u,i.v);
        if(i.val==0) cnt++,i.val=-10086;
        total--;
    }
    if(cnt>k||total>1)
    {
        printf("no solution\n");
        exit(0);
    }
    cnt=0,total=n;
    sort(op.begin(),op.end(),cmp2);
    for(auto &i:op)
    {
        if(fu.find(i.u)==fu.find(i.v)) continue;
        if(i.val==1||cnt<k)
        {
            if(i.val<1) i.val=0,cnt++;
            fu.combine(i.u,i.v);
            total--;
            ans.push_back(i);
        }
    }
    if(cnt<k||total>1)
    {
        printf("no solution\n");
        exit(0);
    }
    for(auto &i:ans)
        printf("%d %d %d\n",i.u,i.v,i.val);
    return 0;
}
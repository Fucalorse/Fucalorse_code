#include <bits/stdc++.h>
using namespace std;

const int MAX=5e5+90,LEN=20;

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

int n,m;
int f[MAX][LEN];
struct fucalorse
{
    void create()
    {
        for(int i=1;i<=n;i++)  
            f[i][0]=f[i-1][0]+read();
        for(int k=1;(1<<k)<=n;k++)
            for(int i=0;i+(1<<k)-1<=n;i++)
                f[i][k]=min(f[i][k-1],f[i+(1<<(k-1))][k-1]);
    }
    int query(const int &st,const int &ed)
    {
        int k=log2(ed-st+1);
        int now=min(f[st][k],f[ed-(1<<k)+1][k]);
        return f[ed+1][0]-now;
    }
}fu;

int main()
{
    n=read(),m=read();
    fu.create();
    int ans=-1e9;
    for(int i=1;i<=n;i++)
    {
        int st=i-m>0?i-m:0,ed=i-1;
        ans=max(ans,fu.query(st,ed));
    }
    printf("%d\n",ans);
    return 0;
}
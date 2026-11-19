#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90;

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

struct qwq
{
    int t,x,y;
}op[MAX];

int cal(const qwq &a,const qwq &b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int n,m;
int f[MAX];

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
        op[i]={read(),read(),read()};
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
            if(cal(op[i],op[j])+op[j].t<=op[i].t) f[i]=max(f[i],f[j]+1);
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}
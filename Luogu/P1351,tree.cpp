#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e5+90,mod=10007;

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

int n;
int op[MAX];
vector<int>p[MAX];

int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        op[i]=read();
    LL ans=0,total=0;
    for(int k=1;k<=n;k++)
    {
        if(p[k].size()<2) continue;
        int a=0,b=0;
        LL num1=0,num2=0;
        for(auto i:p[k])
        {
            if(op[i]>a) b=a,a=op[i];
            else if(op[i]>b) b=op[i];
            num1+=(LL)op[i],num2+=(LL)op[i]*op[i];
        }
        ans=max(ans,(LL)a*b);
        total=(total+num1*num1-num2)%mod;
    }
    printf("%lld %lld\n",ans,total);
    return 0;
}
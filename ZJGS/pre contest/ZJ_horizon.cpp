#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90;

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
int f[MAX],ans[MAX];
priority_queue<int>q;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        f[i]=read();
    q.push(f[n]);
    for(int i=n-1;i>=1;i--)
    {
        int cur=q.top();
        if(f[i]<=cur-2) ans[i]+=cur-f[i]-1;
        q.push(f[i]+ans[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
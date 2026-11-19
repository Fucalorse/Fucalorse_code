#include <bits/stdc++.h>
using namespace std;

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

int n;
int pre[MAX],num[MAX],op[MAX],qwq=0;
unordered_map<int,int>f;

int main()
{
    n=read();
    for(int i=1,cnt=0;i<=n;i++)
        pre[i]=read(),f[pre[i]]=++cnt;
    for(int i=1;i<=n;i++)
    {
        int a=read();
        num[i]=f[a];
    }
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(op+1,op+qwq+1,num[i])-op;
        op[pos]=num[i];
        qwq=max(qwq,pos);
    }
    printf("%d\n",qwq);
    return 0;
}
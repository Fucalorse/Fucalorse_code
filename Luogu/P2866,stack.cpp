#include <bits/stdc++.h>
using namespace std;

#define LL long long

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
stack<int>op;

int main()
{
    n=read();
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        int a=read();
        while(op.size()&&a>=op.top()) op.pop();
        total+=op.size();
        op.push(a);
    }
    printf("%lld\n",total);
    return 0;
}
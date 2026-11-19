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
int num[MAX],f[MAX];
stack<int>op;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        num[i]=read();
        while(op.size()&&num[i]>num[op.top()])
        {
            f[op.top()]=i;
            op.pop();
        }
        op.push(i);
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",f[i]);
    return 0;
}
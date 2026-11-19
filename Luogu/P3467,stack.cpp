#include <bits/stdc++.h>
using namespace std;

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
    int total=0;
    for(int i=1;i<=n;i++)
    {
        int w=read(),h=read();
        while(op.size()&&h<=op.top())
        {
            if(h<op.top()) total++;
            op.pop();
        }
        op.push(h);
    }
    printf("%d\n",total+(int)op.size());
    return 0;
}
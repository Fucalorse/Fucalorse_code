#include <bits/stdc++.h>
using namespace std;

const int MAX=2e4+90;

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
    int l,r;
}op[MAX];

int n;

int main()
{
    n=read();
    qwq pre={1,1};
    for(int i=1;i<=n;i++)
    {
        qwq now={read(),read()};
        int a=op[i-1].l,b=op[i-1].r;
        int d=now.r-now.l;
        op[i].l=1+d+min(a+abs(now.r-pre.l),b+abs(now.r-pre.r));
        op[i].r=1+d+min(a+abs(now.l-pre.l),b+abs(now.l-pre.r));
        pre=now;
    }
    printf("%d\n",op[n].r+n-pre.r-1);
    return 0;
}
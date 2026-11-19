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

int num[10];

int cal(int len)
{
    vector<int>op;
    int total=0;
    for(int i=0;i<len;i++)
    {
        op.push_back(read());
        total+=op[i];
    }
    size_t size=total/2+4;
    int f[size];
    memset(f,0,sizeof f);
    for(auto a:op)
        for(int i=total/2;i>=a;i--)
            f[i]=max(f[i],f[i-a]+a);
    return total-f[total/2];
}

int main()
{
    for(int i=1;i<=4;i++)
        num[i]=read();
    int total=0;
    for(int i=1;i<=4;i++)
        total+=cal(num[i]);
    printf("%d\n",total);
    return 0;
}
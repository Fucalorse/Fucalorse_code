#include <bits/stdc++.h>
using namespace std;

const int MAX=450,LEN=8e5,mid=4e5,inf=-1e9;

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
int a[MAX],b[MAX];
vector<int>f;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read(),b[i]=read();
    f.assign(LEN+10,inf);
    f[mid]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=0)
        {
            for(int k=LEN;k>=a[i];k--)
                if(f[k-a[i]]!=inf) f[k]=max(f[k],f[k-a[i]]+b[i]);
        }
        else
        {
            for(int k=0;k<=LEN+a[i];k++)
                if(f[k-a[i]]!=inf) f[k]=max(f[k],f[k-a[i]]+b[i]);
        }
    }
    int maxn=inf;
    for(int i=mid;i<=LEN;i++)
        if(f[i]>=0) maxn=max(maxn,f[i]+i-mid);
    printf("%d\n",maxn);
    return 0;
}
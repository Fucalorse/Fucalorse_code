#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90,LEN=20;

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

int n,k;
int f[MAX<<1];

void cal(const int &x)
{
    int sum=0;
    for(int i=LEN;i>=0;i--)
    {
        if(((k>>i)&1)&&((x>>i)&1))
        {
            f[sum+(1<<i)]++;
            f[sum+(1<<(i+1))]--;
        }
        else if((k>>i)&1)
        {
            f[sum]++;
            f[sum+(1<<i)]--;
            sum+=1<<i;
        }
        else if((x>>i)&1) sum+=1<<i;
    }
    f[sum]++,f[sum+1]--;
}

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
    {
        int a=read();
        cal(a);
    }
    int maxn=0;
    for(int i=0;i<=(1<<20);i++)
    {
        if(i) f[i]+=f[i-1];
        maxn=max(maxn,f[i]);
    }
    printf("%d\n",maxn);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

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

int n,w;
int f[MAX];

int main()
{
    n=read(),w=read();
    for(int i=1;i<=n;i++)
    {
        int a=read(),now=max(1,i*w/100);
        f[a]++;
        for(int i=600,cnt=0;i>=0;i--)
        {
            cnt+=f[i];
            if(cnt>=now) 
            {
                printf("%d ",i);
                break;
            }
        }
    }
    return 0;
}
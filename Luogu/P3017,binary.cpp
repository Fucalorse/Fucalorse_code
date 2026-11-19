#include <bits/stdc++.h>
using namespace std;

const int MAX=550;

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

int n,m,a,b;
int f[MAX][MAX];

bool cal(const int &mid)
{
    int total=0;
    for(int l=0,r=1;r<=n;r++)
    {
        int sum=0,cnt=0;
        for(int i=1;i<=m;i++)
        {
            sum+=f[r][i]-f[l][i];
            if(sum>=mid) sum=0,cnt++;
            if(cnt>=b) 
            {
                l=r;
                total++;
                break;
            }
        }
        if(total>=a) return true;
    }
    return false;
}

int main()
{
    n=read(),m=read(),a=read(),b=read();
    int l=0,r=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int now=read();
            f[i][j]=f[i-1][j]+now;
            r+=now;
        }
    r/=a*b;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(cal(mid)) l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
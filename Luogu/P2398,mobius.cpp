#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

int n;
int minp[MAX],mu[MAX],f[MAX];
vector<int>op;

void oula()
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i,mu[i]=-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if((LL)i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
            else mu[i*j]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+mu[i];
}

LL cal(const int &d)
{
    int ed=n/d,r;
    LL ans=0;
    for(int l=1;l<=ed;l=r+1)
    {
        int a=ed/l;
        r=min(ed,ed/a);
        ans+=(LL)a*a*(f[r]-f[l-1]);
    }
    return ans;
}

int main()
{
    cin>>n;
    oula();
    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=(LL)i*cal(i);
    cout<<ans<<'\n';
    return 0;
}
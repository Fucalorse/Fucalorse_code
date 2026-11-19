#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,MOD=998244353,INF=2e9;

int n;
int minp[MAX],mu[MAX];
LL f[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1,mu[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            mu[i]=-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
            mu[i*j]=-mu[i];
        }
    }

    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+mu[i];
}

LL cal(int m)
{
    LL ans=0;
    for(int l=1,r;l<=m;l=r+1)
    {
        int now=m/l;
        r=min(m,m/now);
        
        LL con=1LL*(f[r]-f[l-1])*now*now;
        ans+=con;
    }

    return ans;
}

LL split(int x)
{
    map<int,int>f;
    while(x!=1)
    {
        ++f[minp[x]];
        x/=minp[x];
    }

    LL ans=1;
    for(auto &[val,cnt]:f)
        ans*=cnt+1;

    return ans;
}

void solve()
{
    cin>>n;

    LL ans=0;
    for(int d=1;d<=n;d++)
    {
        // cout<<cal(n/d)<<endl;
        LL now=cal(n/d)*split(d);
        ans+=now;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,mod=1e9+7,LEN=1e6+10;

int t,n,m;
int cnta[MAX],cntb[MAX],minp[MAX];
LL a[MAX],b[MAX],suma[MAX],sumb[MAX],mu[MAX],f[MAX];
vector<int>op;

void oula(int n)
{
    mu[1]=1;
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
            if((LL)i*j>n) break;
            minp[i*j]=j;
            if(i%j==0)
            {
                mu[i*j]=0;
                break;
            }
            else mu[i*j]=-mu[i];
        }
    }
    for(int i=1;i<=n;i++)
        f[i]=((LL)mu[i]*i%mod*i%mod+mod)%mod;
}

void initial()
{
    for(int i=0;i<=LEN;i++)
    {
        cnta[i]=cntb[i]=0;
        suma[i]=sumb[i]=0;
    }
}

void solve()
{
    cin>>n>>m;
    initial();
    LL V=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnta[a[i]]++;
        V=max(V,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        cntb[b[i]]++;
        V=max(V,b[i]);
    }
    for(int d=1;d<=V;d++)
        for(int i=1;i*d<=V;i++)
        {
            suma[d]=(suma[d]+(LL)cnta[d*i]*i)%mod;
            sumb[d]=(sumb[d]+(LL)cntb[d*i]*i)%mod;
        }
    LL ans=0;
    for(int d=1;d<=V;d++)
        for(int k=1;k*d<=V;k++)
        {
            int T=d*k;
            ans=(ans+f[k]*suma[T]%mod*sumb[T]%mod)%mod;
        }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    oula(LEN);
    cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;
const vector<int>sgn={-1,1};

int n;
LL a[MAX],f[MAX],fa[MAX],fb[MAX],pre[MAX],suf[MAX];

void cal(int s1,int s2,int s3,int s4)
{
    for(int i=2;i<n;i++)
    {
        fa[i]=(s3+s4)*a[i]-s1*a[i-1]-s2*a[i+1]-(f[i]+f[i+1]);
        fb[i]=(s1+s2)*a[i]-s3*a[i-1]-s4*a[i+1]-(f[i]+f[i+1]);
    }

    pre[0]=pre[1]=suf[n+1]=suf[n]=-INF;
    for(int i=2;i<n;i++)
        pre[i]=max(pre[i-1],fa[i]);
    for(int i=n-1;i>=2;i--)
        suf[i]=max(suf[i+1],fb[i]);
}

void solve()
{
    cin>>n;
    a[0]=a[n+1]=0,f[0]=f[1]=f[n+1]=0;

    LL S=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
        {
            f[i]=llabs(a[i]-a[i-1]);
            S+=f[i];
        }
    }

    LL extra=0;
    for(auto &s1:sgn)
        for(auto &s2:sgn)
            for(auto &s3:sgn)
                for(auto &s4:sgn)
                {
                    cal(s1,s2,s3,s4);
                    for(int i=2;i<n;i++)
                    {
                        int j=i+2;
                        if(j>n-1) break;

                        extra=max(extra,pre[i]+suf[j]);
                    }
                }

    for(int i=1;i<n;i++)
    {
        swap(a[i],a[i+1]);

        LL pre_sum=f[i]+f[i+1]+f[i+2],now_sum=0;
        if(i>1) now_sum+=llabs(a[i]-a[i-1]);
        now_sum+=llabs(a[i+1]-a[i]);
        if(i+2<=n) now_sum+=llabs(a[i+2]-a[i+1]);

        extra=max(extra,now_sum-pre_sum);

        swap(a[i],a[i+1]);
    }

    for(int i=3;i<=n;i++)
    {
        swap(a[1],a[i]);

        LL pre_sum=f[2]+f[i]+f[i+1],now_sum=llabs(a[2]-a[1]);
        if(i>1) now_sum+=llabs(a[i]-a[i-1]);
        if(i+1<=n) now_sum+=llabs(a[i+1]-a[i]);

        extra=max(extra,now_sum-pre_sum);

        swap(a[1],a[i]);
    }

    for(int i=1;i<=n-2;i++)
    {
        swap(a[i],a[n]);

        LL pre_sum=f[n]+f[i]+f[i+1],now_sum=llabs(a[n]-a[n-1]);
        if(i>1) now_sum+=llabs(a[i]-a[i-1]);
        if(i+1<=n) now_sum+=llabs(a[i+1]-a[i]);

        extra=max(extra,now_sum-pre_sum);

        swap(a[i],a[n]);
    }

    cout<<S+extra<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
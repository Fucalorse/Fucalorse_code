#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=5e5,mod=1e9+7;

int T,n,x;
int a[MAX],minp[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }

        for(auto &j:op)
        {
            if((LL)i*j>n) break;

            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

void solve()
{
    cin>>n>>x;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    map<int,int>f;

    auto split=[&](int num)
    {
        while(num!=1)
        {
            ++f[minp[num]];
            num/=minp[num];
        }
    };

    for(int i=1;i<=n;i++)
        split(a[i]);

    LL ans=1;
    for(auto &[val,cnt]:f)
        ans=ans*(cnt+1)%mod;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    cin>>T;
    while(T--) solve();

    return 0;
}
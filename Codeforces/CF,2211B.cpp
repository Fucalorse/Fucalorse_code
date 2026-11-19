#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=676767677,INF=2e9;
const LL LINF=1e18;

int minp[MAX],fac_cnt[MAX];
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
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    auto cal=[&](int num)
    {
        map<int,int>f;
        while(num!=1)
        {
            ++f[minp[num]];
            num/=minp[num];
        }
        int ans=1;
        for(auto &[val,cnt]:f)
            ans*=cnt+1;
        return ans;
    };

    fac_cnt[0]=1;
    for(int i=1;i<=n;i++)
        fac_cnt[i]=cal(i);
}

int x,y;

void solve()
{
    cin>>x>>y;

    cout<<fac_cnt[abs(x-y)]<<endl;
    for(int i=1;i<=x;i++)
        cout<<1<<' ';
    for(int i=1;i<=y;i++)
        cout<<-1<<' ';
    cout<<endl;
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
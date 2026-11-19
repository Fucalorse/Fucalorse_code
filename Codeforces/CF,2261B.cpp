#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    int minn=INF,maxn=-INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }

    int high_bit=31-__builtin_clz(maxn);
    if(__builtin_clz(maxn)!=__builtin_clz(minn))
    {
        int ans=(1<<(high_bit+1))-1;
        cout<<ans<<endl;
    }
    else
    {
        int pos=-1;
        for(int k=high_bit;k>=0;k--)
            if(((maxn>>k)&1)!=((minn>>k)&1))
            {
                pos=k;
                break;
            }

        if(pos==-1) cout<<maxn<<endl;
        else
        {
            int ans=maxn|((1<<pos)-1);
            cout<<ans<<endl;
        }
    }
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
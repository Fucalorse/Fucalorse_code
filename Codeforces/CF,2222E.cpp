#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=60,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

LL insert(LL x)
{
    cout<<'I'<<' '<<x<<endl<<flush;
    LL sz;
    cin>>sz;
    return sz;
}

LL ask(LL x)
{
    cout<<'Q'<<' '<<x<<endl<<flush;
    LL big;
    cin>>big;
    return big;
}

int n;

void solve()
{
    cin>>n;

    int k=-1;
    LL S=1LL<<n,FULL=S-1;

    cout<<0<<endl<<flush;
    LL start_size=insert(0);
    if(start_size==1)
    {
        k=1;
        insert(FULL);
    }

    LL l=1,r=FULL,c;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL now=ask(mid);
        if(now>=1) l=mid+1;
        else r=mid-1;
    }
    c=r;

    if(k==-1)
    {
        LL bit;
        for(int i=LEN;i>=0;i--)
            if((c>>i)&1)
            {
                bit=1LL<<i;
                break;
            }

        if(c==FULL)
        {
            LL end_size=insert(bit);
            if(end_size==2) k=2;
            else k=3;
        }
        else
        {
            insert(FULL);
            LL cnt=ask(FULL);
            if(cnt==1) k=2;
            else k=3;
        }
    }

    cout<<'A'<<' '<<k<<' '<<c<<endl<<flush;
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
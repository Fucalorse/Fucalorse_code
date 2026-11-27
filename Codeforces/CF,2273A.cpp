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

    auto check=[&](int mid)->bool
    {
        LL cnt=0;
        for(int i=1;i<=mid;i++)
        {
            cnt+=1LL*mid/i*i;
            if(cnt>=n) return true;
        }
        return cnt>=n;
    };

    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    cout<<l<<endl;
    for(int i=l,rest=n,num=0;i>=1&&rest;i--)
    {
        int bags=min(rest/i,l/i);
        rest-=bags*i;
        for(int cur=1;cur<=bags;cur++)
        {
            ++num;
            for(int j=1;j<=i;j++)
                cout<<num<<' ';
        }
    }
    cout<<endl;
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
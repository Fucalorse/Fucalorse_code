#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    vector<int>freq(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++freq[a[i]];
    }

    auto check=[&](int mid)->bool
    {
        int S=k+n+2*mid-1,used=0;
        vector<int>cnt=freq;
        
        for(int num=n;num>=1;num--)
        {
            int take=min(cnt[num],max(0,S-num+1));
            S-=take;
            int split=cnt[num]-take;
            if(split==0) continue;
            if(num==1) return false;

            cnt[(num+1)>>1]+=split*2;
            used+=split;
            if(used>mid) return false;
        }

        return true;
    };
    
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    cout<<2*l+n<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
LL a[MAX],op[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]=a[i];
    }

    map<LL,int>mp;
    auto update=[&](LL x)
    {
        while(x!=1)
        {
            mp[x]++;
            if(x&1) x++;
            else x>>=1;
        }
    };
    for(int i=1;i<=n;i++)
        update(a[i]);
    mp[1]=n,mp[2]=n;

    auto cal=[&](LL num,LL x)
    {
        LL cnt=0;
        while(num!=x)
        {
            ++cnt;
            if(num&1) num++;
            else num>>=1;
        }
        return cnt;
    };
    LL minn=1e18;
    for(auto it=mp.begin();it!=mp.end();++it)
        if(it->second==n)
        {
            LL cnt=0;
            for(int i=1;i<=n;i++)
                cnt+=cal(a[i],it->first);
            minn=min(minn,cnt);
        }
    
    cout<<minn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
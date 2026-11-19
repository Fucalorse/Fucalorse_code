#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
int a[MAX];

void solve()
{
    cin>>n;n<<=1;

    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            if(!x) x=i;
            else y=i;
        }
    }

    auto check_center=[&](int pos)
    {
        vector<int>cnt(n,0);
        int l=pos-1,r=pos+1;

        while(l>=1&&r<=n)
        {
            if(a[l]!=a[r]) break;

            ++cnt[a[r]];
            --l,++r;
        }

        for(size_t i=1;i<cnt.size();i++)
            if(!cnt[i]) return (int)i;
        return 1;
    };

    auto check_two=[&]()
    {
        vector<int>cnt(n,0);
        int dx=(y-x)>>1;
        for(int i=0;i<=dx;i++)
        {
            if(a[x+i]!=a[y-i]) return 1;
            ++cnt[a[x+i]];
        }
        
        int l=x-1,r=y+1;
        // cout<<l<<' '<<r<<endl;
        while(l>=1&&r<=n)
        {
            if(a[l]!=a[r]) break;

            ++cnt[a[r]];
            --l,++r;
        }

        for(size_t i=1;i<cnt.size();i++)
            if(!cnt[i]) return (int)i;
        return 1;
    };

    int ans=1;
    ans=max(ans,max(check_center(x),check_center(y)));
    ans=max(ans,check_two());

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
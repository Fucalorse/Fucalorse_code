#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3090;

int T;
LL s;
LL f[MAX];

bool check(const LL &mid)
{
    if(f[1]+f[3]+f[5]+f[7]<mid) return false;
    if(f[2]+f[3]+f[6]+f[7]<mid) return false;
    if(f[4]+f[5]+f[6]+f[7]<mid) return false;
    if(s-f[4]<2*mid) return false;
    if(s-f[2]<2*mid) return false;
    if(s-f[1]<2*mid) return false;
    if(s<3*mid) return false;
    
    return true;
}

void solve()
{
    cin>>s;

    for(int i=1;i<=7;i++)
        cin>>f[i];

    LL l=0,r=s/3;
    while(l<=r)
    {
        LL mid=(l+r)>>1;

        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    cout<<r<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
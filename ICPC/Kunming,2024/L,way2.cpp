#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    bool have_one=false;
    int rest=0,total=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            --a[i];
            ++rest;
        }
        else have_one=true;
    }

    for(int i=1;i<=m;i++)
        cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    int posa=1,posb=1;
    if(have_one)
    {
        ++posa;
        ++total;
        ++rest;
    }

    auto update_a=[&]()->void
    {
        while(posa<=n)
        {
            if(total<a[posa]) break;
            ++total;
            ++posa;
        }
    };

    update_a();
    while(posb<=m)
    {
        if(total>=b[posb]) ++total;
        else
        {
            int dx=b[posb]-total;
            if(rest<dx) break;
            rest-=dx;
            ++total;
        }

        update_a();
        ++posb;
    }

    if(posb==m+1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
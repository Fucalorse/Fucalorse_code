#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
int a[MAX];
LL cnt[MAX],sum[MAX];

void clear()
{
    for(int i=1;i<=n+1;i++)
        cnt[i]=sum[i]=0;
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        ++cnt[1],--cnt[a[i]+1];
        sum[1]+=i,sum[a[i]+1]-=i;
    }

    auto cal=[&](LL x)
    {
        LL now=(2*n-x+1)*x/2;
        return now;
    };

    LL total=0,best=0;
    for(int i=1;i<=n;i++)
    {
        cnt[i]+=cnt[i-1];
        sum[i]+=sum[i-1];

        LL pre=cal(cnt[i])-sum[i];
        total+=pre;
    }

    for(int i=1;i<=n;i++)
    {
        LL pre=cal(cnt[a[i]])-sum[a[i]],now=cal(cnt[a[i]]-1)-(sum[a[i]]-i);
        best=max(best,now-pre);
    }

    cout<<total+best<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
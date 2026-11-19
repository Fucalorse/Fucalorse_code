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

    set<LL>st;
    st.insert(1LL),st.insert(2LL);
    LL maxo=1,maxe=2;
    while(a[1]!=1)
    {
        st.insert(a[1]);
        if(a[1]&1)
        {
            maxo=max(maxo,a[1]);
            a[1]++;
        }
        else
        {
            maxe=max(maxe,a[1]);
            a[1]>>=1;
        }
    }

    // printf("%lld %lld\n",maxo,maxe);
    for(int i=2;i<=n;i++)
    {
        LL numo=1,nume=2;
        while(a[i]!=1)
        {
            if(a[i]&1)
            {
                if(st.count(a[i])&&a[i]<=maxo) numo=max(numo,a[i]);
                a[i]++;
            }
            else
            {
                if(st.count(a[i])&&a[i]<=maxe) nume=max(nume,a[i]);
                a[i]>>=1;
            }
        }
        maxo=min(maxo,numo),maxe=min(maxe,nume);
    }

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

    // printf("121::%lld %lld\n",maxo,maxe);
    LL minn=1e18,cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=cal(op[i],maxo);
    minn=min(minn,cnt);

    if(maxe)
    {
        cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=cal(op[i],maxe);
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
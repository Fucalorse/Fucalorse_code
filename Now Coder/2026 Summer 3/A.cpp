#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=31,MOD=1e9+7,INF=2e9;

int n,m;
LL a[MAX],cnt1[LEN+3],cnt2[LEN+3],cnt3[LEN+3],cnt4[LEN+3];

void update_and(LL x)
{
    for(int i=0;i<=LEN;i++)
    {
        LL p=(x>>i)&1,q=(x>>(i+1))&1;

        if(!p&&!q)
        {
            cnt1[i]+=cnt2[i]+cnt3[i]+cnt4[i];
            cnt2[i]=cnt3[i]=cnt4[i]=0;
        }
        else if(!q)
        {
            cnt1[i]+=cnt3[i];
            cnt3[i]=0;

            cnt2[i]+=cnt4[i];
            cnt4[i]=0;
        }
        else if(!p)
        {
            cnt1[i]+=cnt2[i];
            cnt2[i]=0;

            cnt3[i]+=cnt4[i];
            cnt4[i]=0;
        }
        else continue;
    }
}

void update_or(LL x)
{
    for(int i=0;i<=LEN;i++)
    {
        LL p=(x>>i)&1,q=(x>>(i+1))&1;

        if(!p&&!q) continue;
        else if(!q)
        {
            cnt2[i]+=cnt1[i];
            cnt1[i]=0;

            cnt4[i]+=cnt3[i];
            cnt3[i]=0;
        }
        else if(!p)
        {
            cnt3[i]+=cnt1[i];
            cnt1[i]=0;

            cnt4[i]+=cnt2[i];
            cnt2[i]=0;
        }
        else
        {
            cnt4[i]+=cnt1[i]+cnt2[i]+cnt3[i];
            cnt1[i]=cnt2[i]=cnt3[i]=0;
        }
    }
}

void update_xor(LL x)
{
    for(int i=0;i<=LEN;i++)
    {
        LL p=(x>>i)&1,q=(x>>(i+1))&1;

        if(!p&&!q) continue;
        else if(!q)
        {
            swap(cnt1[i],cnt2[i]);
            swap(cnt3[i],cnt4[i]);
        }
        else if(!p)
        {
            swap(cnt1[i],cnt3[i]);
            swap(cnt2[i],cnt4[i]);
        }
        else
        {
            swap(cnt1[i],cnt4[i]);
            swap(cnt2[i],cnt3[i]);
        }
    }
}

void solve()
{
    cin>>n;

    auto add=[&](LL x)
    {
        for(int i=0;i<=LEN;i++)
        {
            LL p=(x>>i)&1,q=(x>>(i+1))&1;

            if(!p&&!q) ++cnt1[i];
            else if(!q) ++cnt2[i];
            else if(!p) ++cnt3[i];
            else ++cnt4[i];
        }
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        add(a[i]);
    }

    cin>>m;
    while(m--)
    {
        int opt;
        LL x;
        cin>>opt>>x;

        if(opt==1) update_and(x);
        else if(opt==2) update_or(x);
        else update_xor(x);

        LL ans=0;
        for(int i=0;i<=LEN;i++)
            ans+=cnt2[i];

        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
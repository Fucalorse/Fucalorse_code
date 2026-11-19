#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=1e18;

int n;
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+a[i];

    auto find=[&](int pos)
    {
        int l=1,r=pos-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            LL now=f[pos-1]-f[mid-1];
            if(now>a[pos]) l=mid+1;
            else r=mid-1;
        }
        return r==0?-1:r;
    };

    set<int>st;
    vector<LL>ans(n+1,0LL);
    for(int i=3;i<=n;i++)
        st.insert(i);

    for(int i=n;i>=3;i--)
    {
        int pos=find(i);
        if(pos==-1) continue;
        int min_len=i-pos+1,max_len=i;

        while(st.size())
        {
            auto it=st.lower_bound(min_len);
            if(it!=st.end()&&*it<=max_len)
            {
                LL now=f[i]-f[i-*it];
                ans[*it]=now;
                st.erase(it);
            }
            else break;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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
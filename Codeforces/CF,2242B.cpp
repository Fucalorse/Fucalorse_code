#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int a[MAX],f[MAX],g[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        if(a[i]==1) f[i]=f[i-1]+1;
        else f[i]=f[i-1]-1;

        if(a[i]==1||a[i]==2) g[i]=g[i-1]+1;
        else g[i]=g[i-1]-1;
    }

    multiset<int>st;
    for(int i=1;i<n;i++)
        st.insert(g[i]);

    for(int i=1;i<n;i++)
    {
        auto it=st.find(g[i]);
        assert(it!=st.end());
        st.erase(it);

        if(f[i]>=0)
        {
            auto pos=st.lower_bound(g[i]);
            if(pos!=st.end())
            {
                // cout<<i<<' ';

                cout<<"YES"<<endl;
                return;
            }
        }
    }

    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
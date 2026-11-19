#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9,LEN=30;

int T,n,k;
int ans[MAX];

void solve()
{
    cin>>n>>k;k^=n;

    int m=1;
    while(m<n) m<<=1;

    if(k>m-1)
    {
        cout<<"NO"<<endl;
        return;
    }

    set<int>st;
    for(int i=1;i<=n-1;i++)
        st.insert(i);

    int pos=0;
    for(int i=LEN;i>=0;i--)
        if((k>>i&1))
        {
            ans[++pos]=1<<i;
            st.erase(1<<i);
        }
    
    ans[++pos]=0;
    for(auto &cur:st)
        ans[++pos]=cur;

    cout<<"YES"<<endl;
    for(int i=n;i>=1;i--)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
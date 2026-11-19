#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m,L;
int a[MAX];

void solve()
{
    cin>>n>>m>>L;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    multiset<int>st;
    for(int i=1;i<=min(n+1,m);i++)
        st.insert(0);

    int now=1;
    for(int i=1;i<=n;i++)
    {
        while(now<=a[i])
        {
            auto it=st.begin();
            int nxt=*it+1;

            st.erase(it);
            st.insert(nxt);
            now++;
        }

        auto it=st.end();--it;
        st.erase(it);
        if((int)st.size()<=n-i) st.insert(0);
    }

    cout<<*st.begin()+L-a[n]<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=350;

int T,n;
int a[MAX][MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    
    multiset<int>st;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=n;j>=1;j--)
        {
            if(a[i][j]==1) ++sum;
            else break;
        }
        if(sum) st.insert(sum);
    }
    int ans=1;
    while(1)
    {
        auto it=st.lower_bound(ans);
        if(it==st.end()) break;
        st.erase(it);
        ++ans;
    }

    cout<<min(ans,n)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
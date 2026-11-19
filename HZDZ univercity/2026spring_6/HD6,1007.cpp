#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int t,n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;
    vector<int>pos(n+2,0);
    set<int>st;
    int cnt=0,ans=inf;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>m) continue;
        if(!pos[a[i]]) pos[a[i]]=i,++cnt;
        else st.erase(pos[a[i]]);
        pos[a[i]]=i;
        st.insert(i);
        if(cnt==m) ans=min(ans,*st.rbegin()-*st.begin()+1-m);
    }
    cout<<(ans==inf?-1:ans)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n,k;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=k;i++)
        cin>>a[i];

    vector<int>ans;
    set<int>st[k+1];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]==k+1) continue;
        st[b[i]].insert(i);
    }

    while(1)
    {
        bool did=false;

        for(int i=k;i>=1;i--)
            if(st[i].size())
            {
                int id=*st[i].begin();st[i].erase(id);
                ans.push_back(id);
                if(i<k) st[i+1].insert(id);
                did=true;
            }

        if(!did) break;
    }

    cout<<ans.size()<<endl;
    for(auto &cur:ans)
        cout<<cur<<' ';
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
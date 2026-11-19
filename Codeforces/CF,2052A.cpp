#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

int n;
int c[MAX],a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>c[i];
    
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++)
    {
        a[i]=n-i+1;
        for(int j=i+1;j<=n;j++)
            ans.push_back({j,i});
    }

    for(int i=1;i<=n;i++)
    {
        int pos=i;
        while(a[pos]!=c[i]) ++pos;

        while(pos>i)
        {
            ans.push_back({a[pos],a[pos-1]});
            swap(a[pos],a[pos-1]);
            --pos;
        }
    }

    cout<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}
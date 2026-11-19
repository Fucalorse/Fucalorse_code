#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;
    set<int>st;
    unordered_map<int,bool>vis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
        vis[a[i]]=false;
    }
    if(a[1]==1)
    {
        if((int)st.size()==k) cout<<1<<endl<<1<<endl;
        else cout<<-1<<endl;
        return;
    }
    vector<int>ans;
    for(auto it=st.begin();it!=st.end();++it)
    {
        int x=*it;
        if(vis[x]) continue;
        // cout<<121<<endl;
        vis[x]=true;
        ans.push_back(x);
        for(int j=x;j<=k;j+=x)
        {
            if(vis.count(j)==0)
            {
                cout<<-1<<endl;
                return;
            }
            vis[j]=true;
        }
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans)
        cout<<i<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct qwq
{
    int val,cnt;
}op[MAX];

int t,n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;
    stack<qwq>st;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(st.size()&&a[i]==st.top().val) st.top().cnt++;
        else st.push({a[i],1});
        if(st.top().cnt==k) st.pop();
    }
    vector<int>ans;
    while(st.size())
    {
        auto [val,cnt]=st.top();st.pop();
        for(int i=1;i<=cnt;i++)
            ans.push_back(val);
    }
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<' ';
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
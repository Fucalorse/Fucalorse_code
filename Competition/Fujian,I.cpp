#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

int t,n;
char s[MAX];

void solve()
{
    cin>>n>>(s+2);
    vector<int>rest;
    for(int i=2;i<=n-1;i++)
        if(s[i]=='0') rest.push_back(i);
    int cnt=rest.size();
    if(!cnt)
    {
        cout<<-1<<endl;
        return;
    }
    if(cnt==1&&s[n-1]!='0')
    {
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int>>ans;
    if(cnt==1) ans.push_back({rest.front(),1});
    else
    {
        int pre=1;
        for(int i=1;i<=n;i++)
            if(s[i]=='0') ans.push_back({pre,i}),pre=i;
        ans.push_back({pre,1});
    }
    int pre=1;
    for(int i=1;i<=n;i++)
        if(s[i]=='1') ans.push_back({pre,i}),pre=i;
    ans.push_back({pre,n});
    cout<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=200,inf=2e9;

int T,n;
string s,t;

pair<vector<pair<int,int>>,int>get(const string &s)
{
    vector<pair<int,int>>ans;
    int pos=inf;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&s[l]==s[r]) r++;
        ans.push_back({l,r-1});
        if(r-l>=2) pos=ans.size()-1;
    }
    return {ans,pos};
}

vector<pair<int,int>>cal(const string &s)
{
    auto [rest,pos]=get(s);
    vector<pair<int,int>>ans;
    if(pos!=inf)
    {
        auto [l,r]=rest[pos];
        for(int i=pos-1;i>=0;i--)
        {
            ans.push_back({l,r});
            l=rest[i].first;
        }
        if(pos&1) ans.push_back({l,r});
        for(int i=pos+1;i<(int)rest.size();i++)
        {
            ans.push_back({l,r});
            r=rest[i].second;
        }
        if(s[n]=='1') ans.push_back({1,n});
    }
    else
    {
        ans.push_back({2,4});
        ans.push_back({1,2});
        ans.push_back({1,3});
        for(int i=5;i<n;i++)
            ans.push_back({1,i});
        if(s[n]=='1'||(n==4&&s[n]=='0')) ans.push_back({1,n});
    }
    return ans;
}

void solve()
{
    cin>>n>>s>>t;s=' '+s,t=' '+t;
    vector<pair<int,int>> ans_s=cal(s);
    vector<pair<int,int>> ans_t=cal(t);
    // cout<<ans_s.size()<<' '<<ans_t.size()<<endl;
    cout<<ans_s.size()+ans_t.size()<<endl;
    for(auto &[l,r]:ans_s)
        cout<<l<<' '<<r<<endl;
    for(int i=ans_t.size()-1;i>=0;i--)
    {
        auto &[l,r]=ans_t[i];
        cout<<l<<' '<<r<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
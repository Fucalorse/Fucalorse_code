#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=2e5+90;

struct qwq
{
    int b,c;
    bool operator<(const qwq &a)const { return b<a.b; }
}num[MAX];

int t,n,m;

void peach()
{
    cin>>n>>m;
    multiset<int>f;
    vector<qwq>op;
    vector<int>rest;
    op.clear(),rest.clear();
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        f.insert(a);
    }
    for(int i=1;i<=m;i++)
        cin>>num[i].b;
    for(int i=1;i<=m;i++)
        cin>>num[i].c;
    for(int i=1;i<=m;i++)
    {
        if(num[i].c==0) rest.push_back(num[i].b);
        else op.push_back(num[i]);
    }
    sort(op.begin(),op.end()),sort(rest.begin(),rest.end());
    int ans=0;
    for(auto &[b,c]:op)
    {
        auto pos=f.lower_bound(b);
        if(pos!=f.end())
        {
            ans++;
            f.insert(max(*pos,c));
            f.erase(pos);
        }
    }
    for(auto &cur:rest)
    {
        auto pos=f.lower_bound(cur);
        if(pos!=f.end())
        {
            ans++;
            f.erase(pos);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) peach();
    return 0;
}
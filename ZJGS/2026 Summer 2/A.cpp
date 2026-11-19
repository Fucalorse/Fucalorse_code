#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

struct qwq
{
    LL l,r;
    bool operator<(const qwq &a)const { return l<a.l; }
}op[MAX];

int n;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        LL x,r;
        cin>>x>>r;
        op[i]={x-r,x+r};
    }

    sort(op+1,op+n+1);

    LL cost=0;
    auto [st,ed]=op[1];
    for(int i=2;i<=n;i++)
    {
        if(op[i].l>ed)
        {
            cost+=op[i].l-ed;
            ed=op[i].r;
        }
        else ed=max(ed,op[i].r);
    }

    cout<<cost<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}
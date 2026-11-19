#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct point
{
    int x,y;
}op[MAX];

struct qwq
{
    int val,id;
    bool operator<(const qwq &a)const { return val<a.val; }
}x[MAX],y[MAX];

int t,n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;
        x[i].val=op[i].x;
        y[i].val=op[i].y;
    }

    sort(x+1,x+n+1),sort(y+1,y+n+1);
    multiset<qwq>stx,sty;
    vector<int>a,b,c,d;
    for(int i=1;i<=n;i++)
    {
        x[i].id=y[i].id=i;
        stx.insert(x[i]);
        sty.insert(y[i]);
    }
    for(int i=1;i<=n;i++)
    {
        auto itx=stx.lower_bound({op[i].x,0}),ity=sty.lower_bound({op[i].y,0});
        // if(itx==stx.end()||ity==sty.end())
        // {
        //     cout<<i<<endl;
        //     break;
        // }
        int dx=itx->id,dy=ity->id;
        if(dx<=n/2&&dy<=n/2) a.push_back(i);
        else if(dx>n/2&&dy>n/2) b.push_back(i);
        else if(dx<=n/2&&dy>n/2) c.push_back(i);
        else d.push_back(i);
        stx.erase(itx),sty.erase(ity);
    }
    
    for(size_t i=0;i<a.size();i++)
        cout<<a[i]<<' '<<b[i]<<endl;
    for(size_t i=0;i<c.size();i++)
        cout<<c[i]<<' '<<d[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
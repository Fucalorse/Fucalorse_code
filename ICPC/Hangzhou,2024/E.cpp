#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90;

struct qwq
{
    LL l,r;
    int id;
}op[MAX];

bool cmp1(const qwq &a,const qwq &b) { return a.l<b.l; }
bool cmp2(const qwq &a,const qwq &b) { return a.r>b.r; }

int T,n;
LL f;

void solve()
{
    cin>>n>>f;

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].l>>op[i].r;
        op[i].id=i;

        ans+=op[i].r-op[i].l;
    }
    
    sort(op+1,op+n+1,cmp1);

    LL now=f;
    vector<int>id;
    vector<qwq>rest;

    for(int i=1;i<=n;)
    {
        while(i<=n&&op[i].l<=now)
        {
            if(op[i].r>=now)
            {
                id.push_back(op[i].id);
                now=op[i].r;
            }
            else rest.push_back(op[i]);

            ++i;
        }

        if(i<=n)
        {
            ans+=op[i].l-now;
            now=op[i].r;
            id.push_back(op[i].id);

            ++i;
        }
    }

    sort(rest.begin(),rest.end(),cmp2);

    for(auto &[l,r,now_id]:rest)
        id.push_back(now_id);

    cout<<ans<<endl;
    for(auto &i:id)
        cout<<i<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
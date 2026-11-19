#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
    bool operator<(const qwq &a)const { return x<a.x; }
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return {a.x-b.x,a.y-b.y}; }

LL Cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL Cal_Cross(const qwq &a,const qwq &b,const qwq &c) { return Cross(Vector(a,b),Vector(b,c)); }

int n,q;

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    sort(op+1,op+n+1);

    vector<qwq>st;
    vector<LL>rest;
    rest.push_back(0LL);

    for(int i=1;i<=n;i++)
    {
        while((int)st.size()>=2&&Cal_Cross(st[st.size()-2],st[st.size()-1],op[i])>=0) st.pop_back();

        if(i>1)
        {
            qwq a=st.back(),b=op[i];
            LL p=b.x*a.y-a.x*b.y,q=b.x-a.x;

            LL now;
            if(p>0) now=(p-1)/q+1;
            else now=p/q;

            rest.push_back(now);
        }

        st.push_back(op[i]);
    }

    sort(rest.begin(),rest.end());

    while(q--)
    {
        LL h;
        cin>>h;

        int ans=upper_bound(rest.begin(),rest.end(),h)-rest.begin();
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

LL cross(const qwq &a,const qwq &b) { return a.x*b.y-b.x*a.y; }

LL dot(const qwq &a,const qwq &b) { return a.x*b.x+a.y*b.y; }

LL cal_cross(const qwq &a,const qwq &b,const qwq &c) { return cross(Vector(a,b),Vector(b,c)); }

int n;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    if(n<=3)
    {
        cout<<"YES"<<endl;
        return;
    }

    auto check=[&](const int &pos,const qwq &base)
    {
        vector<qwq>rest;

        for(int i=1;i<=n;i++)
        {
            if(i==pos) continue;
            qwq now=Vector(op[i],op[pos]);
            if(cross(now,base)!=0) rest.push_back(op[i]);
        }

        int len=rest.size();
        if(len<=2) return true;

        qwq st=Vector(rest[0],rest[1]);
        for(int i=2;i<len;i++)
        {
            qwq now=Vector(rest[i],rest[0]);
            if(cross(st,now)!=0) return false;
        }

        return true;
    };

    for(int i=1;i<=3;i++)
        for(int j=i+1;j<=3;j++)
        {
            qwq base=Vector(op[i],op[j]);
            if(check(i,base))
            {
                cout<<"YES"<<endl;
                return;
            }
        }

    cout<<"NO"<<endl;
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
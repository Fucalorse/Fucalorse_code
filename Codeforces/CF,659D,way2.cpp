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

LL Cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL Cal_Cross(const qwq &a,const qwq &b,const qwq &c) { return Cross(Vector(a,b),Vector(b,c)); }

int n;

void solve()
{
    cin>>n;

    map<int,vector<int>>fx,fy;

    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;

        fx[op[i].x].push_back(i);
        fy[op[i].y].push_back(i);
    }

    vector<vector<int>>p(n+1);

    for(auto &[x,now]:fx)
    {
        sort(now.begin(),now.end(),[&](const int &a,const int &b){
            return op[a].y<op[b].y;
        });

        for(int i=0;i<(int)now.size();i+=2)
        {
            int u=now[i],v=now[i+1];
            p[u].push_back(v);
            p[v].push_back(u);
        }
    }
    
    for(auto &[y,now]:fy)
    {
        sort(now.begin(),now.end(),[&](const int &a,const int &b){
            return op[a].x<op[b].x;
        });

        for(int i=0;i<(int)now.size();i+=2)
        {
            int u=now[i],v=now[i+1];
            p[u].push_back(v);
            p[v].push_back(u);
        }
    }

    vector<int>rest;
    int st=1,aft=0;

    for(int i=2;i<=n;i++)
        if(op[i].y<op[st].y||(op[i].y==op[st].y&&op[i].x<op[st].x)) st=i;

    for(auto &to:p[st])
        if(op[to].x==op[st].x&&op[to].y>op[st].y) aft=to;

    int pre=st,now=aft;

    rest.push_back(st);

    while(now!=st)
    {
        rest.push_back(now);

        int nxt;
        if(pre!=p[now][0]) nxt=p[now][0];
        else nxt=p[now][1];

        pre=now;
        now=nxt;
    }

    int ans=0;
    for(int i=2;i<=n-1;i++)
        if(Cal_Cross(op[i-1],op[i],op[i+1])>0) ++ans;

    cout<<ans<<endl;
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
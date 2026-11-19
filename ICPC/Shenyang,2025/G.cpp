#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

struct qwq
{
    LL x,y;
    qwq operator+(const qwq &a)const { return {x+a.x,y+a.y}; }
    qwq operator-(const qwq &a)const { return {x-a.x,y-a.y}; }
    bool operator==(const qwq &a)const { return x==a.x&&y==a.y; }
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
};

int T,n,m;

LL cal_point(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL cal_area(vector<qwq>&op)
{
    LL ans=0;
    int len=op.size();

    for(int i=0;i<len;i++)
    {
        int j=(i+1)%len;
        ans+=cal_point(op[i],op[j]);
    }

    return llabs(ans);
}

vector<qwq> get_convex(vector<qwq>&op)
{
    sort(op.begin(),op.end());
    op.erase(unique(op.begin(),op.end()),op.end());

    if(op.size()<=1) return op;

    auto cross=[&](const qwq &a,const qwq &b,const qwq &c) { return cal_point(b-a,c-a); };

    vector<qwq>ans;

    for(auto cur:op)
    {
        while(ans.size()>=2&&cross(ans[ans.size()-2],ans[ans.size()-1],cur)<=0)
            ans.pop_back();
        ans.push_back(cur);
    }

    size_t pre_len=ans.size();

    for(int i=op.size()-2;i>=0;i--)
    {
        while(ans.size()>pre_len&&cross(ans[ans.size()-2],ans[ans.size()-1],op[i])<=0)
            ans.pop_back();
        ans.push_back(op[i]);
    }
    ans.pop_back();

    return ans;
}

void solve()
{
    cin>>n>>m;
    vector<qwq>P,Q,D;
    for(int i=1;i<=n;i++)
    {
        LL x,y;
        cin>>x>>y;
        P.push_back({x,y});
    }
    for(int i=1;i<=m;i++)
    {
        LL x,y;
        cin>>x>>y;
        Q.push_back({x,y});
    }

    for(auto i:P)
        for(auto j:Q)
            D.push_back(i-j);
    
    D=get_convex(D);
    double ans=(double)cal_area(P)*cal_area(Q)/(2.00*cal_area(D));

    cout<<fixed<<setprecision(18);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
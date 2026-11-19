#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int n,m,k,q;
LL x[MAX],y[MAX];

struct qwq
{
    LL p,q;
    bool updated;

    qwq():p(0),q(1),updated(false){}

    void update(LL np,LL nq)
    {
        if(!updated||np*q<p*nq)
        {
            updated=true;
            p=np;
            q=nq;
        }
    }

    LL cal(LL num)
    {
        if(!updated) return (LL)n+1;

        LL now=(num*p-1)/q+1;
        return min(now,(LL)n+1);
    }
};

void solve()
{
    cin>>n>>m>>k>>q;

    for(int i=1;i<=k;i++)
        cin>>x[i]>>y[i];

    vector<vector<LL>>op(m+1);
    while(q--)
    {
        for(int i=1;i<=m;i++)
            op[i].clear();

        int p;
        cin>>p;
        cin>>x[p]>>y[p];

        if(m==1)
        {
            LL minn=n+1;
            for(int i=1;i<=k;i++)
                minn=min(minn,x[i]);
            
            cout<<minn-1<<endl;
            continue;
        }

        for(int i=1;i<=k;i++)
            op[y[i]].push_back(x[i]);

        vector<LL>left(m+1,n+1),right(m+1,n+1);

        qwq best;
        for(int y=2;y<=m;y++)
        {
            for(auto &x:op[y])
                best.update(x,y-1);

            left[y]=best.cal(y-1);
        }

        best=qwq{};
        for(int y=m-1;y>=1;y--)
        {
            for(auto &x:op[y])
                best.update(x,m-y);

            right[y]=best.cal(m-y);
        }

        LL ans=0;
        for(int i=1;i<=m;i++)
            ans+=min(left[i],right[i])-1;

        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}
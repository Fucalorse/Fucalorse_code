#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1090,LEN=32,MOD=998244353,INF=2e9;

struct point
{
    LL x,y,z;
    bool operator<(const point &a)const
    {
        if(x!=a.x) return x<a.x;
        else if(y!=a.y) return y<a.y;
        else return z<a.z;
    }
    bool operator==(const point &a)const { return x==a.x&&y==a.y&&z==a.z; }
}st,ed,op[MAX];

int n,m;
LL a[MAX],b[MAX],c[MAX];

void solve()
{
    cin>>n>>m;
    cin>>st.x>>st.y>>st.z;
    cin>>ed.x>>ed.y>>ed.z;

    map<pair<LL,LL>,vector<LL>>f;
    for(int i=1;i<=n;i++)
    {
        LL x,y,z;
        cin>>x>>y>>z;
        f[{x,y}].push_back(z);
    }

    for(auto &[cur,vec]:f)
        sort(vec.begin(),vec.end());

    for(int i=1;i<=m;i++)
        cin>>a[i]>>b[i]>>c[i];

    auto find=[&](LL x,LL y,LL z)
    {
        if(f.count({x,y})==0) return -1LL;

        vector<LL>&op=f[{x,y}];
        int len=op.size();
        int l=0,r=len-1;

        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(op[mid]<z) l=mid+1;
            else r=mid-1;
        }

        if(r==-1) return -1LL;
        else
        {
            if(r<len-1&&op[r+1]==z) return -1LL;
            else return op[r];
        }
    };

    auto bfs=[&]()
    {
        set<point>vis;
        queue<pair<point,LL>>q;
        q.push({st,0}),vis.insert(st);

        while(q.size())
        {
            auto [cur,step]=q.front();q.pop();
            auto [x,y,z]=cur;

            // cout<<x<<' '<<y<<' '<<z<<endl;
            if(cur==ed) return step;

            for(int i=1;i<=m;i++)
            {
                LL nx=x+a[i],ny=y+b[i],nz=z+c[i];
                LL d=find(nx,ny,nz);
                if(d!=-1)
                {
                    // cout<<nx<<' '<<ny<<' '<<d+1<<endl;
                    point nxt={nx,ny,d+1};
                    if(vis.count(nxt)) continue;
                    vis.insert(nxt);
                    q.push({nxt,step+1});
                }
            }
        }

        return -10086LL;
    };

    LL ans=bfs();
    if(ans<0) cout<<-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
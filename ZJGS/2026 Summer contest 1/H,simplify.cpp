#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+90,LEN=1e6,MOD=998244353,INF=1e9;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return num.size(); }
};

struct point
{
    int x,y;
};

struct peach
{
    private:
        int n;
        vector<vector<int>>pos,tree;
    public:
        peach(int _n,const vector<point>& op)
        {
            n=_n;
            pos.assign(n+1,vector<int>{});
            tree.assign(n+1,vector<int>{});

            for(auto &[x,y]:op)
                for(int i=x;i<=n;i+=i&-i)
                    pos[i].push_back(y);

            for(int i=1;i<=n;i++)
            {
                sort(pos[i].begin(),pos[i].end());
                pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
                tree[i].assign((int)pos[i].size()+1,INF);
            }
        }

        void update(int x,int y,int id)
        {
            for(int i=x;i<=n;i+=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank;j<(int)tree[i].size();j+=j&-j)
                    tree[i][j]=min(tree[i][j],id);
            }
        }

        int query(int x,int y)
        {
            int ans=INF;

            for(int i=x-1;i;i-=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank-1;j;j-=j&-j)
                    ans=min(ans,tree[i][j]);
            }

            return ans;
        }
};

struct qwq
{
    int f[4],id;
}op[MAX];

int n;
int a[MAX],sum[MAX][4];

int cal(int num,discrete &dis)
{
    int d0=num,d1=(num+1)&3,d2=(num+2)&3,d3=(num+3)&3;

    sort(op,op+n+1,[&](const qwq &a,const qwq &b){
        int fa=a.f[d0]-a.f[d1],fb=b.f[d0]-b.f[d1];

        if(fa!=fb) return fa<fb;
        return a.id<b.id;
    });

    vector<point>rest;

    for(int i=0;i<=n;i++)
    {
        int x=dis.find(op[i].f[d0]-op[i].f[d2]),y=dis.find(op[i].f[d0]-op[i].f[d3]);
        rest.push_back({x,y});
    }

    int ans=0;
    peach fu(dis.size(),rest);

    for(int l=0,r=0;l<=n;l=r)
    {
        int val=op[l].f[d0]-op[l].f[d1];
        while(r<=n&&op[r].f[d0]-op[r].f[d1]==val) ++r;

        for(int i=l;i<r;i++)
        {
            int now=fu.query(rest[i].x,rest[i].y);
            if(now!=INF) ans=max(ans,op[i].id-now);
        }

        for(int i=l;i<r;i++)
            fu.update(rest[i].x,rest[i].y,op[i].id);
    }

    return ans;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    discrete dis;
    dis.add(0);

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=3;j++)
            sum[i][j]=sum[i-1][j];
        sum[i][a[i]]++;

        for(int j=0;j<=3;j++)
            op[i].f[j]=sum[i][j];
        op[i].id=i;

        for(int j=0;j<=3;j++)
            for(int k=0;k<=3;k++)
            {
                if(j==k) continue;
                dis.add(sum[i][j]-sum[i][k]);
            }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=3;j++)
    //         cout<<op[i].f[j]<<' ';
    //     cout<<endl;
    // }

    dis.create();

    // cout<<cal(0,dis)<<endl;
    cout<<cal(0,dis)<<' '<<cal(1,dis)<<' '<<cal(2,dis)<<' '<<cal(3,dis)<<endl;
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
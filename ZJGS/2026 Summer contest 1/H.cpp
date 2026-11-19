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
    int x,y,id;
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

            for(auto &[x,y,id]:op)
                for(int i=x;i<=n;i+=i&-i)
                    pos[i].push_back(y);

            for(int i=1;i<=n;i++)
            {
                sort(pos[i].begin(),pos[i].end());
                pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
                tree[i].assign(pos[i].size()+1,INF);
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
    int f0,f1,f2,f3,id;
}op[MAX];

bool cmp0(const qwq &a,const qwq &b)
{
    int fa=a.f0-a.f1,fb=b.f0-b.f1;
    if(fa!=fb) return fa<fb;
    return a.id<b.id;
}

bool cmp1(const qwq &a,const qwq &b)
{
    int fa=a.f1-a.f0,fb=b.f1-b.f0;
    if(fa!=fb) return fa<fb;
    return a.id<b.id;
}

bool cmp2(const qwq &a,const qwq &b)
{
    int fa=a.f2-a.f0,fb=b.f2-b.f0;
    if(fa!=fb) return fa<fb;
    return a.id<b.id;
}

bool cmp3(const qwq &a,const qwq &b)
{
    int fa=a.f3-a.f0,fb=b.f3-b.f0;
    if(fa!=fb) return fa<fb;
    return a.id<b.id;
}

int n;
int a[MAX],sum[MAX][5];

int cal_0(discrete& dis)
{
    sort(op,op+n+1,cmp0);

    vector<point>rest;

    for(int i=0;i<=n;i++)
    {
        int x=dis.find(op[i].f0-op[i].f2),y=dis.find(op[i].f0-op[i].f3);
        rest.push_back({x,y,op[i].id});
    }

    int ans=0;
    peach fu((int)dis.size(),rest);

    for(int l=0,r=0;l<=n;l=r)
    {
        int st=op[l].f0-op[l].f1;
        while(r<=n&&op[r].f0-op[r].f1==st) r++;

        for(int i=l;i<r;i++)
        {
            int now=fu.query(rest[i].x,rest[i].y);
            if(now!=INF) ans=max(ans,rest[i].id-now);
        }

        for(int i=l;i<r;i++)
            fu.update(rest[i].x,rest[i].y,rest[i].id);
    }

    return ans;
}

int cal_1(discrete& dis)
{
    sort(op,op+n+1,cmp1);

    vector<point>rest;

    for(int i=0;i<=n;i++)
    {
        int x=dis.find(op[i].f1-op[i].f2),y=dis.find(op[i].f1-op[i].f3);
        rest.push_back({x,y,op[i].id});
    }

    int ans=0;
    peach fu(dis.size(),rest);

    for(int l=0,r=0;l<=n;l=r)
    {
        int st=op[l].f1-op[l].f0;
        while(r<=n&&op[r].f1-op[r].f0==st) ++r;

        for(int i=l;i<r;i++)
        {
            int now=fu.query(rest[i].x,rest[i].y);
            if(now!=INF) ans=max(ans,rest[i].id-now);
        }

        for(int i=l;i<r;i++)
            fu.update(rest[i].x,rest[i].y,rest[i].id);
    }

    return ans;
}

int cal_2(discrete &dis)
{
    sort(op,op+n+1,cmp2);

    vector<point>rest;
    
    for(int i=0;i<=n;i++)
    {
        int x=dis.find(op[i].f2-op[i].f1),y=dis.find(op[i].f2-op[i].f3);
        rest.push_back({x,y,op[i].id});
    }

    int ans=0;
    peach fu(dis.size(),rest);

    for(int l=0,r=0;l<=n;l=r)
    {
        int st=op[l].f2-op[l].f0;
        while(r<=n&&op[r].f2-op[r].f0==st) ++r;

        for(int i=l;i<r;i++)
        {
            int now=fu.query(rest[i].x,rest[i].y);
            if(now!=INF) ans=max(ans,rest[i].id-now);
        }

        for(int i=l;i<r;i++)
            fu.update(rest[i].x,rest[i].y,rest[i].id);
    }

    return ans;
}

int cal_3(discrete &dis)
{
    sort(op,op+n+1,cmp3);

    vector<point>rest;
    
    for(int i=0;i<=n;i++)
    {
        int x=dis.find(op[i].f3-op[i].f1),y=dis.find(op[i].f3-op[i].f2);
        rest.push_back({x,y,op[i].id});
    }

    int ans=0;
    peach fu(dis.size(),rest);

    for(int l=0,r=0;l<=n;l=r)
    {
        int st=op[l].f3-op[l].f0;
        while(r<=n&&op[r].f3-op[r].f0==st) ++r;

        for(int i=l;i<r;i++)
        {
            int now=fu.query(rest[i].x,rest[i].y);
            if(now!=INF) ans=max(ans,rest[i].id-now);
        }

        for(int i=l;i<r;i++)
            fu.update(rest[i].x,rest[i].y,rest[i].id);
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
    op[0]={0,0,0,0,0};
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=3;j++)
            sum[i][j]=sum[i-1][j];
        sum[i][a[i]]=sum[i-1][a[i]]+1;

        op[i]={sum[i][0],sum[i][1],sum[i][2],sum[i][3],i};
        
        for(int j=0;j<=3;j++)
            for(int k=0;k<=3;k++)
            {
                if(j==k) continue;
                dis.add(sum[i][j]-sum[i][k]);
            }
    }

    dis.create();

    cout<<cal_0(dis)<<' '<<cal_1(dis)<<' '<<cal_2(dis)<<' '<<cal_3(dis)<<endl;
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
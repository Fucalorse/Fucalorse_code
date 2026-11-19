#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=2e9;

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

        int size() { return (int)num.size(); }
};

struct point
{
    int x,y;
};

struct peach
{
    private:
        int n;
        vector<vector<int>>pos;
        vector<vector<LL>>tree;
    public:
        peach(int _n,const vector<point>& op)
        {
            n=_n;
            pos.assign(n+1,vector<int>{});
            tree.assign(n+1,vector<LL>{});

            for(auto &[x,y]:op)
                for(int i=x;i<=n;i+=i&-i)
                    pos[i].push_back(y);

            for(int i=1;i<=n;i++)
            {
                sort(pos[i].begin(),pos[i].end());
                pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
                tree[i].assign((int)pos[i].size()+1,0);
            }
        }

        void update(int x,int y,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank;j<(int)tree[i].size();j+=j&-j)
                    tree[i][j]+=k;
            }
        }

        LL query(int x,int y)
        {
            LL ans=0;

            for(int i=x;i;i-=i&-i)
            {
                int rank=upper_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin();

                for(int j=rank;j;j-=j&-j)
                    ans+=tree[i][j];
            }

            return ans;
        }
};

struct qwq
{
    int a,b,c,id;
    bool operator<(const qwq &other)const { return a<other.a; }
}op[MAX];

int n,k;
LL ans[MAX];

void solve()
{
    cin>>n>>k;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].a>>op[i].b>>op[i].c;
        dis.add(op[i].a),dis.add(op[i].b),dis.add(op[i].c);
        op[i].id=i;
    }

    dis.create();
    sort(op+1,op+n+1);

    vector<point>rest;
    for(int i=1;i<=n;i++)
    {
        int x=dis.find(op[i].b),y=dis.find(op[i].c);
        rest.push_back({x,y});
    }

    peach fu(dis.size(),rest);
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&op[l].a==op[r].a) r++;

        for(int i=l;i<r;i++)
            fu.update(rest[i-1].x,rest[i-1].y,1);

        for(int i=l;i<r;i++)
        {
            LL now=fu.query(rest[i-1].x,rest[i-1].y)-1;
            ans[now]++;
        }
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<endl;
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
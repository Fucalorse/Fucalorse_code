#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

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
        vector<vector<int>>tree,pos;
    public:
        peach(int _n,const vector<point>& op)
        {
            n=_n;
            tree.assign(n+1,vector<int>{});
            pos.assign(n+1,vector<int>{});

            for(const auto &[x,y]:op)
                for(int i=x;i<=n;i+=i&-i)
                    pos[i].push_back(y);

            for(int i=1;i<=n;i++)
            {
                sort(pos[i].begin(),pos[i].end());
                pos[i].erase(unique(pos[i].begin(),pos[i].end()),pos[i].end());
                tree[i].assign((int)pos[i].size()+1,-INF);
            }
        }

        void update(int x,int y,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank;j<(int)tree[i].size();j+=j&-j)
                    tree[i][j]=max(tree[i][j],k);
            }
        }

        int query(int x,int y)
        {
            int ans=-INF;
            for(int i=x;i;i-=i&-i)
            {
                int rank=upper_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin();

                for(int j=rank;j;j-=j&-j)
                    ans=max(ans,tree[i][j]);
            }
            return ans;
        }
};

int n;
int r[MAX],y[MAX],b[MAX],fr[MAX],fy[MAX],fb[MAX],X[MAX],Y[MAX];

void solve()
{
    cin>>n;

    discrete dis;
    dis.add(0);

    for(int i=1;i<=n;i++)
    {
        cin>>r[i]>>y[i]>>b[i];

        fr[i]=fr[i-1]+r[i];
        fy[i]=fy[i-1]+y[i];
        fb[i]=fb[i-1]+b[i];

        dis.add(fr[i]-fy[i]);
        dis.add(fr[i]-fb[i]);
    }

    dis.create();

    vector<point>op;
    for(int i=0;i<=n;i++)
    {
        X[i]=dis.find(fr[i]-fy[i]);
        Y[i]=dis.find(fr[i]-fb[i]);
        op.push_back({X[i],Y[i]});
    }

    peach fu(dis.size(),op);
    vector<int>dp(n+1,-INF);

    dp[0]=0;
    fu.update(X[0],Y[0],dp[0]-0);

    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];

        int now=fu.query(X[i],Y[i]);
        if(now!=-INF) dp[i]=max(dp[i],now+i);
        fu.update(X[i],Y[i],dp[i]-i);
    }

    cout<<dp[n]<<endl;
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
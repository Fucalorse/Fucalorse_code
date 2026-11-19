#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353,INF=2e9;

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

        void update(int x,int y,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
            {
                int rank=lower_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin()+1;

                for(int j=rank;j<(int)tree[i].size();j+=j&-j)
                    tree[i][j]=min(tree[i][j],k);
            }
        }

        int query(int x,int y)
        {
            int ans=INF;
            for(int i=x;i;i-=i&-i)
            {
                int rank=upper_bound(pos[i].begin(),pos[i].end(),y)-pos[i].begin();

                for(int j=rank;j;j-=j&-j)
                    ans=min(ans,tree[i][j]);
            }
            return ans;
        }
};

struct qwq
{
    int pos;
    int x,y,z;
};

int n;
int A[MAX],f[MAX][4],pu[MAX],pv[MAX],pw[MAX];

void clear()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<4;j++)
            f[i][j]=0;
}

int cal(int col,discrete& dis)
{
    int p=col,u=(col+1)%4,v=(col+2)%4,w=(col+3)%4;
    
    vector<qwq>rest;
    vector<point>op;

    for(int i=0;i<=n;i++)
    {
        pu[i]=dis.find(f[i][p]-f[i][u]);
        pv[i]=dis.find(f[i][p]-f[i][v]);
        pw[i]=dis.find(f[i][p]-f[i][w]);
        rest.push_back({i,pu[i],pv[i],pw[i]});
        op.push_back({pv[i],pw[i]});
    }

    sort(rest.begin(),rest.end(),[&](const qwq &a,const qwq &b){
        if(a.x!=b.x) return a.x<b.x;
        return a.pos>b.pos;
    });

    peach fu(dis.size(),op);
    int ans=0;
    
    for(auto &cur:rest)
    {
        int now=fu.query(cur.y-1,cur.z-1);
        if(now!=INF)
        {
            int con=cur.pos-now;
            ans=max(ans,con);
        }
        fu.update(cur.y,cur.z,cur.pos);
    }

    return ans;
}

void solve()
{
    cin>>n;clear();

    discrete dis;
    dis.add(0);

    for(int i=1;i<=n;i++)
    {
        cin>>A[i];

        for(int j=0;j<4;j++)
            f[i][j]=f[i-1][j];

        f[i][A[i]]++;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                if(j==k) continue;
                dis.add(f[i][j]-f[i][k]);
            }
    }

    dis.create();

    for(int i=0;i<4;i++)
        cout<<cal(i,dis)<<' ';
    cout<<endl;
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
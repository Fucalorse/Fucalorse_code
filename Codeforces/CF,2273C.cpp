#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1090,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct Bit
{
    private:
        int n,m;
        vector<vector<int>>op;
    public:
        Bit(int _n,int _m):n(_n),m(_m),op(_n+1,vector<int>(_m+1,0)){}

        void update(int x,int y,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
                for(int j=y;j<=m;j+=j&-j)
                    op[i][j]+=k;
        }

        int query(int x,int y)
        {
            int ans=0;
            for(int i=x;i;i-=i&-i)
                for(int j=y;j;j-=j&-j)
                    ans+=op[i][j];
            return ans;
        }

        int query_rectangle(int r1,int c1,int r2,int c2)
        {
            if(r1>r2||c1>c2) return 0;
            return query(r2,c2)-query(r1-1,c2)-query(r2,c1-1)+query(r1-1,c1-1);
        }
};

int n,q;
LL a[MAX][MAX],b[MAX][MAX],d[MAX][MAX],f[MAX][MAX];

void solve()
{
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];

    Bit fu(n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            f[i][j]=b[i][j]-a[i][j];
            if(i>=2&&j>=2)
            {
                d[i][j]=f[i][j]+f[i-1][j-1]-f[i-1][j]-f[i][j-1];
                fu.update(i,j,d[i][j]!=0);
            }
        }

    auto update=[&](int r,int c,LL dx)->void
    {
        if(r<2||c<2||r>n||c>n) return;
        int pre=d[r][c]!=0;
        d[r][c]+=dx;
        int now=d[r][c]!=0;
        fu.update(r,c,now-pre);
    };

    while(q--)
    {
        char c;
        cin>>c;

        if(c=='U')
        {
            LL x;
            int r1,c1,r2,c2;
            cin>>r1>>c1>>r2>>c2>>x;
            update(r1,c1,-x);
            update(r1,c2+1,x);
            update(r2+1,c1,x);
            update(r2+1,c2+1,-x);
        }
        else
        {
            int r1,c1,r2,c2;
            cin>>r1>>c1>>r2>>c2;
            int cnt=fu.query_rectangle(r1+1,c1+1,r2,c2);
            cout<<(cnt==0?"YES":"NO")<<endl;
        }
    }
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
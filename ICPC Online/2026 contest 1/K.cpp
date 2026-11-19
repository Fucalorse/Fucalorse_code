#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            array<array<int,2>,2>f;

            qwq():f{}{}

            qwq operator*(const qwq &a)const
            {
                qwq now=qwq();
                for(int i=0;i<=1;i++)
                    for(int k=0;k<=1;k++)
                        for(int j=0;j<=1;j++)
                            now.f[i][j]|=f[i][k]&a.f[k][j];
                return now;
            }
        };

        int n;
        vector<qwq>op;

        void create(int l,int r,int id,const vector<pair<int,int>>& rest)
        {
            if(l==r)
            {
                op[id].f[0][0]=rest[l].first;
                op[id].f[0][1]=rest[l].second;
                op[id].f[1][0]=1;
                op[id].f[1][1]=0;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,rest);
            create(mid+1,r,hr,rest);

            op[id]=op[hr]*op[hl];
        }

        void dfs(int l,int r,int id,const int &pos,const int &x,const int &y,const int &k)
        {
            if(l==r)
            {
                op[id].f[x][y]=k;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(pos<=mid) dfs(l,mid,hl,pos,x,y,k);
            else dfs(mid+1,r,hr,pos,x,y,k);

            op[id]=op[hr]*op[hl];
        }
    public:
        peach(int _n,const vector<pair<int,int>>& rest)
        {
            n=_n;
            op.assign((n+90)<<2,qwq{});
            create(1,n,1,rest);
        }

        void update(int pos,int x,int y,int k) { dfs(1,n,1,pos,x,y,k); }

        int query() { return op[1].f[0][0]; }
};

int n;
string s;
int b[MAX],c[MAX];

void solve()
{
    cin>>n>>s;s='L'+s,s=s+'R';

    b[0]=b[n+1]=0;
    for(int i=1;i<=n;i++)
        cin>>b[i];

    vector<pair<int,int>>rest(n+2,{0,0});
    vector<vector<int>>A(n+1),B(n+1);

    for(int i=1;i<=n+1;i++)
    {
        if(s[i]==s[i-1])
        {
            if(b[i]==b[i-1]) rest[i].first=1;
            else rest[i].first=0;
        }
        else
        {
            int cnt=b[i-1]+b[i];
            if(cnt>=0&&cnt<=n) A[cnt].push_back(i);
        }

        if(i>1)
        {
            if(s[i]==s[i-2])
            {
                if(s[i]=='L'&&b[i-2]+1==b[i]) rest[i].second=1;
                else if(s[i]=='R'&&b[i-2]==b[i]+1) rest[i].second=1;
                else rest[i].second=0;
            }
            else
            {
                int cnt=b[i-2]+b[i];
                if(s[i-2]=='L'&&s[i]=='R') ++cnt;
                else --cnt;

                if(cnt>=0&&cnt<=n) B[cnt].push_back(i);
            }
        }
    }

    int ans=-1;
    peach fu(n+1,rest);

    for(int k=0;k<=n;k++)
    {
        for(const auto &pos:A[k])
            fu.update(pos,0,0,1);
        for(const auto &pos:B[k])
            fu.update(pos,0,1,1);

        if(fu.query())
        {
            ans=k;
            break;
        }

        for(const auto &pos:A[k])
            fu.update(pos,0,0,0);
        for(const auto &pos:B[k])
            fu.update(pos,0,1,0);
    }

    if(ans==-1) cout<<-1<<endl;
    else
    {
        vector<int>dp(n+2,0),pre(n+2,0);
        dp[0]=1;

        c[0]=0,c[n+1]=ans;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='L') c[i]=b[i];
            else c[i]=ans-b[i];
        }

        for(int i=1;i<=n+1;i++)
        {
            dp[i]|=dp[i-1]&(c[i]==c[i-1]);
            if(dp[i]) pre[i]=i-1;

            if(i>1)
            {
                dp[i]|=dp[i-2]&(c[i]==c[i-2]+1);
                if(dp[i-2]&(c[i]==c[i-2]+1)) pre[i]=i-2;
            }
        }

        vector<int>ok(n+2,1);
        for(int i=n+1;i;i=pre[i])
            ok[i]=0;

        for(int i=1;i<=n;i++)
            cout<<ok[i];
        cout<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct qwq
{
    int id;
    LL a,b,c;
    bool operator<(const qwq &other)const
    {
        if(a!=other.a) return a<other.a;
        return c<other.c;
    }
    bool operator>(const qwq &other)const
    {
        if(a!=other.a) return a>other.a;
        return c>other.c;
    }
};

bool not_intersect(const qwq &f,const qwq &g)
{
    LL a=f.a-g.a,b=f.b-g.b,c=f.c-g.c;
    if(a==0) return b==0&&c!=0;
    else return b*b-4*a*c<0;
}

int n;

template <typename T>
vector<int> get_dp(vector<qwq>& op,T func)
{
    int len=(int)op.size();
    sort(op.begin()+1,op.end(),func);
    vector<int>dp(len+1,1);

    for(int i=1;i<len;i++)
        for(int j=1;j<i;j++)
            if(not_intersect(op[i],op[j])) dp[i]=max(dp[i],dp[j]+1);
    
    return dp;    
}

void solve()
{
    cin>>n;
    
    vector<qwq>op(n+1);
    for(int i=1;i<=n;i++)
    {
        op[i].id=i;
        cin>>op[i].a>>op[i].b>>op[i].c;
    }

    vector<int>ans(n+1,0);
    vector<int>up=get_dp(op,greater<qwq>());
    for(int i=1;i<=n;i++)
        ans[op[i].id]=up[i];

    vector<int>down=get_dp(op,less<qwq>());
    for(int i=1;i<=n;i++)
        ans[op[i].id]=ans[op[i].id]+down[i]-1;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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
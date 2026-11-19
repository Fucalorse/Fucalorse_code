#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=3e5+90,LEN=31,MOD=998244353,INF=2e9;
const vector<vector<int>>h={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};

istream& operator>>(istream& in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f==-1) x=-x;

    return in;
}

ostream& operator<<(ostream& out,i128 x)
{
    if(x==0)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

LL qpow(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}


vector<vector<LL>> merge(const vector<vector<LL>>& a,const vector<vector<LL>>& b)
{
    int n=a.size();
    vector<vector<LL>>ans(n,vector<LL>(n,0));

    for(int i=0;i<n;i++)
        for(int k=0;k<n;k++)
            for(int j=0;j<n;j++)
                ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%MOD)%MOD;

    return ans;
}

vector<vector<LL>> cal(vector<vector<LL>> a,int p)
{
    int n=a.size();
    vector<vector<LL>>ans(n,vector<LL>(n,0));

    for(int i=0;i<n;i++)
        ans[i][i]=1;

    while(p)
    {
        if(p&1) ans=merge(ans,a);
        a=merge(a,a);
        p>>=1;
    }

    return ans;
}

int n,m;
vector<vector<int>>state;
vector<int>op={0,1};

void dfs()
{
    if((int)op.size()==n)
    {
        state.push_back(op);
        return;
    }

    for(int i=0;i<3;i++)
    {
        if(i==op.back()) continue;

        op.push_back(i);
        dfs();
        op.pop_back();
    }
}

void solve()
{
    cin>>n>>m;

    if(n==1)
    {
        LL ans=3*qpow(2LL,m-1)%MOD;
        cout<<ans<<endl;
        return;
    }

    dfs();

    auto check=[&](const vector<int>& a,const vector<int>& b,const vector<int>& rev)
    {
        int len=a.size();

        for(int i=0;i<len;i++)
            if(a[i]==rev[b[i]]) return false;

        return true;
    };

    int len=state.size();
    vector<vector<LL>>a(len,vector<LL>(len,0));
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
        {
            for(auto &rev:h)
                if(check(state[i],state[j],rev)) ++a[i][j];
        }

    // for(int i=0;i<len;i++)
    // {
    //     for(int j=0;j<len;j++)
    //         cout<<a[i][j]<<' ';
    //     cout<<endl;
    // }

    i128 ans=0;
    vector<vector<LL>>dp=cal(a,m-1);
    for(int i=0;i<len;i++)
        for(int j=0;j<len;j++)
            ans+=dp[i][j]*6;

    cout<<ans%MOD<<endl;
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
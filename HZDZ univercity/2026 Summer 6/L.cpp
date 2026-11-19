#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i128 __int128
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

istream &operator>>(istream& in,i128 &x)
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

    if(f<0) x=-x;

    return in;
}

ostream &operator<<(ostream& out,i128 x)
{
    if(!x)
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

int n;
int fa[MAX];
i128 a[MAX];

void dfs(int ch,int fa,vector<vector<int>>& p,vector<int>& base)
{
    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        int con=ch!=1&&ch<to;
        base[to]=base[ch]+con;
        dfs(to,ch,p,base);
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<int>>p(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>fa[i];
        p[fa[i]].push_back(i);
    }

    vector<int>base(n+1,0);
    dfs(1,0,p,base);

    i128 sum=0,other=0;
    for(int i=2;i<=n;i++)
    {
        sum+=a[i];
        other+=a[i]*base[i];
    }

    if(sum==0)
    {
        if(other>0) cout<<-1<<endl;
        else if(other<0) cout<<1<<endl;
        else cout<<0<<endl;
    }
    else if(sum>0) cout<<1<<endl;
    else cout<<-1<<endl;
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
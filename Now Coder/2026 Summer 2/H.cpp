#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+10,LEN=30,MOD=998244353,INF=1e9;

int n,a,b;

void dfs(int mask,int st,int ed,vector<int>& ans)
{
    if(__builtin_popcount(mask)==1)
    {
        ans.push_back(st);
        ans.push_back(ed);
        return;
    }

    int c=__builtin_ctz((st^ed)&mask);
    int rest=mask^(1<<c);
    int j=__builtin_ctz(rest);
    int x=st^(1<<j),y=x^(1<<c);

    dfs(rest,st,x,ans);
    dfs(rest,y,ed,ans);
}

int fade(int x,int k)
{
    int mask=(1<<k)-1;
    int high=x>>(k+1),low=mask&x;
    int ans=(high<<k)|low;
    return ans;
}

int reborn(int x,int k,int parity)
{
    int mask=(1<<k)-1;
    int high=x>>k,low=mask&x;
    int ans=low|(high<<(k+1));

    int bit=parity^(__builtin_popcount(x)&1);
    ans|=bit<<k;

    return ans;
}

void solve()
{
    cin>>n>>a>>b;

    int sa=__builtin_popcount(a)&1,sb=__builtin_popcount(b)&1;

    if(sa!=sb)
    {
        cout<<"NO"<<endl;
        return;
    }

    int k=__builtin_ctz(a^b);
    int total=1<<(n-1);
    int mask=total-1;
    int st=fade(a,k),ed=fade(b,k);

    vector<int>ans;
    dfs(mask,st,ed,ans);

    int len=ans.size();

    cout<<"YES"<<endl;
    for(int i=1;i<len-1;i+=2)
    {
        int x=reborn(ans[i],k,sa),y=reborn(ans[i+1],k,sa);
        cout<<x<<' '<<y<<endl;
    }
    for(int i=0;i<total;i+=2)
    {
        int x=reborn(i,k,sa^1),y=reborn(i^1,k,sa^1);
        cout<<x<<' '<<y<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while (T--) solve();

    return 0;
}
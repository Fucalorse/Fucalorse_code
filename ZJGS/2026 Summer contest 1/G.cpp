#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=110,LEN=1e6,MOD=998244353,INF=2e9;

vector<int>get(LL x)
{
    vector<int>ans;

    while(x%2==0)
    {
        x>>=1;
    }

    while(x)
    {
        ans.push_back(x&1);
        x>>=1;
    }

    return ans;
}

LL n,a,b;

void solve()
{
    cin>>n>>a>>b;

    if(a!=b)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(!a&&!b)
    {
        cout<<"YES"<<endl;
        return;
    }

    if((n&(n-1))==0)
    {
        cout<<"YES"<<endl;
        return;
    }

    vector<int>op=get(n);
    int c0=INF,c1=INF,len=(int)op.size();
    for(int l=0,r=0;l<len;l=r)
    {
        while(r<len&&op[l]==op[r]) r++;

        if(op[l]==1) c1=min(c1,r-l);
        else c0=min(c0,r-l);
    }

    if(c0>=2||c1>=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e6,MOD=998244353;
const LL INF=1e12;

int n;
int minp[MAX];
LL ans[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1;

    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

void create()
{
    oula(LEN);

    int len=1e4,tot=0;
    for(int i=0;i<(int)op.size()-1&&tot<len;i++)
    {
        LL now=1LL*op[i]*op[i+1];
        ans[++tot]=now;
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
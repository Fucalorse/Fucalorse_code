#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,MOD=998244353,INF=2e9;

int n;
int minp[MAX],cnt[MAX],num[MAX];
vector<int>op;

void oula(int n)
{
    minp[1]=1,cnt[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            cnt[i]=num[i]=1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            cnt[i*j]=cnt[i]+1;
            num[i*j]=num[i];
            if(i%j==0) break;
            num[i*j]++;
        }
    }
}

void solve()
{
    cin>>n;
    
    cout<<cnt[n]+num[n]-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);

    // for(int i=1;i<=10;i++)
    //     cout<<num[i]<<' ';
    // cout<<endl;

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
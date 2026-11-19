#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,mod=998244353,LEN=1e7;

int t,n;
LL a[MAX],b[MAX],phi[LEN+90],minp[LEN+90];
vector<int>op;

void oula(int n)
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            phi[i]=i-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0)
            {
                phi[i*j]=phi[i]*j;
                break;
            }
            else phi[i*j]=phi[i]*(j-1);
        }
    }
}

LL cal(LL a,int p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

LL inv(LL a) { return cal(a,mod-2); }

LL determinant(vector<vector<LL>>&op)
{
    LL ans=1;
    for(int i=0;i<n;i++)
    {
        int pos=i;
        while(pos<n&&op[pos][i]==0) ++pos;
        if(pos==n) return 0;
        // cout<<pos<<' ';
        if(pos!=i)
        {
            swap(op[pos],op[i]);
            ans=(mod-ans)%mod;
        }
        for(int j=i+1;j<n;j++)
        {
            if(op[j][i]==0) continue;
            LL p=op[j][i]*inv(op[i][i])%mod;
            for(int k=i;k<n;k++)
            {
                op[j][k]=(op[j][k]-p*op[i][k])%mod;
                if(op[j][k]<0) op[j][k]+=mod;
            }
        }
        // cout<<op[i][i]<<' ';
        ans=ans*op[i][i]%mod;
    }
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    if(n>50)
    {
        cout<<0<<endl;
        return;
    }
    vector<vector<LL>>c(n,vector<LL>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=(a[i+1]^b[j+1])*(phi[a[i+1]]+phi[b[j+1]])%mod;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout<<c[i][j]<<' ';
    //     cout<<endl;
    // }
    cout<<determinant(c)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    oula(LEN);
    // for(auto &i:op)
    //     cout<<i<<endl;
    cin>>t;
    while(t--) solve();
    return 0;
}
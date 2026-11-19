#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int minp[MAX];
vector<int>op;
void oula(int n)
{
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

int a[5],n;

map<int,int> split(int x)
{
    map<int,int>f;
    for(auto &cur:op)
    {
        if(1LL*cur*cur>x) break;
        if(x%cur!=0) continue;
        while(x%cur==0)
        {
            ++f[cur];
            x/=cur;
        }
    }
    if(x>1) ++f[x];
    return f;
}

void solve()
{
    cin>>a[1]>>a[2]>>a[3]>>n;
    
    i128 total=(i128)a[1]*a[2]*a[3];
    if(total%n!=0)
    {
        cout<<-1<<endl;
        return;
    }

    i128 each=total/n;
    vector<LL>ans(4,1LL);
    for(int i=1;i<=3;i++)
    {
        map<int,int>f=split(a[i]);
        for(auto &[prime,cnt]:f)
        {
            if(each==1) break;
            for(int k=1;k<=cnt;k++)
                if(each%prime==0)
                {
                    ans[i]*=prime;
                    each/=prime;
                }
        }

        if(each==1) break;
    }

    if(each!=1)
    {
        cout<<-1<<endl;
        return;
    }

    for(int i=1;i<=3;i++)
        cout<<a[i]/ans[i]-1<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=1e5;

int T,n;
int ans[MAX],minp[MAX];
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
            if((LL)i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

void solve()
{
    cin>>n;

    int p,st=n/3,ed=2*n/3+(2*n%3?1:0);
    for(auto &i:op)
        if(i>=st&&i<=ed)
        {
            p=i;
            break;
        }
    ans[1]=p;
    for(int i=2;i<=(p-1)*2+1;i++)
    {
        int dx=i/2;
        if(i&1) ans[i]=p+dx;
        else ans[i]=p-dx;
    }
    for(int i=2*p;i<=n;i++)
        ans[i]=i;
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    oula(LEN);
    cin>>T;
    while(T--) solve();
    return 0;
}
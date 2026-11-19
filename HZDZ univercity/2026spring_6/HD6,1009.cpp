#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=31;

int t,n,m;
int f[LEN+3];

void update(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return;
            }
            x^=f[i];
        }
}

int cal(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i&1)&&f[i]) x^=f[i];
    return x;
}

void solve()
{
    cin>>n>>m;
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        update(u^v^val);
    }
    cout<<cal(1^n)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
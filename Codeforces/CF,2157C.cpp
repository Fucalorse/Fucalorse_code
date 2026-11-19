#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct interval
{
    int c,l,r;
}op[MAX];

int t,n,k,q;
int ans[MAX];

void solve()
{
    cin>>n>>k>>q;
    vector<int>f(n+3,0),g(n+3,0);
    vector<bool>mex(n+3,false);
    for(int i=1;i<=q;i++)
    {
        cin>>op[i].c>>op[i].l>>op[i].r;
        if(op[i].c==1) f[op[i].l]++,f[op[i].r+1]--;
        else g[op[i].l]++,g[op[i].r+1]--;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]+=f[i-1],g[i]+=g[i-1];
        if(f[i]&&g[i]) ans[i]=k+1;
        else if(f[i]) ans[i]=k;
        else mex[i]=true;
    }
    for(int l=1,r=1;l<=n&&r<=n;l=r)
    {
        while(r<=n&&mex[l]==mex[r]) ++r;
        if(mex[l])
        {
            for(int i=l,now=0;i<r;i++,now=(now+1)%k)
                ans[i]=now;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
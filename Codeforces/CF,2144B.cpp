#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int p[MAX];

void solve()
{
    cin>>n;

    int c0=0,pos;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        
        if(p[i]==0)
        {
            ++c0;
            pos=i;
        }
    }

    if(c0==1)
    {
        vector<bool>vis(n+1,false);
        for(int i=1;i<=n;i++)
            vis[p[i]]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                p[pos]=i;
                break;
            }
    }

    int st=1,ed=n;
    for(ed=n;ed>=1;--ed)
        if(p[ed]!=ed||p[ed]==0) break;
    for(st=1;st<=n;++st)
        if(p[st]!=st||p[st]==0) break;

    if(st<ed) cout<<ed-st+1<<endl;
    else cout<<0<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
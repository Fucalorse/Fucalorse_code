#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

int t,n,m,k;
int a[MAX],b[MAX];
vector<bool>vis;
char s[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        cin>>(s+1);
        unordered_map<int,vector<int>>f;
        vis.assign(n+5,false);
        sort(b+1,b+m+1);
        for(int i=1;i<=n;i++)
        {
            if(b[1]<a[i])
            {
                int now=a[i]-*(lower_bound(b+1,b+m+1,a[i])-1);
                f[-now].push_back(i);
            }
            if(a[i]<b[m])
            {
                int now=*(lower_bound(b+1,b+m+1,a[i]))-a[i];
                f[now].push_back(i);
            }
        }
        int now=0,ans=n;
        for(int i=1;i<=k;i++)
        {
            if(s[i]=='L') now--;
            else now++;
            for(auto &pos:f[now])
                if(!vis[pos])
                {
                    vis[pos]=true;
                    ans--;
                }
            f[now].clear();
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
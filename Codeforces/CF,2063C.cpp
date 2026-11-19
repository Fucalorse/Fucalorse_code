#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int f[MAX];
vector<int>deg,p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

void dfs(int ch,int fa)
{
    f[ch]=fa;
    for(auto &to:p[ch])
    {
        if(to==fa) continue;
        dfs(to,ch);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        clear();
        deg.assign(n+5,0);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            deg[u]++,deg[v]++;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        int max1=0,max2=0,p1=1,p2=1;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]>max1)
            {
                max2=max1,p2=p1;
                max1=deg[i],p1=i;
            }
            else if(deg[i]>max2) max2=deg[i],p2=i;
        }
        dfs(1,0);
        int ans=deg[p1]+deg[p2];
        // cout<<p1<<' '<<p2<<endl;
        // cout<<f[p1]<<' '<<f[p2]<<endl;
        if(f[p1]==p2||f[p2]==p1) ans-=2;
        else ans-=1;
        for(int i=1;i<=n;i++)
        {
            if(i==p1||i==p2) continue;
            int num1=deg[p1]+deg[i],num2=deg[p2]+deg[i];
            if(f[i]==p1||f[p1]==i) num1-=2;
            else num1-=1;
            if(f[i]==p2||f[p2]==i) num2-=2;
            else num2-=1;
            ans=max(ans,max(num1,num2));
        }
        cout<<ans<<endl;
    }
    return 0;
}
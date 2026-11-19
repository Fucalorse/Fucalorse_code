#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct point
{
    LL x,y;
}st[MAX],ed[MAX];

int n,pos;

void solve()
{
    cin>>n>>pos;
    for(int i=1;i<=n;i++)
        cin>>st[i].x>>st[i].y>>ed[i].x>>ed[i].y;
    
    LL dx=-2*st[pos].x,dy=-2*st[pos].y,sumx=0,sumy=0;
    for(int i=1;i<=n;i++)
    {
        dx+=st[i].x,dy+=st[i].y;
        sumx+=ed[i].x,sumy+=ed[i].y;
    }

    for(int i=1;i<=n;i++)
    {
        LL nowx=sumx-2*ed[i].x,nowy=sumy-2*ed[i].y;
        if(nowx==dx&&nowy==dy)
        {
            cout<<i<<endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=14;

int t,n;
int a[MAX],d[MAX],ans[MAX],pos[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans[i]=0;
    }
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int now=n;now>=1;--now)
    {
        int pos=-1;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]) continue;
            if(!d[i])
            {
                pos=i;
                break;
            }
        }
        if(pos==-1)
        {
            cout<<-1<<endl;
            return;
        }
        for(int i=1;i<pos;i++)
        {
            if(ans[i]) continue;
            if(a[pos]>a[i]) --d[i];
        }
        ans[pos]=now;
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
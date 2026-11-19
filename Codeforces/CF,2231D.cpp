#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;
const LL inf=1e15;

int t,n;
bool vis[MAX];
LL a[MAX],c[MAX],b[MAX];
string s;

void clear()
{
    c[0]=-inf;
    b[0]=a[0]=0;
    vis[0]=true;
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        b[i]=-inf;
    }
}

void solve()
{
    cin>>n>>s;s=' '+s;
    clear();

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];

    for(int i=1;i<=n;i++)
    {
        if(c[i]==c[i-1]) continue;
        if(c[i-1]>c[i])
        {
            cout<<"NO"<<endl;
            return;
        }
        b[i]=c[i],vis[i]=true;
        for(int j=i;j>=1;j--)
        {
            if(s[j]=='1')
            {
                if(vis[j-1])
                {
                    if(b[j-1]+a[j]!=b[j])
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                    break;
                }
                b[j-1]=b[j]-a[j];
                vis[j-1]=true;
            }
            else break;
        }
    }

    // for(int i=1;i<=n;i++)
    //     cout<<vis[i]<<' ';
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1'&&!vis[i]) b[i]=b[i-1]+a[i],vis[i]=true;
        if(!vis[i]) b[i]=-inf;
        a[i]=b[i]-b[i-1];
        // cout<<max(c[i-1],b[i])<<endl;
        if(max(c[i-1],b[i])!=c[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<b[i]<<' ';
    // cout<<endl;

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
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
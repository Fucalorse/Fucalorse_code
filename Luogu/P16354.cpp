#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int t,n;
int f[MAX],g[MAX],ans[MAX];
char a[MAX],b[MAX],c[MAX];

void solve()
{
    cin>>n>>(a+1)>>(b+1)>>(c+1);
    if(c[1]=='1'||c[n]=='1')
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        if(c[i]=='1'&&(c[i]==a[i]||c[i]==b[i]))
        {
            cout<<-1<<endl;
            return;
        }
    for(int i=1,cnt=0;i<=n;i++)
    {
        if(a[i]=='1'&&b[i]=='1') ++cnt;
        if(cnt>=2)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+(a[i]=='1');
        g[i]=g[i-1]+(b[i]=='1');
    }
    for(int i=1;i<=n;i++)
        if(b[i]=='1'&&f[n]-f[i]>0)
        {
            cout<<-1<<endl;
            return;
        }
    int pos=n+1,qwq=0;
    for(int i=n;i>=1;i--)
        if(b[i]=='1') pos=i;
    for(int i=1;i<pos;i++)
    {
        if(c[i+1]=='1')
        {
            for(int j=i+1;j<pos;j++)
            {
                if(c[j]=='0') break;
                ans[j]=++qwq;
            }
            ans[i]=++qwq;
            i=qwq;
        }
        else ans[i]=++qwq;
    }
    for(int i=pos+1;i<=n;i++)
        if(b[i]=='0') ans[i]=++qwq;
    for(int i=n;i>=pos;i--)
        if(b[i]=='1') ans[i]=++qwq;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ',ans[i]=0;
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
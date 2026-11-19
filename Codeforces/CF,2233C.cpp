#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,inf=2e9;

int T,n,k;
int pre[MAX],suf[MAX],ans[MAX];
string s;

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    pre[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+(s[i]=='(');
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+(s[i]==')');
    
    int pos=0,minn=inf;
    for(int i=0;i<=n;i++)
    {
        int now=pre[i]+suf[i+1];

        if(now<minn)
        {
            minn=now;
            pos=i;
        }
    }

    int cnt=0;

    for(int i=1;i<=pos;i++)
    {
        if(s[i]=='('&&cnt<k)
        {
            ans[i]=1;
            ++cnt;
        }
        else ans[i]=0;
    }

    for(int i=pos+1;i<=n;i++)
    {
        if(s[i]==')'&&cnt<k)
        {
            ans[i]=1;
            ++cnt;
        }
        else ans[i]=0;
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i];
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
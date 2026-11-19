#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+10,LEN=9999;

int t,n;
int a[MAX];
bool vis[LEN];
string s[MAX],op[MAX];

int cal(int n)
{
    if(!n) return 3;
    int cnt=0;
    while(n)
    {
        ++cnt;
        n/=10;
    }
    return 4-cnt;
}

void create()
{
    for(int i=0;i<=LEN;i++)
    {
        op[i]=to_string(i);
        op[i]=string(cal(i),'0')+op[i];
    }
}

int match(const string &now,const string &s)
{
    // cout<<now<<' '<<s<<endl;
    int ans=0;
    for(int i=0;i<4;i++)
        if(now[i]==s[i]) ans++;
    return ans;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i]>>a[i];
    for(int i=1;i<=n;i++)
        if(a[i]==4)
        {
            cout<<s[i]<<endl;
            return;
        }
    for(int i=0;i<=LEN;i++)
    {
        bool f=true;
        for(int j=1;j<=n;j++)
            if(match(op[i],s[j])!=a[j])
            {
                f=false;
                break;
            }
        if(f)
        {
            cout<<op[i]<<endl;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--) solve();
    return 0;
}
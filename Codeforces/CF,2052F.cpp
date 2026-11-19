#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
bool f[3][MAX];
string s[3];

void solve()
{
    cin>>n>>s[1]>>s[2];
    s[1]=' '+s[1],s[2]=' '+s[2];
    s[1]=s[1]+'#',s[2]=s[2]+'#';
    
    for(int i=1;i<=n;i++)
    {
        f[1][i]=s[1][i]=='#';
        f[2][i]=s[2][i]=='#';
    }

    f[1][0]=f[2][0]=true;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(f[1][i]&&f[2][i]) continue;

        if(f[1][i])
        {
            if(s[2][i]=='.'&&s[2][i+1]=='.') f[2][i]=f[2][i+1]=true;
            else
            {
                cout<<"None"<<endl;
                return;
            }
        }
        else if(f[2][i])
        {
            if(s[1][i]=='.'&&s[1][i+1]=='.') f[1][i]=f[1][i+1]=true;
            else
            {
                cout<<"None"<<endl;
                return;
            }
        }
        else
        {
            if(s[1][i-1]=='.'&&s[2][i-1]=='.') flag=true;
            f[1][i]=f[2][i]=true;
        }
    }

    if(flag) cout<<"Multiple"<<endl;
    else cout<<"Unique"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t;
char s[MAX];

void solve()
{
    cin>>(s+1);
    int len=strlen(s+1);
    map<int,int>f;
    bool a=false,b=false;
    for(int l=1,r=1;l<=len&&r<=len;l=r)
    {
        while(r<=len&&s[l]==s[r]) r++;
        if(r-l>=2)
        {
            if(r-l>=4)
            {
                cout<<"NO"<<endl;
                return;
            }
            ++f[r-l];
            if(r-l==2)
            {
                if(s[l]=='a') a=true;
                else b=true;
            }
        }
    }
    if(a&&b)
    {
        if(f[2]==2&&f.count(3)==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else if(f.count(3))
    {
        if(f[2]+f[3]>=2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    else
    {
        if(f[2]<=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

const int MAX=2e5+90;

int t,n;
LL a[MAX],s;

void peach()
{
    cin>>n>>s;
    bool f=true,g=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=0&&a[i]!=s) f=false;
        if(a[i]==s) g=true;
    }
    if(f&&g) cout<<"YES\n";
    else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) peach();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int t,n,x,y;

void solve()
{
    cin>>n>>x>>y;
    if(x==y)
    {
        if(n==1||x==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(x==0||y==0)
    {
        if(n>=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else
    {
        if((x>0&&y>0)||(x<0&&y<0))
        {
            int a=abs(x),b=abs(y);
            int cnt=max(a,b)/min(a,b);
            if(cnt>=n&&n>=2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            if(n>=2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
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
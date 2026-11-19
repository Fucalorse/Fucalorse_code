#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n,x,s;
string t;

void solve()
{
    cin>>n>>x>>s>>t;t=' '+t+' ';

    vector<int>id;
    id.push_back(0);
    for(int i=1;i<=n;i++)
        if(t[i]=='A') id.push_back(i);
    
    auto cal=[&](const int &mid)
    {
        if(mid>=(int)id.size()) return -1;
        string now=t;
        for(int i=0;i<=id[mid];i++)
            if(now[i]=='A') now[i]='I';

        int ans=0,a=0,b=0;
        for(int i=1;i<=n;i++)
        {
            if(now[i]=='I'&&a<x)
            {
                ++ans;
                ++a;
                b+=s-1;
            }
            else if((now[i]=='E'||now[i]=='A')&&b)
            {
                --b;
                ++ans;
            }
        }
        return ans;
    };

    int l=0,r=id.size()-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(cal(mid)<cal(mid+1)) l=mid+1;
        else r=mid-1;
    }

    cout<<cal(l)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
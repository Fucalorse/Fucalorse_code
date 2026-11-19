#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int T,a,b,x;

vector<int> split(int num)
{
    vector<int>ans;

    while(num)
    {
        ans.push_back(num);
        num/=x;
    }

    ans.push_back(0);

    return ans;
}

void solve()
{
    cin>>a>>b>>x;

    int ans=inf;
    vector<int>f=split(a),g=split(b);
    
    for(size_t i=0;i<f.size();i++)
        for(size_t j=0;j<g.size();j++)
        {
            int now=i+j+abs(f[i]-g[j]);
            ans=min(ans,now);
        }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    
    cin>>T;
    while(T--) solve();

    return 0;
}
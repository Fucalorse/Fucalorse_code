#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=2e5+90;

int t,n;
vector<int>a,op;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        a.assign(n+5,0),op.clear();
        for(int i=1;i<=n;i++)
            cin>>a[i];
        op.push_back(0);
        for(int i=1;i<=n;i++)
            if(a[i]!=a[i-1]) op.push_back(a[i]);
        op.push_back(0);
        int ans=0;
        for(size_t i=1;i<op.size();i++)
            if(op[i]>op[i-1]&&op[i]>op[i+1]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
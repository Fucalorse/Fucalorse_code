#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int t,n;
int ans[MAX];

void solve()
{
    cin>>n;
    vector<vector<int>>op(4);
    for(int i=1;i<=n;i++)
    {
        if(i%2==0) op[2].push_back(i);
        else if(i%3==0) op[3].push_back(i);
        else op[1].push_back(i);
    }

    auto get=[&]()
    {
        if(op[1].size())
        {
            int now=op[1].back();
            op[1].pop_back();
            return now;
        }
        else if(op[3].size())
        {
            int now=op[3].back();
            op[3].pop_back();
            return now;
        }
        else return inf;
    };

    while(op[2].size()>=2)
    {
        int a,b,c;
        a=get();
        b=op[2].back();op[2].pop_back();
        c=op[2].back();op[2].pop_back();
        cout<<a<<' '<<b<<' '<<c<<' ';
    }
    if(op[2].size()) op[3].push_back(op[2].front());

    while(op[3].size()>=2)
    {
        int a,b,c;
        a=get();
        b=op[3].back();op[3].pop_back();
        c=op[3].back();op[3].pop_back();
        cout<<a<<' '<<b<<' '<<c<<' ';  
    }

    int now=get();
    while(now!=inf)
    {
        cout<<now<<' ';
        now=get();
    }
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
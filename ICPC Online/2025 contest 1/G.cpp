#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    vector<int>op(n+1,0);
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
        if(b[i]-a[i]==1) op[a[i]]=b[i];
    }

    for(int i=1;i<n;i++)
        if(!op[i])
        {
            cout<<"No"<<endl;
            return;
        }

    cout<<"Yes"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}
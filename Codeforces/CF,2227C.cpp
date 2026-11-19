#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int a[MAX];
vector<int>p[10];

void clear()
{
    for(int i=1;i<=6;i++)
        p[i].clear();
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%6==0) p[6].push_back(a[i]);
        else if(a[i]%2==0) p[2].push_back(a[i]);
        else if(a[i]%3==0) p[3].push_back(a[i]);
        else p[1].push_back(a[i]);
    }

    for(auto &i:p[2])
        cout<<i<<' ';
    for(auto &i:p[1])
        cout<<i<<' ';
    for(auto &i:p[3])
        cout<<i<<' ';
    for(auto &i:p[6])
        cout<<i<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
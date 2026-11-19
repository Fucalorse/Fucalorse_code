#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int a[MAX];

void peach()
{
    cin>>n;
    unordered_map<int,int>f;
    vector<int>op(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=0;i<=n;i++)
    {
        op[f[i]]++;
        op[n-i+1]--;
        if(!f[i]) break;
    }
    for(int i=0,cnt=0;i<=n;i++)
    {
        cnt+=op[i];
        cout<<cnt<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) peach();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090,LEN=1e7,MOD=998244353,INF=2e9;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    if(k==n||k<n/2)
    {
        cout<<-1<<endl;
        return;
    }

    string s="";
    if(k&1)
    {
        for(int i=1;i<=k/2;i++)
        {
            s.push_back('(');
            s.push_back(')');
        }
        s.push_back('(');

        int rest=n-k;
        string pre=string(rest>>1,'('),suf=string((rest+1)>>1,')');
        s=pre+s;s=s+suf;
    }
    else
    {
        int dx=k-n/2,rest=n-dx*2;
        string base="()";

        for(int i=1;i<=dx/2;i++)
            s+=base;

        for(int i=1;i<=rest/2;i++)
            s+='(';
        for(int i=1;i<=rest/2;i++)
            s+=')';

        for(int i=1;i<=(dx+1)/2;i++)
            s+=base;
    }
    
    cout<<s<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
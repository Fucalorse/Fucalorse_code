#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    int c1=0,c2=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        if(a[i]==0) ++cnt;
        else if(a[i]==1) ++c1;
        else ++c2;
    }

    if(c1<c2) swap(c1,c2);
    cout<<cnt+c2+(c1-c2)/3<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
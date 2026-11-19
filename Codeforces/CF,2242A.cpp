#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int T,k;
int c[MAX];

void solve()
{
    cin>>k;

    int c3=0,c2=0;
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];

        if(c[i]>=3) c3++;
        if(c[i]>=2) c2++;
    }

    if(c3>=1||c2>=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
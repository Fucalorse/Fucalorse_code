#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    set<int>odd,even;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1) odd.insert(a[i]);
        else even.insert(a[i]);
    }

    int posl=1,posr=n%2==1?1:0;
    for(int num=1;num<=n;num++)
    {
        auto it_odd=odd.find(num);
        auto it_even=even.find(num);

        if(it_odd!=odd.end())
        {
            if(posl&1) posl^=1;
            else if(posr&1) posr^=1;
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }

        if(it_even!=even.end())
        {
            if(posl%2==0) posl^=1;
            else if(posr%2==0) posr^=1;
            else
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
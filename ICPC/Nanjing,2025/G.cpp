#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int n,q;
LL v[MAX],l[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>l[i];

    sort(v+1,v+n+1,greater<LL>());
    sort(l+1,l+n+1);

    vector<LL>pre_v(n+3,0),pre_l(n+3,0);
    for(int i=1;i<=n;i++)
    {
        pre_v[i]=pre_v[i-1]+v[i];
        pre_l[i]=pre_l[i-1]+l[i];
    }

    cin>>q;
    while(q--)
    {
        LL t;
        cin>>t;

        int L=1,R=n;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            LL now=v[mid]-l[mid]*t;
            if(now>=0) L=mid+1;
            else R=mid-1;
        }

        if(R<1)
        {
            cout<<0<<' ';
            continue;
        }

        LL ans=pre_v[R]-pre_l[R]*t;
        cout<<ans<<' ';
    }

    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ G2.cpp -O2 -o out.exe && .\out.exe < in.txt
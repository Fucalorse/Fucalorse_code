#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

ostream& operator<<(ostream& out,i128 x)
{
    if(!x)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

int n;
LL k;
LL a[MAX];

void solve()
{
    cin>>n>>k;

    vector<i128>pre(n+3,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i]-k*i;
    }

    for(int i=1;i<=n;i++)
    {
        if(i==1||i==n)
        {
            cout<<0<<' ';
            continue;
        }

        int l=i+1,r=n;
        LL base=a[i-1]-k*i;

        while(l<=r)
        {
            int mid=(l+r)>>1;
            LL now=a[mid]-mid*k-base;
            if(now<=0) r=mid-1;
            else l=mid+1;
        }

        i128 now=0;
        if(r>=i) now+=pre[r]-pre[i]+(i128)(r-i)*(k*i-a[i-1]);
        cout<<now<<' ';
    }
    cout<<endl;
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
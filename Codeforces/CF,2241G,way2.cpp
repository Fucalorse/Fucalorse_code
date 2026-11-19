#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

istream& operator>>(istream &in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f<0) x=-x;

    return in;
}

ostream& operator<<(ostream &out,i128 x)
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
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    i128 ans=0;
    vector<int>st;

    auto add=[&](int i,int pos)
    {
        LL r=a[pos]%a[i];
        LL now=min(a[i]-r,r);
        ans+=now*(n-pos+1);
    };

    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[i]%a[st.back()]!=0)
        {
            add(st.back(),i);
            st.pop_back();
        }
        st.push_back(i);
    }

    cout<<ans<<endl;
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
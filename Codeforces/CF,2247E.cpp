#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
LL k;

void solve()
{
    cin>>n>>k;

    LL l=2*(n-1),r=1LL*n*n/2;
    if(k<l||k>r||k&1)
    {
        cout<<-1<<endl;
        return;
    }

    if(n==2)
    {
        cout<<1<<' '<<2<<endl;
        return;
    }

    vector<int>ans(n+1,0);
    set<int>st;
    k=(k-l)>>1;
    int tot=n-1,num=2;
    ans[n]=n;

    for(int i=1;i<n;i++)
        st.insert(i);

    for(LL d=n-3;d>0;d-=2)
    {
        if(k<d) break;

        ans[tot--]=num;
        st.erase(num);

        num+=2,k-=d;
    }

    for(auto it=st.rbegin();it!=st.rend();++it)
        ans[tot--]=*it;
    
    if(k)
    {
        int pos;
        for(int i=1;i<=n;i++)
            if(ans[i]%2==0)
            {
                pos=i;
                break;
            }

        while(k)
        {
            swap(ans[pos],ans[pos+1]);
            ++pos;
            --k;
        }
    }

    for(int i=1;i<n;i++)
        cout<<ans[i]<<' '<<ans[i+1]<<endl;
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
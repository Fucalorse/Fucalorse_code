#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    a[0]=n;
    bool non_increasing=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1]) non_increasing=false;
    }
    
    if(!non_increasing)
    {
        cout<<"NO"<<endl;
        return;
    }

    set<int>st;
    for(int i=0;i<=n;i++)
        st.insert(i);

    for(int i=1;i<=n;i++)
        st.erase(a[i]);

    int big=0,gap=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i-1])
        {
            b[i]=n+1;
            gap++;
            big+=a[i-1]-a[i]-1;
        }
        else
        {
            auto it=st.lower_bound(a[i]);
            if(it==st.begin())
            {
                cout<<"NO"<<endl;
                return;
            }

            --it;
            b[i]=*it;
            st.erase(it);
        }

        int small=i-gap-big,c=a[i]+i-n;
        if(small!=c)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
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
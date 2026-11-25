#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int p[MAX],L[MAX],R[MAX];

void cal_L()
{
    vector<int>st;
    for(int i=n;i>=1;i--)
    {
        while(st.size()&&p[i]<p[st.back()])
        {
            L[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(st.size())
    {
        L[st.back()]=0;
        st.pop_back();
    }
}

void cal_R()
{
    vector<int>st;
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&p[i]<p[st.back()])
        {
            R[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(st.size())
    {
        R[st.back()]=n+1;
        st.pop_back();
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>p[i];

    cal_L(),cal_R();

    LL ans=1LL*(n+1)*n/2;
    for(int i=1;i<=n;i++)
    {
        int lenL=i-L[i]-1,lenR=R[i]-i-1;
        if(lenL==0||lenR==0) continue;

        LL now=1LL*(lenL+1)*(lenR+1);
        ans-=now-2;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    vector<int>st,rest;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1') st.push_back(i);
        else if(s[i]=='2')
        {
            if(st.size())
            {
                st.pop_back();
                rest.push_back(i);
            }
        }
    }

    while(st.size())
    {
        rest.push_back(st.back());
        st.pop_back();
    }

    sort(rest.begin(),rest.end());
    cout<<rest.size()<<endl;
    for(auto &cur:rest)
        cout<<cur<<' ';
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
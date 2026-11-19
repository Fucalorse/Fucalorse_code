#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    char opt;
    int x;
}op[MAX];

int n;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].opt>>op[i].x;
    
    vector<int>nxt(n+1,INF);
    map<int,int>f;

    for(int i=n;i>=1;i--)
    {
        auto [opt,x]=op[i];
        if(f.count(x)) nxt[i]=f[x];
        f[x]=i;
    }

    string ans="";
    vector<int>st;
    map<int,bool>del;

    for(int i=1;i<=n;i++)
    {
        while(st.size()&&del[st.back()])
        {
            del[st.back()]=false;
            st.pop_back();
            ans.push_back('-');
        }

        const auto [opt_cur,x]=op[i];
        if(nxt[i]!=INF)
        {
            const auto [opt_nxt,xxxx]=op[nxt[i]];
            if((opt_cur=='+'||opt_cur=='T')&&(opt_nxt=='+'||opt_nxt=='F')) del[x]=true;
        }
        else del[x]=true;

        if(opt_cur=='+')
        {
            st.push_back(x);
            ans.push_back('+');
        }
        else ans.push_back('?');
    }

    while(st.size())
    {
        ans.push_back('-');
        st.pop_back();
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
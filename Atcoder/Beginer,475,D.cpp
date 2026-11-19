#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e7+10,LEN=1e7,G=3,MOD=998244353,INF=2e9;

int minp[MAX];
vector<int>op;
vector<vector<int>>num(9);

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    auto get_len=[&](int x)
    {
        if(!x) return 1;

        int ans=0;
        while(x)
        {
            ++ans;
            x/=10;
        }

        return ans;
    };

    for(auto &cur:op)
        num[get_len(cur)].push_back(cur);
}

string s;

void solve()
{
    cin>>s;

    auto check=[&](int x)
    {
        string t;
        while(x)
        {
            t.push_back(x%10+'0');
            x/=10;
        }
        reverse(t.begin(),t.end());

        for(size_t i=0;i<s.size();i++)
            for(size_t j=i+1;j<s.size();j++)
            {
                if(s[i]==s[j]&&t[i]!=t[j]) return false;
                if(s[i]!=s[j]&&t[i]==t[j]) return false;
            }

        return true;
    };

    for(auto &cur:num[s.size()])
        if(check(cur))
        {
            cout<<cur<<endl;
            return;
        }

    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
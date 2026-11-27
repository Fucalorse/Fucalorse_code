#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

string s;

void solve()
{
    cin>>s;
    int n=(int)s.size();
    s=s+s,s=' '+s;

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }

    auto get_min_dic=[&](const string &s)->string
    {
        int len=(int)s.size();
        string t=s+s;
        int i=0,j=1,k=0;
        while(i<len&&j<len&&k<len)
        {
            if(t[i+k]==t[j+k])
            {
                ++k;
                continue;
            }

            if(t[i+k]>t[j+k]) i+=k+1;
            else j+=k+1;

            if(i==j) ++j;
            k=0;
        }
        return t.substr(min(i,j),len);
    };

    vector<string>ans;
    for(int i=1;i<=n;i++)
    {
        string cur=s.substr(i,n-1);
        ans.push_back(get_min_dic(cur));
    }

    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    cout<<(int)ans.size()<<endl;
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
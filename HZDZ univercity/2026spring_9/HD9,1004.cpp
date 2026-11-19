#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90;
const string now="execute";

int t;
int op[MAX];
string s;

void create()
{
    for(size_t i=1,j=0;i<now.size();i++)
    {
        while(j&&now[i]!=now[j]) j=op[j];
        if(now[i]==now[j]) j++;
        op[i+1]=j;
    }
}

vector<int> find()
{
    vector<int>ans;
    for(size_t i=0,j=0;i<s.size();i++)
    {
        while(j&&s[i]!=now[j]) j=op[j];
        if(s[i]==now[j]) j++;
        if(j==now.size()) ans.push_back(i-6);
    }
    return ans;
}

void solve()
{
    cin>>s;
    vector<int>rest=find();
    // for(auto &i:rest)
    //     cout<<i<<' ';
    // cout<<endl;
    for(size_t l=0,r=0;l<rest.size();l=r)
    {
        r=l+1;
        while(r<rest.size()&&rest[r]-rest[r-1]==6) r++;
        // cout<<l<<' '<<r<<endl;
        if((r-l)&1)
        {
            s[rest[l]]='1';
            for(int i=l+2;i<(int)r;i+=2)
                s[rest[i]]='1';
        }
        else
        {
            for(int i=l+1;i<(int)r;i+=2)
                s[rest[i]]='1';
        }
    }
    cout<<s<<endl;  
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--) solve();
    return 0;
}
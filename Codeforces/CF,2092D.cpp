#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define peach 182497
const int MAX=150;

int T,n;
string s;

void solve()
{
    cin>>n>>s;

    int a=0,b=0,c=0;
    auto cal=[&]()
    {
        a=b=c=0;
        for(size_t i=0;i<s.size();i++)
        {
            if(s[i]=='L') ++a;
            else if(s[i]=='I') ++b;
            else ++c;            
        }
    };

    cal();
    if(a==n||b==n||c==n)
    {
        cout<<-1<<endl;
        return;
    }
    
    vector<int>ans;
    auto update=[&](char c)
    {
        string now="";
        size_t pos;
        for(size_t i=0;i<s.size();i++)
        {
            if((i+1)<s.size()&&s[i]!=s[i+1])
            {
                pos=i;
                if(c!=s[i]&&c!=s[i+1]) break;
            }
        }
        for(size_t i=0;i<s.size();i++)
        {
            now+=s[i];
            if(i==pos)
            {
                if(c==s[i]||c==s[i+1])
                {
                    char other;
                    if('L'!=s[i]&&'L'!=s[i+1]) other='L';
                    else if('I'!=s[i]&&'I'!=s[i+1]) other='I';
                    else other='T';

                    now+=s[i+1];
                    now+=s[i];
                    now+=other;
                    now+=s[i];

                    ans.push_back(i);
                    ans.push_back(i);
                    ans.push_back(i+2);
                    ans.push_back(i+1);
                }
                else
                {
                    now+=c;
                    ans.push_back(i);
                }
            }
        }
        s=now;
    };

    while(peach)
    {
        if(a==b&&b==c) break;
        int minn=min({a,b,c});
        if(minn==a) update('L');
        else if(minn==b) update('I');
        else update('T');
        cal();
    }

    cout<<ans.size()<<endl;
    for(auto &i:ans)
        cout<<i+1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}
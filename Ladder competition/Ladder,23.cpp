#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1090;
const string ans="GPLT";

string s;
map<char,int>f;

int main()
{
    cin>>s;
    for(auto c:s)
    {
        if(islower(c)) c-=32;
        if(ans.find(c)!=string::npos) f[c]++;
    }
    for(int i=0;;i=(i+1)&3)
    {
        if(f.count(ans[i])&&f[ans[i]])
        {
            cout<<ans[i];
            if(--f[ans[i]]==0) f.erase(ans[i]);
        }
        if(f.empty()) break;
    }
    return 0;
}
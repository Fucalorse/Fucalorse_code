#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

unordered_map<char,string>f;
string s;

void create()
{
    f['-']="fu";
    f['0']="ling";
    f['1']="yi";
    f['2']="er";
    f['3']="san";
    f['4']="si";
    f['5']="wu";
    f['6']="liu";
    f['7']="qi";
    f['8']="ba";
    f['9']="jiu";
}

int main()
{
    create();
    cin>>s;
    for(size_t i=0;i<s.size();++i)
    {
        if(i) cout<<' ';
        cout<<f[s[i]];
    }
    return 0;
}
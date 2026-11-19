#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100;

int main()
{
    string s;
    LL x=0,y=0;
    cin>>s;
    for(auto &i:s)
        x=x*2+i-'0';
    cin>>s;
    for(auto &i:s)
        y=y*2+i-'0';
    if(!x&&y) cout<<-1<<endl;
    else cout<<llabs(x-y)<<endl;
    return 0;
}
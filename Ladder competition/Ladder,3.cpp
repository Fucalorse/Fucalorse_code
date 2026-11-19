#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=15;

string s;
int f[MAX];

int main()
{
    cin>>s;
    for(auto &i:s)
        f[i-'0']++;
    for(int i=0;i<=9;i++)
    {
        if(!f[i]) continue;
        cout<<i<<':'<<f[i]<<endl;
    }
    return 0;
}
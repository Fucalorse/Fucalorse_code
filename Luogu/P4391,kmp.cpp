#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int>op;

int main()
{
    cin>>n>>s;
    op.resize(n+1,0);
    for(size_t i=1,j=0;i<s.size();i++)
    {
        while(j&&s[i]!=s[j]) j=op[j];
        if(s[i]==s[j]) j++;
        op[i+1]=j;
    }
    cout<<n-op[n]<<'\n';
    return 0;
}
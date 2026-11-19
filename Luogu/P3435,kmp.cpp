#include <bits/stdc++.h>
using namespace std;

#define LL long long

int n;
string s;
vector<int>op;

int main()
{
    cin>>n>>s;
    op.resize(n+1,0);
    LL total=0;
    for(size_t i=1,j=0;i<s.size();i++)
    {
        while(j&&s[i]!=s[j]) j=op[j];
        if(s[i]==s[j]) j++;
        int x=i+1;
        op[x]=j;
        while(op[op[x]]) op[x]=op[op[x]];
        if(op[x]) total+=x-op[x];
    }
    cout<<total<<'\n';
    return 0;
}
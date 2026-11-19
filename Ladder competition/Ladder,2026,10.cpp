#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m,k;
map<string,char>op;

bool solve()
{
    cin>>k;
    bool f=true;
    for(int i=1;i<=k;i++)
    {
        string s;
        cin>>s;
        if(op.count(s)&&op[s]=='e') f=false;
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        char c;
        cin>>s>>c;
        op[s]=c;
    }
    cin>>m;
    vector<int>id;
    for(int i=1;i<=m;i++)
        if(solve()) id.push_back(i);
    if(id.empty())
    {
        cout<<"None"<<endl;
        return 0;
    }
    for(size_t i=0;i<id.size();i++)
    {
        if(i) cout<<' ';
        cout<<id[i];
    }
    cout<<endl;
    return 0;
}
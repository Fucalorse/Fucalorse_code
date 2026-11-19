#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=55;

int n,st,ed;
LL m;
LL num[MAX];
vector<LL>f,g;

void dfs(int pos,LL sum,vector<LL>&op)
{
    if(sum>m) return;
    op.push_back(sum);
    for(int i=pos;i<=ed;i++)
        dfs(i+1,sum+num[i],op);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    st=1,ed=n/2;
    dfs(st,0,f);
    st=n/2+1,ed=n;
    dfs(st,0,g);
    sort(f.begin(),f.end(),greater<LL>());
    sort(g.begin(),g.end());
    LL total=0;
    for(size_t i=0,j=0;i<f.size();i++)
    {
        while(j<g.size()&&f[i]+g[j]<=m) j++;
        total=total+j;
    }
    cout<<total<<'\n';
    return 0;
}
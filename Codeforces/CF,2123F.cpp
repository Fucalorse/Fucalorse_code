#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e5;

int t,n;
int ans[MAX],minp[MAX];
bool vis[MAX];
vector<int>p[MAX],op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if((LL)i*j>n) break;
            minp[i*j]=i;
            if(i%j==0) break;
        }
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        p[i].clear();
        vis[i]=false;
    }
}

void solve()
{
    cin>>n;clear();

    vector<int>num;
    num.push_back(1);
    for(auto &i:op)
    {
        if(i>n) break;
        else num.push_back(i);
    }
    for(int i=num.size()-1;i>=0;i--)
        for(int j=num[i];j<=n;j+=num[i])
            if(!vis[j])
            {
                vis[j]=true;
                p[num[i]].push_back(j);
            }
    for(int i=2;i<=n;i++)
    {
        if(p[i].empty()) continue;
        vector<int>&now=p[i];
        for(size_t j=1;j<now.size();j++)
            ans[now[j]]=now[j-1];
        ans[now[0]]=now.back();
    }
    for(auto &i:p[1])
        ans[i]=i;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    oula(LEN);
    cin>>t;
    while(t--) solve();
    return 0;
}
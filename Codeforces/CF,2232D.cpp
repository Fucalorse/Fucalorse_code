#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100;

struct qwq
{
    int id,from,to;
};

int T,n;
int a[MAX];

void dfs(int id,int from,int to,vector<qwq>& ans)
{
    if(!id) return;

    if(a[id]==0)
    {
        int mid=6-from-to;

        dfs(id-1,from,mid,ans);
        ans.push_back({id,from,to});
        dfs(id-1,mid,to,ans);
    }
    else
    {
        int mid=6-from-to;

        dfs(id-a[id]-1,from,mid,ans);
        ans.push_back({id,from,to});
        dfs(id-a[id]-1,mid,from,ans);
        dfs(id-1,from,to,ans);
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        if(a[i]>=i)
        {
            cout<<"NO"<<endl;
            return;
        }

    vector<qwq>ans;
    dfs(n,1,3,ans);

    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for(auto &[id,from,to]:ans)
        cout<<id<<' '<<from<<' '<<to<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
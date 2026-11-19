#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=1090;

struct qwq
{
    int row,col,val;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n,m,k;
int op[MAX][MAX];
bool f[MAX],g[MAX];
priority_queue<qwq>q;
vector<int>rest;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>op[i][j];
            // cout<<i<<' '<<j<<' '<<op[i][j]<<endl;
            q.push({i,j,op[i][j]});
        }
    int now=k;
    while(now)
    {
        auto [r,c,val]=q.top();q.pop();
        if(f[r]||g[c]) continue;
        f[r]=g[c]=true;
        // cout<<r<<' '<<c<<endl;
        now--;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]) continue;
        for(int j=1;j<=m;j++)
        {
            if(g[j]) continue;
            rest.push_back(op[i][j]);
        }
    }
    int cnt=0;
    for(auto &i:rest)
    {
        ++cnt;
        if(cnt==m-k) cout<<i<<endl,cnt=0;
        else cout<<i<<' ';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX=4090;

int n,m,k,v;
int f[MAX][MAX],op[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k>>v;
    for(int i=1;i<=k;i++)
    {
        int x,y,val;
        cin>>x>>y>>val;
        op[x][y]=val;
    }
    for(int i=1;i<=n;i++)
    {
        deque<int>q;
        int p=i-1,r;
        for(r=1;r<=v;r++)
        {
            while(q.size()&&f[p][r]>f[p][q.back()]) q.pop_back();
            q.push_back(r);
        }
        for(int j=1;j<=m;j++)
        {
            while(q.size()&&r<=m&&f[p][r]>f[p][q.back()]) q.pop_back();
            while(q.size()&&q.front()<j-v) q.pop_front();
            if(r<=m)
            {
                q.push_back(r);
                r++;
            }
            f[p+1][j]=f[p][q.front()]+op[i][j];
        }
    }
    int maxn=0;
    for(int i=1;i<=m;i++)
        maxn=max(maxn,f[n][i]);
    cout<<maxn<<'\n';
    return 0;
}
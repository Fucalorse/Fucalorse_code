#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

struct qwq
{
    int pos,val;
};

int n,m,p;
int f[MAX],g[MAX][MAX],c[MAX],op[MAX];
deque<qwq>q[MAX];

int get(const int &i,const int &j) { return ((j-i)%n+n)%n; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            g[i][j]+=g[i-1][j-1];
        }
    memset(f,-0x3f,sizeof f);
    f[0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        q[i].push_back({0,-c[i]});
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int id=get(i,j);
            while(q[id].size()&&q[id].front().pos<i-p) q[id].pop_front();
            if(!j) op[id]+=g[n][i];
            if(q[id].size()) f[i]=max(f[i],q[id].front().val+op[id]+g[j][i]);
        }
        for(int j=0;j<n;j++)
        {
            int id=get(i,j);
            int now=f[i]-g[j][i]-op[id]-c[j];
            while(q[id].size()&&q[id].back().val<=now) q[id].pop_back();
            q[id].push_back({i,now});
        }
    }
    cout<<f[m]<<'\n';
    return 0;
}
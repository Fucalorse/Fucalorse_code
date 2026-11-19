#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,LEN=2e5,MOD=1e9+7,INF=2e9;

int n,m;
LL a[MAX][MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];

    if(n==1||m==1)
    {
        set<LL>st;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                st.insert(a[i][j]);

        if((int)st.size()>1) cout<<-1<<endl;
        else cout<<0<<endl;

        return;
    }

    set<LL>st;
    for(int k=3;k<=n+m-1;k++)
    {
        LL sum=0,cnt=0;

        for(int x=1;x<=n;x++)
            {
                int y=k-x;
                if(y>=1&&y<=m) sum+=a[x][y],++cnt;
            }

        LL p=sum-a[1][1],q=cnt-1;
        if(p%q!=0)
        {
            cout<<-1<<endl;
            return;
        }

        st.insert(p/q);
    }

    if((int)st.size()>1||a[1][1]!=a[n][m])
    {
        cout<<-1<<endl;
        return;
    }

    LL tar=*st.begin();

    if(tar<a[1][1])
    {
        cout<<-1<<endl;
        return;
    }

    vector<vector<LL>>rest(n+1,vector<LL>(m+1,0));
    rest[1][1]=tar-a[1][1];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1) continue;

            LL cost=tar-a[i][j];
            if(rest[i-1][j]>cost)
            {
                cout<<-1<<endl;
                return;
            }

            cost-=rest[i-1][j],rest[i-1][j]=0;
            if(rest[i][j-1]<cost)
            {
                cout<<-1<<endl;
                return;
            }

            rest[i][j-1]-=cost,cost=0;
            rest[i][j]=tar-a[i][j];
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(i==n&&j==m) continue;

            if(rest[i][j]!=0)
            {
                cout<<-1<<endl;
                return;
            }
        }

    cout<<tar-a[1][1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
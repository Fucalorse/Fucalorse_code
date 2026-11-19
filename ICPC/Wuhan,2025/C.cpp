#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n,m;

void solve()
{
    cin>>n>>m;

    bool inverse=false;
    if(n%3==0)
    {
        if(m==3)
        {
            swap(n,m);
            inverse=true;
        }
        else inverse=false;
    }
    else
    {
        swap(n,m);
        inverse=true;
    }

    vector<vector<int>>ans(n+1,vector<int>(m+1,-1));
    if(m==1||m==2)
    {
        if(n>=9)
        {
            cout<<"No"<<endl;
            return;
        }

        int total=n*m;
        if(m==1)
        {
            int pos=0;
            for(int i=1;i<=total/3;i++)
                ans[++pos][1]=0;
            for(int i=1;i<=total/3;i++)
                ans[++pos][1]=1;
            for(int i=1;i<=total/3;i++)
                ans[++pos][1]=2;
        }
        else
        {
            for(int i=1;i<=total/3;i++)
                for(int j=1;j<=m;j++)
                {
                    if((i+j)&1) ans[i][j]=0;
                    else ans[i][j]=1;
                }

            for(int i=total/3+1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    ans[i][j]=2;
        }
    }
    else
    {
        const vector<vector<int>>a={{2,2,0,0,1,1},{1,0,2,1,0,2},{0,1,1,2,2,0}};
        const vector<vector<int>>b={{0,1,1,2},{1,0,0,2},{1,2,2,0},{2,1,1,0},{2,0,0,1},{0,2,2,1}};

        if(m==4)
        {
            for(int i=1,pos=0;i<=n;i++,pos=(pos+1)%6)
                for(int j=1;j<=m;j++)
                    ans[i][j]=b[pos][(j-1)%4];
        }
        else
        {
            for(int block=1;block<=n/3;block++)
            {
                int st=(block-1)*3+1,ed=block*3;
                for(int i=st,pos=0;i<=ed;i++,pos=(pos+1)%3)
                    for(int j=1;j<=m;j++)
                    {
                        if(block&1) ans[i][j]=a[pos][(j-1)%6];
                        else ans[i][j]=a[2-pos][(j-1)%6];
                    }
            }
        }
    }

    cout<<"Yes"<<endl;
    if(inverse)
    {
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<=n;i++)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cout<<ans[i][j];
            cout<<endl;
        }
    }
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
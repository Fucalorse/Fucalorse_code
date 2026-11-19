#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=350;

struct peach
{
    private:
        int op[MAX][MAX][110];
        int n,m;
        int query(int x,int y,int c)
        {
            int ans=0;
            for(int i=x;i;i-=i&-i)
                for(int j=y;j;j-=j&-j)
                    ans+=op[i][j][c];
            return ans;
        }
    public:
        void debut(int _n,int _m) { n=_n,m=_m; }
        void update(int x,int y,int c,int k)
        {
            for(int i=x;i<=n;i+=i&-i)
                for(int j=y;j<=m;j+=j&-j)
                    op[i][j][c]+=k;
        }
        int get(int x1,int x2,int y1,int y2,int c)
        {
            return query(x2,y2,c)-query(x2,y1-1,c)-query(x1-1,y2,c)+query(x1-1,y1-1,c);
        }
}fu;

int n,m,q;
int a[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    fu.debut(n,m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            fu.update(i,j,a[i][j],1);
        }
    cin>>q;
    while(q--)
    {
        int p;
        cin>>p;
        if(p==1)
        {
            int x,y,c;
            cin>>x>>y>>c;
            fu.update(x,y,a[x][y],-1);
            fu.update(x,y,c,1);
            a[x][y]=c;
        }
        else
        {
            int x1,x2,y1,y2,c;
            cin>>x1>>x2>>y1>>y2>>c;
            cout<<fu.get(x1,x2,y1,y2,c)<<endl;
        }
    }
    return 0;
}
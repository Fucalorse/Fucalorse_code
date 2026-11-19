#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090;

struct peach
{
    private:
        int n,m;
        LL a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],d[MAX][MAX];
        void add(int x,int y,LL k)
        {
            int p=x,q=y;
            for(int i=x;i<=n;i+=i&-i)
                for(int j=y;j<=m;j+=j&-j)
                {
                    a[i][j]+=k;
                    b[i][j]+=q*k;
                    c[i][j]+=p*k;
                    d[i][j]+=p*q*k;
                }
        }
        LL query(int x,int y)
        {
            int p=x+1,q=y+1;
            LL ans=0;
            for(int i=x;i;i-=i&-i)
                for(int j=y;j;j-=j&-j)
                    ans+=p*q*a[i][j]-p*b[i][j]-q*c[i][j]+d[i][j];
            return ans;
        }
    public:
        void debut(int _n,int _m) { n=_n,m=_m; }
        void update(int x1,int y1,int x2,int y2,LL k)
        {
            add(x1,y1,k),add(x1,y2+1,-k);
            add(x2+1,y1,-k),add(x2+1,y2+1,k);
        }
        LL get(int x1,int y1,int x2,int y2)
        {
            return query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1);
        }
}fu;

int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char c;
    cin>>c>>n>>m;
    fu.debut(n,m);
    while(cin>>c)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(c=='L')
        {
            LL k;
            cin>>k;
            fu.update(x1,y1,x2,y2,k);
        }
        else cout<<fu.get(x1,y1,x2,y2)<<endl;
    }
    return 0;
}
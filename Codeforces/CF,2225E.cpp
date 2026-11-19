#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

mt19937 rng(random_device{}());

struct point
{
    int x,y;
    bool operator<(const point &a)const
    {
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
    bool operator==(const point &a)const { return x==a.x&&y==a.y; }
}op[MAX];

int n,r;

bool in_circle(const point &cur,const point &circle)
{
    LL dx=abs(cur.x-circle.x),dy=abs(cur.y-circle.y);
    LL dist=dx*dx+dy*dy;
    return dist<=1LL*r*r;
}

void solve()
{
    cin>>n>>r;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    int h=ceil(sqrt(3)*r);
    uniform_int_distribution<int>dist_r(0,2*r-1),dist_h(0,2*h-1);
    while(1)
    {
        int dx=dist_r(rng),dy=dist_h(rng),cnt=0;
        vector<point>ans;
        for(int i=1;i<=n;i++)
        {
            int nx=op[i].x-dx,ny=op[i].y-dy;

            int row1=ny/h,row2;
            if(ny<0) row2=row1-1;
            else row2=row1+1;

            auto check=[&](int row)
            {
                point p1,p2;
                int col1,col2;
                if(abs(row)&1)
                {
                    col1=floor(1.00*(nx-r)/(2*r));
                    col2=col1+1;
                    p1={col1*2*r+r,row*h};
                    p2={col2*2*r+r,row*h};
                }
                else
                {
                    col1=floor(1.00*nx/(2*r));
                    col2=col1+1;
                    p1={col1*2*r,row*h};
                    p2={col2*2*r,row*h};
                }

                if(in_circle(point{nx,ny},p1))
                {
                    ans.push_back(p1);
                    return true;
                }
                if(in_circle(point{nx,ny},p2))
                {
                    ans.push_back(p2);
                    return true;
                }

                return false;
            };

            if(check(row1)||check(row2)) ++cnt;
        }

        if(100*cnt>=89*n)
        {
            sort(ans.begin(),ans.end());
            ans.erase(unique(ans.begin(),ans.end()),ans.end());

            cout<<ans.size()<<endl;
            for(auto &[x,y]:ans)
                cout<<x+dx<<' '<<y+dy<<endl;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
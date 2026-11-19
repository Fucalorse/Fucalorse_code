#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,inf=2e9;

struct point
{
    int x,y;
    bool operator<(const point &a)const { return x<a.x; }
}op[MAX];

int T,n;
int minn[MAX],maxn[MAX];

void clear()
{
    for(int i=1;i<=n+3;i++)
        minn[i]=inf,maxn[i]=-inf;
}

void solve()
{
    cin>>n;clear();

    vector<int>rest;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;
        rest.push_back(op[i].y);
    }

    sort(op+1,op+n+1);
    sort(rest.begin(),rest.end());
    rest.erase(unique(rest.begin(),rest.end()),rest.end());

    for(int i=n;i>=1;i--)
    {
        minn[i]=min(minn[i+1],op[i].y);
        maxn[i]=max(maxn[i+1],op[i].y);
    }

    LL ans=0;
    int lmin=inf,lmax=-inf;
    for(int l=1,r;l<=n;l=r)
    {
        r=l;
        while(r<=n&&op[l].x==op[r].x)
        {
            lmin=min(lmin,op[r].y);
            lmax=max(lmax,op[r].y);

            ++r;
        }

        int rmin=minn[r],rmax=maxn[r];
        int low=max(lmin,rmin),high=min(lmax,rmax)-1;

        if(low<=high)
        {
            int now=upper_bound(rest.begin(),rest.end(),high)-lower_bound(rest.begin(),rest.end(),low);
            ans+=now;
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
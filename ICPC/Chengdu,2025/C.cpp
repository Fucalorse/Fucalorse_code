#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=4e5+90;

struct ovo
{
    LL t;
    int tp,id;
}ans[MAX];

struct item
{
    LL t;
    int id;
    bool operator<(const item &a)const { return t<a.t; }
}a[MAX],b[MAX];

int T,n,m;
LL k;

bool dis(LL now,int col)
{
    int i,j,p,qwq=0;
    for(i=n,j=m,p=col;i>=1&&j>=1;)
    {
        if(p&1)
        {
            now-=k;
            if(now<b[j].t) return false;
            ans[++qwq]={now,p,b[j].id};
            j--;
        }
        else
        {
            now-=k;
            if(now<a[i].t) return false;
            ans[++qwq]={now,p,a[i].id};
            i--;
        }
        p^=1;
    }
    while(i)
    {
        now-=k;
        if(now<a[i].t) return false;
        ans[++qwq]={now,p,a[i].id};
        i--;
        now-=k;
    }
    while(j)
    {
        now-=k;
        if(now<b[j].t) return false;
        ans[++qwq]={now,p,b[j].id};
        j--;
        now-=k;
    }
    return now+k>=0LL;
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].t;
        a[i].id=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].t;
        b[i].id=i;
    }
    
    sort(a+1,a+n+1),sort(b+1,b+m+1);
    // for(int i=1;i<=n;i++)
    //     cout<<a[i].t<<' '<<a[i].id<<endl;
    // cout<<endl;
    // for(int i=1;i<=m;i++)
    //     cout<<b[i].t<<' '<<b[i].id<<endl;
    LL l=0,r=1e18;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(dis(mid,0)||dis(mid,1)) r=mid-1;
        else l=mid+1;
    }
    bool flag=dis(l,0);
    if(!flag) dis(l,1);

    cout<<l<<endl;
    for(int i=n+m;i>=1;i--)
        cout<<ans[i].t<<' '<<ans[i].tp<<' '<<ans[i].id<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}

// g++ C.cpp -O2 -o out.exe && out.exe < in.txt
#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e5+90;

struct qwq
{
    LL x,y;
    qwq operator+(const qwq &a)const { return {x+a.x,y+a.y}; }
}f[MAX],st,ed;

int n;
char s[MAX];

LL cal(const qwq &a,const qwq &b)
{
    return llabs(a.x-b.x)+llabs(a.y-b.y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>st.x>>st.y>>ed.x>>ed.y>>n>>(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='U') f[i]=f[i-1]+qwq{0,1};
        else if(s[i]=='R') f[i]=f[i-1]+qwq{1,0};
        else if(s[i]=='D') f[i]=f[i-1]+qwq{0,-1};
        else f[i]=f[i-1]+qwq{-1,0};
    }
    LL l=0,r=1e15,ans=-1;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL m=mid/n,rest=mid%n;
        qwq now={f[n].x*m,f[n].y*m};
        now=now+f[rest]+st;
        // cout<<mid<<' '<<now.x<<' '<<now.y<<' '<<cal(now,ed)<<endl;
        if(cal(now,ed)<=mid) r=mid-1,ans=mid;
        else l=mid+1;
        // cout<<mid<<endl;
    }
    cout<<ans<<'\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=1e14;

int t,n,k,x,qwq,len;
int ans[MAX],num[MAX],op[MAX],f[MAX];

bool dis(const int &mid)
{
    if(!mid) return x+1>=k;
    int cnt=0;
    if(op[1]>=mid) cnt+=op[1]-mid+1;
    if(op[qwq]>=mid) cnt+=op[qwq]-mid+1;
    for(int i=2;i<qwq;i++)
    {
        int l=mid,r=op[i]+1-mid;
        if(l<=r) cnt+=r-l+1;
        // if(cnt>=k) return true;
    }
    return cnt>=k;
}

void cal(const int &mid)
{
    if(!mid)
    {
        for(int i=0;i<=k-1;i++)
            ans[++len]=i;
        return;
    }
    if(op[1]>=mid)
    {
        for(int i=0;i<=num[1]-mid;i++)
        {
            ans[++len]=i;
            if(len==k) return;
        }
    }
    for(int i=2;i<qwq;i++)
    {
        int l=mid,r=op[i]+1-mid;
        if(l<=r)
        {
            for(int j=l;j<=r;j++)
            {
                ans[++len]=j+f[i];
                if(len==k) return;
            }
        }
    }
    if(op[qwq]>=mid)
    {
        for(int i=num[n]+mid;i<=x;i++)
        {
            ans[++len]=i;
            if(len==k) return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    num[0]=-1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>x;
        len=qwq=0;
        for(int i=1;i<=n;i++)
            cin>>num[i];
        sort(num+1,num+n+1);
        for(int i=1;i<=n;i++)
        {
            int now=num[i]-num[i-1]-1;
            if(now||i==1) op[++qwq]=now,f[qwq]=num[i-1];
        }
        op[++qwq]=x-num[n],f[qwq]=num[n];
        // for(int i=1;i<=qwq;i++)
        //     cout<<op[i]<<' ';
        // cout<<'\n';
        int l=0,r=x;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(dis(mid)) l=mid+1;
            else r=mid-1;
            // cout<<l<<' '<<r<<'\n';
        }
        cal(r);
        // cout<<r<<'\n';
        for(int i=1;i<=len;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;
const LL inf=1e13;

int t,n;
LL k;
LL a[MAX];
char s[MAX];

LL cal()
{
    LL maxn=-inf,sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=max(a[i],sum+a[i]);
        maxn=max(maxn,sum);
    }
    return maxn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>(s+1);
        LL maxn=-inf,sum=0;
        int pos=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(s[i]=='0') a[i]=-inf,pos=i;
        }
        for(int i=1;i<=n;i++)
        {
            sum=max(a[i],sum+a[i]);
            maxn=max(maxn,sum);
        }
        if((pos==-1&&maxn!=k)||(pos>0&&maxn>k))
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(pos!=-1)
        {
            LL l=-inf,r=inf;
            while(l<=r)
            {
                LL mid=(l+r)>>1;
                a[pos]=mid;
                if(cal()>=k) r=mid-1;
                else l=mid+1;
            }
            a[pos]=l;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    return 0;
}
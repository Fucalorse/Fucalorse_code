#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=5e5+90;

int t,n;
LL a[MAX],b[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<i) f=false;
        }
        if(!f)
        {
            cout<<-1<<'\n';
            continue;
        }
        b[n]=a[n];
        for(int i=n-1;i>=1;i--)
            b[i]=min(a[i],b[i+1]-1);
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i]>ans) ans=a[i];
            else ans+=a[i]-b[i]+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
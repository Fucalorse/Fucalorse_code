#include <bits/stdc++.h>
using namespace std;

const int MAX=3090;

int t,n,k;
int op[MAX];

bool dis(const int &mid)
{
    int total=0,cnt=0;
    for(int i=1;i<=n;i++,cnt++)
    {
        if(total+op[i]>mid)
        {
            if(total<mid) total=mid,++cnt;
            break;
        }
        else total+=op[i];
    }
    if(cnt+(total-cnt)/k>=n) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int l=0,r=0;
        for(int i=1;i<=n;i++)
        {
            cin>>op[i];
            r+=op[i];
        }
        sort(op+1,op+n+1,greater<int>());
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(dis(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}
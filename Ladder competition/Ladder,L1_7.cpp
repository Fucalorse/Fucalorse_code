#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=1e5+90,LEN=31,inf=2e9;

int x,len;
LL f[MAX+90];

bool dis()
{
    LL ans=0;
    int i=1;
    while(ans<x)
    {
        if(!f[i]) f[i]=i;
        else
        {
            if(f[i]>=inf) return false;
            else f[i]*=i;
        }
        ans+=f[i];
        // cout<<f[i]<<' '<<ans<<endl;
        i++;
    }
    if(ans==x) len=i-1;
    return ans==x;
}

int main()
{
    cin>>x;
    int ans=-1;
    for(int i=1;i<=LEN;i++)
        if(dis()) ans=i;
    if(ans==-1) cout<<"Impossible for "<<x<<"."<<endl;
    else
    {
        for(int i=1;i<=len;i++)
        {
            if(i>1) cout<<'+';
            cout<<i<<'^'<<ans;
        }
        cout<<endl;
    }
    return 0;
}
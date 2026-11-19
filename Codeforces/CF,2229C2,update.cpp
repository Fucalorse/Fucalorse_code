#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int a[MAX];
LL pre[MAX],suf[MAX];

void solve()
{
    cin>>n;

    int pos=-1;
    LL maxn=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn+=a[i];
        pre[i]=pre[i-1]+abs(a[i]);
    }

    suf[n+1]=0;
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+a[i];

    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            LL now=pre[i-1]-a[i]+suf[i+1];
            if(now>maxn)
            {
                maxn=now;
                pos=i;
            }
        }
    }
    
    vector<int>id;
    if(pos!=-1)
    {
        bool flip=false;

        for(int i=pos-1;i>=1;i--)
        {
            if((a[i]>0&&!flip)||(a[i]<0&&flip))
            {
                id.push_back(i);
                flip^=1;
            }
        }
        id.push_back(pos);        
    }

    cout<<id.size()<<endl;
    for(auto &cur:id)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
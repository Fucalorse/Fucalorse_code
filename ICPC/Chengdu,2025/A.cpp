#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int d[MAX],b[MAX];

void solve()
{
    cin>>n;
    int cnt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        b[i]=d[i];
        if(d[i]) ++cnt;
        sum+=d[i];
    }
    if(sum<100)
    {
        if(2*sum+n<=200)
        {
            cout<<"NO"<<endl;
            return;
        }
        int r=100-sum;
        for(int i=1;i<=n;i++)
            b[i]=n*b[i]+r;
    }
    else if(sum>100)
    {
        if(2*sum-cnt>200)
        {
            cout<<"NO"<<endl;
            return;
        }

        int now_cnt=2*(sum-100);
        for(int i=1,now=0;i<=n;i++)
            if(b[i])
            {
                if(now<now_cnt)
                {
                    ++now;
                    b[i]=10*b[i]-5;
                }
                else b[i]*=10;
            }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
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
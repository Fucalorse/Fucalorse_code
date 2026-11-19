#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'
const int MAX=100,LEN=20;

int t,n,k;
int op[MAX];
LL f[MAX];

void create()
{
    f[0]=3;
    LL a=9,b=1;
    for(int i=1;i<=LEN;i++)
    {
        f[i]=a+i*b;
        a*=3,b*=3;
    }
}

void peach()
{
    cin>>n>>k;
    int total=0,qwq=0;
    while(n)
    {
        op[qwq]=n%3;
        total+=op[qwq];
        n/=3;
        qwq++;
    }
    --qwq;
    if(total>k)
    {
        cout<<-1<<'\n';
        return;
    }
    k=(k-total)>>1;
    for(int i=qwq;i>=1;i--)
    {
        if(op[i]<=k)
        {
            op[i-1]+=3*op[i];
            k-=op[i];
            op[i]=0;
        }
        else
        {
            op[i-1]+=3*k;
            op[i]-=k;
            break;
        }
    }
    LL ans=0;
    for(int i=0;i<=qwq;i++)
        ans+=op[i]*f[i];
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    create();
    cin>>t;
    while(t--) peach();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int n,q;
LL k;
LL a[MAX],l[MAX],r[MAX];

void solve()
{
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        l[i]=l[i-1]+(a[i]>a[i+1]);
    for(int i=n;i>=2;i--)
        r[i]=r[i+1]+(a[i]>a[i-1]);
    while(q--)
    {
        LL x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2) swap(x1,x2),swap(y1,y2);
        LL h1=y1>a[x1]?(y1-a[x1]-1)/k+1:0,h2=y2>a[x2]?(y2-a[x2]-1)/k+1:0;
        // cout<<h1<<' '<<h2<<endl;
        if(h1<h2)
        {
            LL now=x1==x2?0:l[x2-1]-l[x1-1];
            LL cost=max(llabs(h1-h2)-now,0LL)+x2-x1;
            cout<<cost<<endl;
        }
        else
        {
            LL now=x1==x2?0:r[x1+1]-r[x2+1];
            // cout<<"1::"<<r[x2]-r[x1+1]<<endl;
            LL cost=max(llabs(h1-h2)-now,0LL)+x2-x1;
            cout<<cost<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}
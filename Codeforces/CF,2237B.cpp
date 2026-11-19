#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

struct qwq
{
    int id,val;
}op[MAX];

int n;
int a[MAX],b[MAX],c[MAX],id[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
        op[i]={i,a[i]};
    }
    for(int i=1;i<=n;i++)
        cin>>b[i];

    sort(c+1,c+n+1);

    for(int i=1;i<=n;i++)
        if(c[i]>b[i])
        {
            cout<<-1<<endl;
            return;
        }

    for(int i=1;i<=n;i++)
    {
        int pos=-1,minn=INF;

        for(int j=i;j<=n;j++)
        {
            if(op[j].val>b[i]) continue;

            if(op[j].id<minn)
            {
                minn=op[j].id;
                pos=j;
            }
        }

        // for(int i=1;i<=n;i++)
        //     cout<<op[i].val<<' '<<op[i].id<<endl;
        // cout<<endl;

        id[i]=op[pos].id;
        swap(op[i],op[pos]);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<id[i]<<' ';
    // cout<<endl;

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(id[i]>id[j]) ++ans;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
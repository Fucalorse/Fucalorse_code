#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=13;

int T,n;
LL h[MAX],f[MAX][LEN+3];

void create()
{
    int m=n<<1;
    for(int i=1;i<=m;i++)
        f[i][0]=h[i];
    
    for(int k=1;k<=LEN;k++)
        for(int i=1;i+(1<<k)-1<=m;i++)
            f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
}

LL query(int st,int ed)
{
    int k=log2(ed-st+1);

    return max(f[st][k],f[ed-(1<<k)+1][k]);
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        h[i+n]=h[i];
    }

    create();

    for(int pos=1;pos<=n;++pos)
    {
        LL sum=0;

        for(int i=pos+1;i<pos+n;i++)
        {
            LL max_pre=query(pos,i-1);
            LL max_suf=query(i,pos+n-1);
            
            sum+=min(max_pre,max_suf);
        }

        cout<<sum<<' ';
    }
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e5+90,inf=2e9;

struct qwq
{
    int l,r,len;
    bool operator<(const qwq &a)const { return len>a.len; }
}op[MAX];

int T,n,k;
int fa[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=k;i++)
    {
        int l,r;
        cin>>l>>r;
        op[i]={l,r,r-l+1};

        fa[l]=0;
        for(int j=l+1;j<=r;j++)
            fa[j]=j-1;
    }
    
    if(k==1)
    {
        for(int i=1;i<=n;i++)
            cout<<fa[i]<<' ';
        cout<<endl;
        return;
    }

    sort(op+1,op+k+1);

    if(op[1].len==op[k].len||(op[1].len==op[2].len&&op[1].len-op[k].len<=1))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    if(op[1].len==op[2].len)
    {
        fa[op[k].l]=op[1].l+1;
        for(int i=2;i<k;i++)
            fa[op[i].l]=op[1].l;
    }
    else
    {
        for(int i=2;i<=k;i++)
            fa[op[i].l]=op[1].l;
    }

    for(int i=1;i<=n;i++)
        cout<<fa[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>T;
    while(T--) solve();
    return 0;
}

// g++ H.cpp -O2 -o out.exe && out.exe < in.txt
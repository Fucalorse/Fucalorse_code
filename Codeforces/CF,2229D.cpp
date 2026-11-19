#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int T,n;
int a[MAX],b[MAX],col[MAX],rest[MAX];

bool check(const int &mid)
{
    int qwq=0;

    for(int i=1;i<=n;i++)
    {
        int pa=a[i]>=mid?1:0;
        int pb=b[i]>=mid?1:0;

        if(pa&&pb) col[i]=1;
        else if(pa^pb) col[i]=2;
        else col[i]=0;

        if(col[i]!=2) rest[++qwq]=col[i];
    }

    stack<int>st;
    for(int i=1;i<=qwq;i++)
    {
        while(st.size()&&rest[i]==0&&rest[i]==rest[st.top()]) st.pop();

        st.push(i);
    }

    int c1=0,c0=0;
    while(st.size())
    {
        int pos=st.top();
        if(rest[pos]==1) ++c1;
        else if(rest[pos]==0) ++c0;

        st.pop();
    }

    return c1>c0;
}

void solve()
{
    cin>>n;

    int l=inf,r=-inf;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l=min(l,a[i]);
        r=max(r,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        l=min(l,b[i]);
        r=max(r,b[i]);
    }

    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    cout<<r<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
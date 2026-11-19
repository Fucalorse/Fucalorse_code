#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

struct qwq
{
    int l,r;
}op[MAX];

int T,n;
int a[MAX],sz[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        op[i]={0,0};
}

void dfs(int pos)
{
    if(!pos) return;

    sz[pos]=1;
    dfs(op[pos].l);
    dfs(op[pos].r);

    sz[pos]+=sz[op[pos].l]+sz[op[pos].r];
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>minn(n+3,inf);
    for(int i=n;i>=1;i--)
    {
        if(a[i]<minn[i+1]) minn[i]=a[i];
        else minn[i]=minn[i+1];
    }

    stack<int>st;
    vector<int>fa(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int last=0;
        while(st.size()&&a[st.top()]>=a[i])
        {
            last=st.top();
            st.pop();
        }

        if(st.size())
        {
            op[st.top()].r=i;
            fa[i]=st.top();
        }

        if(last)
        {
            op[i].l=last;
            fa[last]=i;
        }

        st.push(i);
    }

    int root=1;
    while(fa[root]) root=fa[root];

    dfs(root);
    // cout<<root<<' ';

    LL total=0,ans=0;
    for(int i=1;i<=n;i++)
        if(a[i]>minn[i+1]) total+=a[i]-minn[i+1];
    
    for(int i=1;i<=n;i++)
    {
        int dx=sz[op[i].l];
        ans=max(ans,total+dx);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
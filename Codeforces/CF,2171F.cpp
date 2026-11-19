#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

struct peach
{
    private:
        vector<int>fa;
    public:
        peach(int n)
        {
            fa.assign(n+3,0);
            for(int i=0;i<=n;i++)
                fa[i]=i;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y) { fa[find(x)]=find(y); }
};

int t,n;
int a[MAX],pre[MAX],suf[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    pre[0]=inf,suf[n+1]=0;
    for(int i=1;i<=n;i++)
        pre[i]=min(pre[i-1],a[i]);
    for(int i=n;i>=1;i--)
        suf[i]=max(suf[i+1],a[i]);
    // for(int i=1;i<=n;i++)
    //     cout<<pre[i]<<' '<<suf[i]<<endl;
    vector<pair<int,int>>ans;
    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        int x=a[i],y=suf[i];
        if(fu.find(x)==fu.find(y)) continue;
        fu.combine(x,y);
        ans.push_back({x,y});
    }
    for(int i=2;i<=n;i++)
        if(pre[i-1]<suf[i])
        {
            int x=pre[i-1],y=suf[i];
            if(fu.find(x)==fu.find(y)) continue;
            fu.combine(x,y);
            ans.push_back({x,y});
        }
    if((int)ans.size()==n-1)
    {
        cout<<"YES"<<endl;
        for(auto &[x,y]:ans)
            cout<<x<<' '<<y<<endl;
    }
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
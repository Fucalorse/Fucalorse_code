#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct ovo
{
    int val,id;
    bool operator<(const ovo &a)const { return val<a.val; }
}a[MAX];

int t,n,m;

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    if(m*2>n)
    {
        cout<<-1<<endl;
        return;
    }
    sort(a+1,a+n+1);
    vector<pair<int,int>>ans;
    if(!m)
    {
        int sum=0,pos;
        for(pos=n-1;pos>=1;pos--)
        {
            if(sum+a[pos].val>=a[n].val) break;
            sum+=a[pos].val;
        }
        if(!pos) cout<<-1<<endl;
        else
        {
            for(int i=2;i<=pos;i++)
                ans.push_back({a[i-1].id,a[i].id});
            for(int i=pos;i<=n-1;i++)
                ans.push_back({a[i].id,a[n].id});
            cout<<ans.size()<<endl;
            for(auto &[u,v]:ans)
                cout<<u<<' '<<v<<endl;
        }
        return;
    }
    int l=1,mid=n-2*m+1,r=n-m+1;
    for(int i=l+1;i<=mid;i++)
        ans.push_back({a[i-1].id,a[i].id});
    for(int i=mid;i<r;i++)
        ans.push_back({a[i+m].id,a[i].id});
    cout<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
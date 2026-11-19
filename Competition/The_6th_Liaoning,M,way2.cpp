#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

struct qwq
{
    LL a,b;
    bool operator<(const qwq &other)const
    {
        if(max(a,b)!=max(other.a,other.b)) return max(a,b)<max(other.a,other.b);
        else return min(a,b)<min(other.a,other.b);
    }
}op[MAX];

int n;

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i].a>>op[i].b;
    sort(op+1,op+n+1);
    LL maxn=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(maxn<=op[i].a)
        {
            maxn=max(maxn,op[i].b);
            ++ans;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}
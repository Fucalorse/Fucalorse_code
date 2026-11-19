#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e6+90;

struct qwq
{
    LL pos,val;
    bool operator<(const qwq &a)const { return pos>a.pos; }
};

int n,st,ed;
LL k,f[MAX],a[MAX];
priority_queue<qwq>q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>st>>ed>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>f[i]>>a[i];
        q.push({f[i],a[i]});
    }
    LL now=st,ans=0;
    while(q.size())
    {
        LL cnt=0;
        while(q.size()&&cnt<k)
        {
            auto [pos,val]=q.top();q.pop();
            ans+=llabs(now-pos),now=pos;
            if(cnt+val<=k) cnt+=val;
            else
            {
                val-=k-cnt;
                cnt=k;
                q.push({pos,val});
            }
        }
        ans+=llabs(ed-now),now=ed;
    }
    cout<<ans<<'\n';
    return 0;
}
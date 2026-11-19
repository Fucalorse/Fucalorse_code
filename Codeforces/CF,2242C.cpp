#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90;

struct qwq
{
    int num,cnt;
    bool operator<(const qwq &a)const { return cnt<a.cnt; }
}op[MAX];

int T,n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    vector<int>cnt(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    int m=0;
    for(int i=1;i<=n;i++)
        if(cnt[i]) op[++m]={i,cnt[i]};

    sort(op+1,op+m+1);
    
    vector<int>suf(m+3,0);
    for(int i=m;i>=1;i--)
        suf[i]=suf[i+1]+op[i].cnt;

    int ans=0;
    op[0].cnt=-10086;
    for(int i=0;i<m;i++)
        if(op[i].cnt!=op[i+1].cnt)
        {
            int now_cnt=m-i,rest=k-(suf[i+1]-(op[i+1].cnt-1)*now_cnt);
            if(rest>=0&&rest%now_cnt==0) ++ans;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=998244353,INF=2e9;

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

struct qwq
{
    LL val;
    int cnt;
    bool operator<(const qwq &a)const { return cnt>a.cnt; }
}op[MAX];

int n;
LL a[MAX];

int cal(LL x)
{
    int ans=0;

    while(1)
    {
        if(x&1) break;
        x>>=1;
        ++ans;
    }

    return ans;
}

void solve()
{
    cin>>n;

    priority_queue<qwq>q;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int cnt=cal(a[i]);
        q.push({a[i],cnt});
    }

    while((int)q.size()>1)
    {
        qwq num1=q.top();q.pop();
        qwq num2=q.top();q.pop();

        LL val=gcd(num1.val,num2.val)*2;
        int cnt=cal(val);

        q.push({val,cnt});
    }

    cout<<q.top().val<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,MOD=1e9+7,INF=2e9,P=0x45d9f3b;

LL cal(const vector<int>& op)
{
    LL ans=0;
    for(auto &cur:op)
        ans=(ans*P+cur)%MOD;
    return ans;
}

struct qwq
{
    int l,r,id;
}op[MAX];

int n,k,q,block;
int num[MAX];
string s;

bool cmp(const qwq &a,const qwq &b)
{
    int bl=(a.l-1)/block+1,br=(b.l-1)/block+1;

    if(bl!=br) return bl<br;
    else
    {
        if(bl&1) return a.r<b.r;
        else return a.r>b.r;
    }
}

void solve()
{
    cin>>n>>k>>q>>s;s=' '+s;

    for(int i=1;i<=n;i++)
        num[i]=s[i]-'a';

    for(int i=1;i<=q;i++)
    {
        cin>>op[i].l>>op[i].r;
        --op[i].l;
        op[i].id=i;
    }

    block=sqrt(n);

    sort(op+1,op+q+1,cmp);

    int tot=0;
    vector<int>freq(26,0),state(n+1);
    map<vector<int>,int>mp;

    mp[freq]=++tot;
    state[0]=tot;

    for(int i=1;i<=n;i++)
    {
        freq[num[i]]++;
        if(freq[num[i]]==k) freq[num[i]]=0;

        if(mp.count(freq)) state[i]=mp[freq];
        else
        {
            mp[freq]=++tot;
            state[i]=tot;
        }
    }

    LL now_ans=0;
    vector<int>cnt(tot+1,0);
    vector<LL>ans(q+1,0);

    auto add=[&](int pos)
    {
        int now_state=state[pos];
        now_ans+=cnt[now_state];
        ++cnt[now_state];
    };

    auto del=[&](int pos)
    {
        int now_state=state[pos];
        --cnt[now_state];
        now_ans-=cnt[now_state];
    };

    int curL=0,curR=-1;
    for(int i=1;i<=q;i++)
    {
        auto [l,r,id]=op[i];

        while(curL>l) add(--curL);
        while(curR<r) add(++curR);
        while(curL<l) del(curL++);
        while(curR>r) del(curR--);

        ans[id]=now_ans;
    }

    for(int i=1;i<=q;i++)
        cout<<ans[i]<<endl;
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
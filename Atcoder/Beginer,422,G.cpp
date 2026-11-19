#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

istream& operator>>(istream& in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f<0) x=-x;

    return in;
}

ostream& operator<<(ostream& out,i128 x)
{
    if(!x)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

struct qwq
{
    LL val,cnt;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n;
LL c;

void solve()
{
    cin>>n>>c;

    vector<vector<qwq>>op(4);
    vector<LL>freq(4);

    for(int i=1;i<=n;i++)
    {
        int wei;
        qwq now;
        cin>>wei>>now.val>>now.cnt;
        freq[wei]+=now.cnt;
        op[wei].push_back(now);
    }

    for(int i=1;i<=3;i++)
        sort(op[i].begin(),op[i].end(),[&](const qwq &a,const qwq &b){
            return a.val>b.val;
        });

    i128 ans=0,base=0;

    auto update=[&](int r,const int &each,const vector<qwq>& now,priority_queue<qwq>& q)
    {
        int len=now.size(),pos=0;
        LL pre_wei=0,pre_sum=0;

        auto add=[&](LL cnt,LL val)
        {
            if(pre_wei+cnt*each<6)
            {
                pre_wei+=cnt*each;
                pre_sum+=val*cnt;
                return;
            }

            LL cost=(6-pre_wei)/each;
            q.push({pre_sum+cost*val,1});
            cnt-=cost;

            LL every=6/each;
            q.push({every*val,cnt/every});
            cnt%=every;

            pre_wei=cnt*each,pre_sum=cnt*val;
        };

        while(pos<len)
        {
            if(now[pos].cnt>=r)
            {
                base+=now[pos].val*r;

                LL rest=now[pos].cnt-r;
                add(rest,now[pos].val);
                ++pos;
                break;
            }
            else
            {
                base+=now[pos].val*now[pos].cnt;
                r-=now[pos].cnt;
                ++pos;
            }
        }

        while(pos<len)
        {
            add(now[pos].cnt,now[pos].val);
            ++pos;
        }
    };

    for(int r1=0;r1<=5;++r1)
        for(int r2=0;r2<=2;++r2)
            for(int r3=0;r3<=1;++r3)
            {
                if(r1>freq[1]||r2>freq[2]||r3>freq[3]||r1+2*r2+3*r3>c) continue;

                base=0;
                priority_queue<qwq>q;
                update(r1,1,op[1],q);
                update(r2,2,op[2],q);
                update(r3,3,op[3],q);

                LL limit=(c-r1-2*r2-3*r3)/6;
                while(limit&&q.size())
                {
                    auto [val,cnt]=q.top();q.pop();

                    LL take=min(limit,cnt);
                    limit-=take;
                    base+=(i128)take*val;
                }

                ans=max(ans,base);
            }

    cout<<ans<<endl;
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
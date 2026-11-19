#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=9e5,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

string s;
vector<array<int,10>>f(LEN+1);

array<int,10> cal(int num)
{
    array<int,10>cnt{};
    while(num)
    {
        ++cnt[num%10];
        num/=10;
    }
    return cnt;
}

void create()
{
    auto update=[&](int num)
    {
        int pre=num;
        array<int,10>cnt{};
        while(num>9)
        {
            int nxt=0;
            auto ncnt=cal(num);
            for(int i=0;i<=9;i++)
            {
                cnt[i]+=ncnt[i];
                nxt+=ncnt[i]*i;
            }
            num=nxt;
        }
        auto ncnt=cal(num);
        for(int i=0;i<=9;i++)
            cnt[i]+=ncnt[i];

        f[pre]=cnt;
    };

    for(int i=1;i<=LEN;i++)
        update(i);
}

string construct(const array<int,10>& cnt,int x)
{
    string ans="";
    for(int i=9;i>=0;i--)
    {
        if(!cnt[i]) continue;
        string now=string(cnt[i],i+'0');
        ans+=now;
    }
    ans+=to_string(x);

    while(x>9)
    {
        auto cnt=cal(x);
        int nxt=0;
        for(int i=0;i<=9;i++)
            nxt+=cnt[i]*i;
        ans+=to_string(nxt);
        x=nxt;
    }
    return ans;
}

void print(const array<int,10>& op)
{
    for(int i=0;i<=9;i++)
        cout<<op[i]<<' ';
    cout<<endl<<flush;
}

void solve()
{
    cin>>s;

    if((int)s.size()==1)
    {
        cout<<s<<endl;
        return;
    }
    
    array<int,10>s_cnt{},cur_cnt{};
    int max_num=9*(int)s.size();
    for(auto &cur:s)
    {
        int num=cur-'0';
        ++s_cnt[num];
    }

    for(int x=1;x<=max_num;x++)
    {
        auto &cnt=f[x];
        bool ok=true;
        for(int i=0;i<=9;i++)
        {
            cur_cnt[i]=s_cnt[i]-cnt[i];
            if(cur_cnt[i]<0)
            {
                ok=false;
                break;
            }
        }
        if(!ok) continue;

        int sum=0;
        for(int i=0;i<=9;i++)
            sum+=i*cur_cnt[i];

        if(sum==x)
        {
            cout<<construct(cur_cnt,x)<<endl;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
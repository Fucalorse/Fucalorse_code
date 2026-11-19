#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];
string s;

void print(deque<pair<int,int>> &q)
{
    for(auto &cur:q)
        for(int i=1;i<=cur.first;i++)
            cout<<cur.second;
    cout<<endl;    
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>s;s=' '+s;

    LL cnt0=0,cnt1=0,total=0;
    deque<pair<int,int>>q;

    for(int l=1,r=1;l<=n&&r<=n;l=r)
    {
        while(r<=n&&a[l]==a[r]) ++r;
        q.push_back({r-l,a[l]});
    }

    for(int i=n;i>=1;i--)
    {
        if(a[i]==1) total+=cnt0,++cnt1;
        else ++cnt0;
    }

    cout<<total<<' ';

    for(int i=1;i<=n;i++)
    {
        if((int)q.size()==1)
        {
            cout<<total<<' ';
            continue;
        }
        
        if(s[i]=='1')
        {
            if(q.front().second==1)
            {
                LL inv_cnt=cnt0;
                total-=inv_cnt;

                if(q.front().first==1) q.pop_front();
                else q.front().first--;

                if(q.size()&&q.back().second==1) q.back().first++;
                else q.push_back({1,1});
            }
            else
            {
                LL inv_cnt=cnt0-q.front().first;
                total-=inv_cnt;

                auto pre=q.front();q.pop_front();

                if(q.front().first==1) q.pop_front();
                else q.front().first--;

                if(q.size()&&q.back().second==1) q.back().first++;
                else q.push_back({1,1});

                if(q.size()&&pre.second==q.front().second) q.front().first+=pre.first;
                else q.push_front(pre);
            }
        }
        else
        {
            if(q.back().second==0)
            {
                LL inv_cnt=cnt1;
                total-=inv_cnt;

                if(q.back().first==1) q.pop_back();
                else q.back().first--;

                if(q.size()&&q.front().second==0) q.front().first++;
                else q.push_front({1,0});
            }
            else
            {
                LL inv_cnt=cnt1-q.back().first;
                total-=inv_cnt;

                auto suf=q.back();q.pop_back();

                if(q.back().first==1) q.pop_back();
                else q.back().first--;

                if(q.size()&&q.front().second==0) q.front().first++;
                else q.push_front({1,0});

                if(q.size()&&suf.second==q.back().second) q.back().first+=suf.first;
                else q.push_back(suf);
            }
        }

        cout<<total<<' ';
    }

    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
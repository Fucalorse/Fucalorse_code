#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e4,MOD=998244353;
const LL INF=1e18;

LL x,y;

void solve()
{
    cin>>x>>y;

    LL minn=INF,total,step;
    for(LL k=1;k<=LEN;k++)
    {
        LL S=(k+1)*k/2;
        if(S>x+y) break;

        LL st=max(0LL,S-min(y,S)),ed=min(S,min(x,S));
        LL best1=(S+x-y)/2,best2=(S+x-y+1)/2;

        auto update=[&](LL pos)
        {
            if(pos<st) pos=st;
            if(pos>ed) pos=ed;

            LL con1=x-pos,con2=y-S+pos;
            LL now=con1*con1+con2*con2;

            if(now<minn)
            {
                minn=now;
                total=pos,step=k;
            }
        };

        update(best1),update(best2);
    }

    string s;
    for(LL k=step;k>=1;k--)
    {
        if(total>=k)
        {
            total-=k;
            s.push_back('X');
        }
        else s.push_back('Y');
    }

    cout<<s<<endl;
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
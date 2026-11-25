#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL y;
string s;

void solve()
{
    cin>>n>>y>>s;s=' '+s;

    LL total=y;
    int preE=0,preI=0;
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]=='E') ++preE;
        else ++preI;
    }

    auto cal_solo_time=[&](LL pre_time,LL T)->LL
    {
        LL rest=max(0LL,total-pre_time);
        return rest/T*3LL+min(3LL,rest%T);
    };

    auto cal=[&](int cntE,int cntI)->LL { return (cntE+1)/2*4+cntI*3; };

    LL TI=preE<=1?n*3:(preE+1)/2*4+(preI+1)*3;
    LL timeI=cal_solo_time(TI-3,TI),timeE=timeI;

    if(preE>=1)
    {
        s[n]='E';
        int cE=preE+1,cI=preI;
        LL TE=(cE+1)/2*4+cI*3;
        
        for(int i=1,ci=0,ce=0;i<=n;i++)
        {
            if(s[i]=='E') ++ce;
            else
            {
                y-=cal_solo_time(cal(ce,ci),TE);
                ++ci;
            }
        }

        LL T=(cE+1)/2*4LL;
        LL cnt=y/T,r=y%T;
        timeE=4LL*cnt;
        if(cE&1) timeE+=4LL*(cnt/cE);

        int pos=cE-1;
        if(cE&1) pos-=cnt%cE;
        for(int i=0;r>0;i+=2)
        {
            int u=i,v=(i+1)%cE;
            if(u==pos||v==pos) timeE+=min(4LL,r);
            r-=4LL;
        }
    }

    if(timeI==timeE) cout<<"Same"<<endl;
    else if(timeI>timeE) cout<<"I"<<endl;
    else cout<<"E"<<endl;
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
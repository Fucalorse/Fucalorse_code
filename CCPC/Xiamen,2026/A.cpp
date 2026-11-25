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

    int preE=0,preI=0;
    for(int i=1;i<=n-1;i++)
    {
        if(s[i]=='E') ++preE;
        else ++preI;
    }

    LL timeI=0,timeE=0;
    //I
    {
        LL T;
        int cE=preE,cI=preI+1;
        
        if(cE<=1) T=n*3;
        else T=(cE+1)/2*4+cI*3;
        LL cnt=y/T,r=y%T;
        timeI=cnt*3+max(0LL,r-(T-3));
    }

    //E
    {
        int cE=preE+1,cI=preI;

        if(cE<=1)
        {
            LL T=n*3;
            LL cnt=y/T,r=y%T;
            timeE=cnt*3+max(0LL,r-(T-3));
        }
        else
        {
            if(cE&1)
            {
                LL T=(cE+1)/2*4+cI*3;
                LL cnt=y/T,r=y%T;

                if(cnt==0) timeE=max(0LL,r-(T-4LL));
                else
                {
                    s[n]='E';
                    timeE=4LL*(cnt+cnt/cE);
                    vector<char>op;
                    for(int l=1,r=1,take=0;l<=n;l=r)
                    {
                        while(r<=n&&s[l]==s[r]) ++r;
                        if(s[l]=='I')
                        {
                            for(int i=l;i<r;i++)
                                op.push_back('I');
                        }
                        else
                        {
                            int now=r-l-take;
                            if(now&1) take=1,now++;
                            else take=0;

                            for(int i=1;i<=now;i++)
                                op.push_back('E');
                        }
                    }

                    int pos=cE-1-(cnt%cE);
                    for(int i=0,now=0;i<n&&r>0;)
                    {
                        if(op[i]=='I')
                        {
                            r-=3LL;
                            i++;
                        }
                        else
                        {
                            int u=now,v=(now+1)%cE;
                            if(u==pos||v==pos) timeE+=min(4LL,r);
                            r-=4LL;
                            i+=2;
                            now+=2;
                        }
                    }
                }
            }
            else
            {
                int interval_cI=0;
                for(int i=n-1;i>=1;i--)
                {
                    if(s[i]=='I') ++interval_cI;
                    else break;
                }

                LL preT=cE/2*4+(cI-interval_cI)*3;
                if(y<=preT)
                {
                    LL r=y;
                    r=max(0LL,r-(preT-4));
                    timeE+=r;
                }
                else
                {
                    timeE+=4;
                    y-=preT;
                    LL T=cE/2*4+cI*3;
                    LL cnt=y/T,r=y%T;
                    timeE+=cnt*4+max(0LL,r-(T-4));
                }
            }
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
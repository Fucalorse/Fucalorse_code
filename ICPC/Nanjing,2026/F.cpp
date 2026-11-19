#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=6,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
const vector<LL>Val={0LL,1000LL,200LL,300LL,400LL,500LL,600LL};

void solve()
{
    array<LL,7>a;
    for(int i=1;i<=6;i++)
        cin>>a[i];

    LL ans=0;
    for(int c1=0;c1<=2;c1++)
    {
        if(c1>*min_element(a.begin()+1,a.begin()+6)) break;
        array<LL,7>f=a;
        for(int i=1;i<=5;i++)
            f[i]-=c1;
        LL r1=500LL*c1;

        for(int c3=0;c3<=2;c3++)
        {
            if(c3>*min_element(f.begin()+1,f.end())) break;

            array<LL,7>g=f;
            for(int i=1;i<=6;i++)
                g[i]-=c3;

            LL min_c3=*min_element(g.begin()+1,g.end());
            LL del_num=min_c3/3*3;
            for(int i=1;i<=6;i++)
                g[i]-=del_num;
            LL r3=1500LL*(c3+del_num);

            for(int c2=0;c2<=2;c2++)
            {
                if(c2>*min_element(g.begin()+2,g.end())) break;
                
                array<LL,7>h=g;
                for(int i=2;i<=6;i++)
                    h[i]-=c2;

                LL min_c2=*min_element(g.begin()+2,g.end());
                LL del_num=min_c2/3*3;
                for(int i=2;i<=6;i++)
                    h[i]-=del_num;
                LL r2=750LL*(c2+del_num);

                LL now=r1+r2+r3;
                for(int i=1;i<=6;i++)
                {
                    now+=h[i]/3*Val[i];
                    h[i]%=3;
                }

                now+=h[1]*100LL+h[5]*50LL;
                ans=max(ans,now);
            }
        }
    }

    cout<<ans<<endl;
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
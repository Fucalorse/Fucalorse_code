#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct interval
{
    int l,r;
}op[MAX];

int n;

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
        cin>>op[i].l;
    for(int i=1;i<=n;i++)
        cin>>op[i].r;

    vector<int>pos{0};
    for(int i=1;i<=n;i++)
        if(op[i].r-op[i].l+1>=3) pos.push_back(i);
    pos.push_back(n+1);

    // for(auto &cur:pos)
    //     cout<<cur<<' ';
    // cout<<endl;

    int len=(int)pos.size(),tot=0;
    LL ans=(int)pos.size()-2;
    vector<int>belong(n+1,0),Len(n+1,0);
    for(int i=0;i<len-1;i++)
    {
        int L=pos[i],R=pos[i+1];
        if(L+1==R) continue;

        vector<int>cur={L};
        for(int j=L+1;j<R;j++)
            if(op[j].r==op[j].l) cur.push_back(j);
        cur.push_back(R);

        // for(auto &x:cur)
        //     cout<<op[x].l<<' '<<op[x].r<<endl;
        // cout<<endl;

        int len_cur=(int)cur.size();
        for(int l=1,r=1;l<len_cur-1;l=r)
        {
            r=l+1;
            while(r<len_cur-1&&cur[r]==cur[r-1]+1&&op[cur[r]].l==op[cur[r-1]].l) ++r;

            ++tot;
            ans+=1LL*(r-l)*(r-l);
            for(int j=l;j<r;j++)
            {
                // printf("%d %d\n",cur[j],n);
                // assert(cur[j]<=n);
                belong[cur[j]]=tot;
            }
            Len[tot]=r-l;
        }

        for(int j=0;j<len_cur-1;j++)
        {
            int X=cur[j],Y=cur[j+1];
            if(X+1==Y) continue;

            if(X==L||Y==R)
            {
                ans+=Y-X-1;
                continue;
            }

            int pre=op[X].l;
            bool free=false;
            for(int k=X+1;k<Y;k++)
            {
                auto [numa,numb]=op[k];
                if(numa!=pre&&numb!=pre)
                {
                    free=true;
                    break;
                }

                if(numa==pre) pre=numb;
                else pre=numa;
            }

            if(free) ans+=Y-X-1;
            else
            {
                if(pre!=op[Y].l)
                {
                    ans+=Y-X-1;
                    continue;
                }

                if(X+2==Y)
                {
                    if(Len[belong[X]]<=Len[belong[Y]])
                    {
                        ans+=2*Len[belong[X]]+1;
                        Len[belong[X]]++;
                    }
                    else
                    {
                        ans+=2*Len[belong[Y]]+1;
                        Len[belong[Y]]++;
                    }
                }
                else ans+=Y-X+1;
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
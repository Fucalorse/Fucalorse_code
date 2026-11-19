#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct fucalorse
{
    private:
        int n;
        vector<vector<int>>f;
    public: 
        fucalorse(int _n,int *a)
        {
            n=_n;
            int size=31-__builtin_clz(n);

            f.assign(size+1,vector<int>(n+1,-INF));
            for(int i=1;i<=n;i++)
                f[0][i]=a[i];

            for(int k=1;k<=size;k++)
                for(int i=1;i+(1<<k)-1<=n;i++)
                    f[k][i]=max(f[k-1][i],f[k-1][i+(1<<(k-1))]);
        }

        int query(int st,int ed)
        {
            int k=31-__builtin_clz(ed-st+1);
            return max(f[k][st],f[k][ed-(1<<k)+1]);
        }
};

int n,k;
string s;
int pre[MAX],cnt[MAX];

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1],cnt[i]=cnt[i-1];

        if(s[i]=='(') pre[i]++;
        else
        {
            pre[i]--;
            cnt[i]++;
        }
    }

    int ans=-INF;
    fucalorse fu(n,pre);

    //prefix
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>k) break;
        int now=min(n/2,pre[i]+k);
        ans=max(ans,now);
    }

    //middle
    for(int l=1,r=1;l<=n;l++)
    {
        while(r<=n&&cnt[r]<cnt[l]+k+1) ++r;
        int now=fu.query(l,r-1)-pre[l];
        ans=max(ans,now);
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
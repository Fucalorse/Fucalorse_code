#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=7,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct Bit
{
    private:
        int n;
        vector<int>op;
    public:
        Bit(int _n):n(_n),op(_n+1,0){}

        void update(int pos,int k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        int query(int pos)
        {
            int ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }

        int find()
        {
            int pos=0,cnt=0;
            for(int k=LEN;k>=0;k--)
            {
                int npos=pos|1<<k;
                if(npos<=n&&cnt+op[npos]==npos)
                {
                    cnt+=op[npos];
                    pos=npos;
                }
            }
            return pos;
        }
};

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int maxn=0;
    pair<int,int>best={0,0};

    auto update=[&](int i,int j)->void
    {
        swap(a[i],a[j]);

        vector<int>ans;
        vector<bool>vis(n+1,false);
        Bit fu(n);
        for(int pos=1;pos<=n;pos++)
        {
            if(!vis[a[pos]])
            {
                vis[a[pos]]=true;
                fu.update(a[pos]+1,1);
            }
            ans.push_back(fu.find());
        }
        sort(ans.begin(),ans.end(),greater<int>());
        if(ans[k-1]>maxn)
        {
            maxn=ans[k-1];
            best={i,j};
        }
        
        swap(a[i],a[j]);
    };
    update(0,0);

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            update(i,j);

    if(best.first==0) cout<<-1<<endl;
    else  cout<<best.first<<' '<<best.second<<endl;
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
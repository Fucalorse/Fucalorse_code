#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=20,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int _n) { size=_n,op.assign(size+5,0); }

        void update(int n,int k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }

        int query(int n)
        {
            int ans=0;

            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }

            return ans;
        }

        int find(int pos)
        {
            int sum=query(pos),now=0,ans=0;
            // cout<<pos<<' '<<sum<<endl;

            for(int k=LEN;k>=0;k--)
            {
                int ed=ans+(1<<k);
                if(ed<pos&&now+op[ed]<sum)
                {
                    now+=op[ed];
                    ans|=1<<k;
                }
            }

            return ans+1;
        }
};

int n,x;
int a[MAX],b[MAX],pa[MAX],pb[MAX];

void solve()
{
    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pa[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        pb[b[i]]=i;
    }

    vector<int>ans;
    set<int>del;
    peach fa(n),fb(n);

    int mina=pa[x],minb=pb[x];
    ans.push_back(x);
    del.insert(x);

    for(int i=n,j=n;;)
    {
        while(i>=1&&i>=mina)
        {
            if(!del.count(a[i]))
            {
                fb.update(pb[a[i]],1);
                // cout<<a[i]<<' '<<pb[a[i]]<<endl;
            }
            i--;
        }
        while(j>=1&&j>=minb)
        {
            if(!del.count(b[j]))
            {
                fa.update(pa[b[j]],1);
                // cout<<b[j]<<' '<<pa[b[j]]<<endl;
            }
            j--;
        }

        // cout<<fb.query(minb-1)<<endl;

        bool updated=false;

        if(fa.query(mina-1))
        {
            int posa=fa.find(mina-1),del_num=a[posa];

            mina=posa;
            ans.push_back(del_num);
            fa.update(pa[del_num],-1);
            del.insert(del_num);

            updated=true;
        }
        else if(fb.query(minb-1))
        {
            int posb=fb.find(minb-1),del_num=b[posb];

            minb=posb;
            ans.push_back(del_num);
            fb.update(pb[del_num],-1);
            del.insert(del_num);

            // cout<<posb<<' '<<del_num<<endl;

            updated=true;
        }

        // cout<<mina<<' '<<minb<<endl;

        if(!updated) break;
    }

    // for(auto &cur:ans)
    //     cout<<cur<<' ';
    // cout<<endl;

    int len=ans.size();
    if(len!=n) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=len-1;i>=1;i--)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
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
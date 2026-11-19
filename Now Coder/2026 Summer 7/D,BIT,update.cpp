#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=20,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int _n) { size=_n,op.assign(size+3,0); }

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

        int find(int tar)
        {
            int total=query(tar),sum=0,pos=0;

            for(int k=LEN;k>=0;k--)
            {
                int npos=pos|(1<<k);
                if(npos<tar&&sum+op[npos]<total)
                {
                    sum+=op[npos];
                    pos=npos;
                }
            }

            return pos+1;
        }
};

int n,x;
int a[MAX],b[MAX],posa[MAX],posb[MAX];

void solve()
{
    cin>>n>>x;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        posa[a[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        posb[b[i]]=i;
    }

    peach fa(n),fb(n);
    vector<int>ans;
    set<int>del;

    del.insert(x),ans.push_back(x);
    int cur_a=posa[x],cur_b=posb[x];

    for(int i=n,j=n;;)
    {
        while(i>=cur_a)
        {
            int x=a[i];
            if(del.count(x)==0) fb.update(posb[x],1);
            i--;
        }
        while(j>=cur_b)
        {
            int x=b[j];
            if(del.count(x)==0) fa.update(posa[x],1);
            j--;
        }

        bool updated=false;
        if(fa.query(cur_a-1))
        {
            int pos=fa.find(cur_a-1);
            ans.push_back(a[pos]);
            fa.update(pos,-1);
            del.insert(a[pos]);
            updated=true,cur_a=pos;
        }
        else if(fb.query(cur_b-1))
        {
            int pos=fb.find(cur_b-1);
            ans.push_back(b[pos]);
            fb.update(pos,-1);
            del.insert(b[pos]);
            updated=true,cur_b=pos;
        }

        if(!updated) break;
    }

    if((int)ans.size()!=n) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;

        for(int i=n-1;i>=1;i--)
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
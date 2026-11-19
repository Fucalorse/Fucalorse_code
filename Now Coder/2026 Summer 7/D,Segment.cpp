#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=20,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int n;
        vector<int>op;

        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r)
            {
                op[id]+=k;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id]=op[hl]+op[hr];
        }

        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id];
            
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        peach(int _n) { n=_n,op.assign((n+90)<<2,0); }

        void update(int x,int k) { dfs(1,n,1,x,k); }

        int get(int st,int ed)
        {
            if(st>ed) return 0;
            return query(1,n,1,st,ed);
        }

        int find(int pos)
        {
            int sum=query(1,n,1,1,pos),l=1,r=n,id=1;

            while(l<r)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                if(sum<=op[hl])
                {
                    id=hl;
                    r=mid;
                }
                else
                {
                    sum-=op[hl];
                    id=hr;
                    l=mid+1;
                }
            }

            return l;
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

        bool updated=false;

        if(fa.get(1,mina-1))
        {
            int posa=fa.find(mina-1),del_num=a[posa];

            mina=posa;
            ans.push_back(del_num);
            fa.update(pa[del_num],-1);
            del.insert(del_num);

            updated=true;
        }
        else if(fb.get(1,minb-1))
        {
            int posb=fb.find(minb-1),del_num=b[posb];

            minb=posb;
            ans.push_back(del_num);
            fb.update(pb[del_num],-1);
            del.insert(del_num);

            updated=true;
        }

        if(!updated) break;
    }

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
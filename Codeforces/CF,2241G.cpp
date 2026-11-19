#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

istream& operator>>(istream &in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f<0) x=-x;

    return in;
}

ostream& operator<<(ostream &out,i128 x)
{
    if(!x)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

struct node
{
    int l,r,id;
};

struct peach
{
    private:
        int n;
        vector<LL>op;

        void create(int l,int r,int id,LL *a)
        {
            if(l==r)
            {
                op[id]=a[l];
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=__gcd(op[hl],op[hr]);
        }

        void query(int l,int r,int id,const int &st,const int &ed,vector<node> &rest)
        {
            if(r<st||l>ed) return;

            if(st<=l&&r<=ed)
            {
                rest.push_back({l,r,id});
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            query(l,mid,hl,st,ed,rest);
            query(mid+1,r,hr,st,ed,rest);
        }
    public:
        peach(int _n,LL *a)
        {
            n=_n;
            op.assign((n+90)<<2,0);
            create(1,n,1,a);
        }

        int get(int st,int ed,LL *a)
        {
            LL num=a[st];
            vector<node>rest;
            query(1,n,1,st,ed,rest);

            for(auto [l,r,id]:rest)
            {
                if(__gcd(op[id],num)==num) continue;

                while(l<r)
                {
                    int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                    if(num==__gcd(op[hl],num))
                    {
                        l=mid+1;
                        id=hr;
                    }
                    else
                    {
                        r=mid;
                        id=hl;
                    }
                }

                if(a[l]%a[st]!=0) return l;
            }

            return n;
        }
};

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    peach fu(n,a);

    i128 ans=0;
    for(int i=1;i<=n;i++)
    {
        int pos=fu.get(i,n,a);
        // cout<<i<<' '<<pos<<endl;
        LL r=a[pos]%a[i];
        LL now=min(a[i]-r,r);
        ans+=now*(n-pos+1);
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
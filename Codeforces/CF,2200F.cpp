#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=18,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        LL get(int pos) { return num[pos-1]; }

        int size() { return (int)num.size(); }
};

struct node
{
    int cnt;
    LL sum;
    node(int _cnt=0,LL _sum=0):cnt(_cnt),sum(_sum){}
    node operator+(const node& a)const { return {cnt+a.cnt,sum+a.sum}; }
};

struct fucalorse
{
    private:
        int n;
        vector<node>op;
    public:
        fucalorse(int _n):n(_n),op(_n+5,node()){}

        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
            {
                op[i].cnt++;
                op[i].sum+=k;
            }
        }

        node query(int pos)
        {
            node ans=node();
            for(int i=pos;i;i-=i&-i)
                ans=ans+op[i];
            return ans;
        }

        int get(int target_cnt)
        {
            int cnt=0,pos=0;
            for(int k=LEN;k>=0;k--)
            {
                int _pos=pos|(1<<k);
                if(_pos<=n)
                {
                    int _cnt=cnt+op[_pos].cnt;
                    if(_cnt<target_cnt)
                    {
                        pos=_pos;
                        cnt=_cnt;
                    }
                }
            }
            return pos+1;
        }
};

struct qwq
{
    LL x;
    int y;
    bool operator<(const qwq &a)const { return y<a.y; }
    bool operator>(const qwq &a)const { return y>a.y; }
}op[MAX],query[MAX];

int n,m;
LL full_sub[MAX],lack_sub[MAX],pre_full_sub[MAX],pre_lack_sub[MAX];

void solve()
{
    cin>>n>>m;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;
        dis.add(op[i].x);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>query[i].x>>query[i].y;
        dis.add(query[i].x);
    }
    dis.create();

    sort(op+1,op+n+1);
    LL sum=0;
    fucalorse fu(dis.size());
    for(int k=n,l=n;k>=0;k--)
    {
        while(l>=1&&op[l].y>=k)
        {
            sum+=op[l].x;
            fu.update(dis.find(op[l].x),op[l].x);
            l--;
        }

        int total=n-l;
        int full_target_cnt=max(0,total-(k+1)),lack_target_cnt=max(0,total-k);

        auto cal=[&](int target_cnt)->LL
        {
            if(target_cnt==0) return sum;
            else
            {
                int pos=fu.get(target_cnt);
                node now=fu.query(pos-1);
                LL min_sum=now.sum+1LL*dis.get(pos)*(target_cnt-now.cnt);
                return sum-min_sum;
            }
        };

        full_sub[k]=cal(full_target_cnt),lack_sub[k]=cal(lack_target_cnt);
    }

    // for(int k=0;k<=n;k++)
    //     cout<<k<<' '<<full_sub[k]<<endl;
    // cout<<endl;
    // for(int k=0;k<=n;k++)
    //     cout<<k<<' '<<lack_sub[k]<<endl;

    pre_full_sub[0]=pre_lack_sub[0]=-LINF;
    for(int k=0;k<=n;k++)
    {
        if(k)
        {
            pre_full_sub[k]=pre_full_sub[k-1];
            pre_lack_sub[k]=pre_lack_sub[k-1];
        }
        pre_full_sub[k]=max(pre_full_sub[k],full_sub[k]);
        pre_lack_sub[k]=max(pre_lack_sub[k],lack_sub[k]);
    }

    for(int i=1;i<=m;i++)
        cout<<max(pre_full_sub[n],pre_lack_sub[query[i].y]+query[i].x)<<' ';
    cout<<endl;
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
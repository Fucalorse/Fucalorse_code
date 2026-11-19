#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+90,LEN=32,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        else return y<a.y;
    }
    bool operator==(const qwq &a)const { return x==a.x&&y==a.y; }
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

i128 cross(const qwq &a,const qwq &b) { return (i128)a.x*b.y-b.x*a.y; }

i128 cal_cross(const qwq &a,const qwq &b,const qwq &c) { return cross(Vector(a,b),Vector(a,c)); }

bool better(const qwq &a,const qwq &b) { return (i128)a.y*b.x>(i128)a.x*b.y;}

int n,q,B;
LL a[MAX],b[MAX];
int belong[MAX],L[MAX],R[MAX],maxn[MAX];
vector<qwq>hull[MAX];

void rebuild(int id)
{
    int pos=L[id];

    for(int i=L[id]+1;i<=R[id];i++)
    {
        qwq best=op[pos];
        if(better(op[i],best)) pos=i;
    }

    maxn[id]=pos;

    vector<qwq> &fu=hull[id],cur;fu.clear();

    for(int i=L[id];i<=R[id];i++)
        cur.push_back(op[i]);

    sort(cur.begin(),cur.end());

    int len=cur.size();
    for(int i=0;i<len;i++)
    {
        qwq z=cur[i];

        while((int)fu.size()>=2)
        {
            qwq x=fu[(int)fu.size()-2],y=fu.back();
            if(cal_cross(x,y,z)>=0) fu.pop_back();
            else break;
        }

        fu.push_back(cur[i]);
    }
}

void initial()
{
    B=sqrt(n);
    int tot=(n+B-1)/B;

    for(int i=0;i<tot;i++)
    {
        L[i]=i*B+1,R[i]=min(n,(i+1)*B);

        for(int j=L[i];j<=R[i];j++)
            belong[j]=i;

        rebuild(i);
    }
}

qwq cal(qwq best,int id)
{
    vector<qwq>&cur=hull[id];
    int len=cur.size(),l=0,r=len-1;

    while(l<r)
    {
        int mid=(l+r)>>1;
        qwq a=Vector(cur[mid],best),b=Vector(cur[mid+1],best);

        if(cross(a,b)>=0) l=mid+1;
        else r=mid;
    }

    return cur[l];
}

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i].y=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        op[i].x=b[i];
    }

    initial();

    while(q--)
    {
        int opt;
        cin>>opt;

        if(opt==1)
        {
            int id;
            LL val;
            cin>>id>>val;

            op[id].y=val;
            rebuild(belong[id]);
        }
        else if(opt==2)
        {
            int id;
            LL val;
            cin>>id>>val;

            op[id].x=val;
            rebuild(belong[id]);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            int pos=l;
            bool first=true;
            qwq ans={0,0};

            auto update=[&](qwq nxt)
            {
                qwq now={nxt.x+op[pos].x,nxt.y+op[pos].y};
                if(first||better(now,ans))
                {
                    ans=now;
                    first=false;
                }
            };

            if(belong[l]==belong[r])
            {
                for(int i=l;i<=r;i++)
                    if(better(op[i],op[pos])) pos=i;
                    
                for(int i=l;i<=r;i++)
                {
                    if(i==pos) continue;
                    update(op[i]);
                }
            }
            else
            {
                for(int i=l;i<=R[belong[l]];i++)
                    if(better(op[i],op[pos])) pos=i;

                for(int i=L[belong[r]];i<=r;i++)
                    if(better(op[i],op[pos])) pos=i;

                for(int id=belong[l]+1;id<=belong[r]-1;id++)
                    if(better(op[maxn[id]],op[pos])) pos=maxn[id];
                    
                for(int i=l;i<=R[belong[l]];i++)
                {
                    if(i==pos) continue;
                    update(op[i]);
                }

                for(int i=L[belong[r]];i<=r;i++)
                {
                    if(i==pos) continue;
                    update(op[i]);
                }

                for(int id=belong[l]+1;id<=belong[r]-1;id++)
                {
                    if(belong[pos]==id)
                    {
                        for(int i=L[id];i<=R[id];i++)
                        {
                            if(pos==i) continue;
                            update(op[i]);
                        }
                    }
                    else
                    {
                        qwq best={-op[pos].x,-op[pos].y};
                        qwq now=cal(best,id);
                        update(now);
                    }
                }
            }

            auto [x,y]=ans;
            LL g=__gcd(x,y);
            cout<<y/g<<' '<<x/g<<endl;
        }
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
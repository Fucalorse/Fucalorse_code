#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    int minn,len;
    bool operator<(const qwq &a)const
    {
        if(len!=a.len) return len<a.len;
        else return minn<a.minn;
    }
};

int n;
int a[MAX],b[MAX];

qwq get(int num)
{
    bool first=true;
    int minn=INF,len=0;
    for(int i=num;i!=num||first;i=a[i])
    {
        first=false;
        minn=min(minn,i);
        ++len;
    }
    return  qwq{minn,len};
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    for(int i=1;i<=n;i++)
        cin>>b[i];

    set<int>rest,filled;
    for(int i=1;i<=n;i++)
    {
        rest.insert(i);
        if(b[i]!=-1) filled.insert(b[i]);
    }

    auto check_first=[&]()
    {
        for(int i=1;i<=n;i++)
            if(b[i]!=-1&&rest.count(b[i]))
            {
                qwq pa=get(a[i]),pb=get(b[i]);
                if(pa.len!=pb.len) return false;

                bool first=true;
                for(int j=i,num=b[i];j!=i||first;j=a[j],num=a[num])
                {
                    if(b[j]!=-1&&num!=b[j]) return false;
                    if(b[j]==-1&&filled.count(num)) return false;

                    first=false;
                    b[j]=num;
                    rest.erase(num);
                }
            }

        return true;
    };
    
    bool ok=check_first();

    if(!ok)
    {
        cout<<"NO"<<endl;
        return;
    }

    set<qwq>circle;

    for(int num=1;num<=n;num++)
        if(rest.count(num))
        {
            qwq now=get(num);
            circle.insert(now);

            bool first=true;
            for(int i=num;i!=num||first;i=a[i])
            {
                first=false;
                rest.erase(i);
            }
        }

    for(int i=1;i<=n;i++)
        if(b[i]==-1)
        {
            qwq pb=get(i);
            auto it=circle.lower_bound({-INF,pb.len});

            if(it==circle.end())
            {
                cout<<"NO"<<endl;
                return;
            }

            bool first=true;
            for(int pos=i,num=it->minn;pos!=i||first;pos=a[pos],num=a[num])
            {
                first=false;
                b[pos]=num;
            }

            circle.erase(it);
        }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<b[i]<<' ';
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
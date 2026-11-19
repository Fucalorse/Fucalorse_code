#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;
const LL P=211;
const vector<int>h={0,7,6,5,4,3,2};

struct qwq
{
    int suma,sumb,rest,p,col,cnt;
};

struct ovo
{
    LL val;
    int cnt,score;
};

int T,n,a,b,p;
char ans[MAX];
unordered_map<LL,ovo>pre;

LL cal(int suma,int sumb,int rest,int p,int col)
{
    LL a=suma*P*P*P*P,b=sumb*P*P*P,c=rest*P*P,d=p*P,e=col;
    return a+b+c+d+e;
}

void bfs()
{
    queue<qwq>q;
    q.push({0,0,21,0,0,0});
    while(q.size())
    {
        auto [suma,sumb,rest,p,col,cnt]=q.front();q.pop();
        if(rest<=0||cnt+1>100) continue;
        //win
        if(col==1)
        {
            for(int i=2;i<=7;i++)
            {
                int na=suma+(p==0)*i,nb=sumb+(p==1)*i;
                LL va=cal(suma,sumb,rest,p,col),vb=cal(na,nb,rest,p,0);
                if(!pre.count(vb)||pre[vb].cnt>cnt+1)
                {
                    pre[vb]={va,cnt+1,i};
                    q.push({na,nb,rest,p,0,cnt+1});
                }
            }
        }
        else
        {
            if(rest>6)
            {
                int na=suma+(p==0),nb=sumb+(p==1);
                LL va=cal(suma,sumb,rest,p,col),vb=cal(na,nb,rest-1,p,1);
                if(!pre.count(vb)||pre[vb].cnt>cnt+1)
                {
                    pre[vb]={va,cnt+1,1};
                    q.push({na,nb,rest-1,p,1,cnt+1});
                }
            }
            else
            {
                int na=suma+(p==0)*h[rest],nb=sumb+(p==1)*h[rest];
                LL va=cal(suma,sumb,rest,p,col),vb=cal(na,nb,rest-1,p,0);
                if(!pre.count(vb)||pre[vb].cnt>cnt+1)
                {
                    pre[vb]={va,cnt+1,h[rest]};
                    q.push({na,nb,rest-1,p,0,cnt+1});
                }
            }
        }
        //fail
        LL va=cal(suma,sumb,rest,p,col),vb=cal(suma,sumb,rest,p^1,0);
        if(!pre.count(vb)||pre[vb].cnt>cnt+1)
        {
            pre[vb]={va,cnt+1,-1};
            q.push({suma,sumb,rest,p^1,0,cnt+1});
        }
    }
    LL st=cal(0,0,21,0,0);
    pre[st]={0,0,0};
}

void solve()
{
    cin>>a>>b>>n>>p;
    LL v1=cal(a,b,n,p,0),v2=cal(a,b,n,p,1),val=-1;
    if(pre.count(v1)) val=v1;
    else if(pre.count(v2)) val=v2;

    if(val==-1) cout<<"NA"<<endl;
    else
    {
        int tot=pre[val].cnt;
        for(int i=tot;i>=1;i--)
        {
            if(pre[val].score<0) ans[i]='/';
            else ans[i]=pre[val].score+'0';
            val=pre[val].val;
        }
        for(int i=1;i<=tot;i++)
            cout<<ans[i];
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    bfs();
    cin>>T;
    while(T--) solve();
    return 0;
}
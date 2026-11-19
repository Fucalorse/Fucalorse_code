#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;
const LL P=211;
const vector<int>h={0,7,6,5,4,3,2,1};

struct qwq
{
    int suma,sumb,rest,p;
};

struct ovo
{
    LL val;
    int cnt,score;
};

int T,a,b,n,p;
char ans[MAX];
unordered_map<LL,ovo>pre;

LL cal(int suma,int sumb,int rest,int p,int col)
{
    LL a=1LL*suma*P*P*P*P,b=1LL*sumb*P*P*P,c=1LL*rest*P*P,d=p*P,e=col;
    return a+b+c+d+e;
}

qwq get(LL x)
{
    int suma=x/(P*P*P*P),sumb=x/(P*P*P)%P,rest=x/(P*P)%P,p=x/P%P;
    return {suma,sumb,rest,p};
}

void dfs(int suma,int sumb,int rest,int p,int col,int cnt)
{
    if(rest<=0||cnt+1>100) return;
    //win
    if(col==1)
    {
        for(int now=2;now<=7;now++)
        {
            int na=suma+(p==0)*now,nb=sumb+(p==1)*now;
            LL va=cal(suma,sumb,rest,p,col),vb=cal(na,nb,rest,p,0);
            if(!pre.count(vb)||pre[vb].cnt>cnt+1)
            {
                pre[vb]={va,cnt+1,now};
                dfs(na,nb,rest,p,0,cnt+1);
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
                dfs(na,nb,rest-1,p,1,cnt+1);
            }            
        }
        else
        {
            int na=suma+(p==0)*h[rest],nb=sumb+(p==1)*h[rest];
            LL va=cal(suma,sumb,rest,p,col),vb=cal(na,nb,rest-1,p,0);
            if(!pre.count(vb)||pre[vb].cnt>cnt+1)
            {
                pre[vb]={va,cnt+1,h[rest]};
                dfs(na,nb,rest-1,p,0,cnt+1);
            }            
        }
    }
    //lose
    LL va=cal(suma,sumb,rest,p,col),vb=cal(suma,sumb,rest,p^1,0);
    if(!pre.count(vb)||pre[vb].cnt>cnt+1)
    {
        pre[vb]={va,cnt+1,-1};
        dfs(suma,sumb,rest,p^1,0,cnt+1);
    }
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
    dfs(0,0,21,0,0,0);
    LL st=cal(0,0,21,0,0);
    pre[st]={0,0,0};
    cin>>T;
    while(T--) solve();
    return 0;
}
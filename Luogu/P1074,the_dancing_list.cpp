#include <bits/stdc++.h>
using namespace std;

const int MAX=324,LEN=3e5;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct qwq
{
    int l,r,u,d;
}op[LEN];
int f[12][12],cnt,maxn=-1;
bool vis[12][12];
int row[LEN],col[LEN],num[LEN],h[LEN];
vector<int>ans;

struct fucalorse
{
    void create()
    {
        for(int i=0;i<=MAX;i++)
        {
            op[i].l=i-1,op[i].r=i+1;
            op[i].u=op[i].d=i;
        }
        op[0].l=MAX,op[MAX].r=0;
        memset(h,-1,sizeof h);
        cnt=MAX+1;
    }
    void add(int r,int c)
    {
        num[c]++;
        row[cnt]=r;
        col[cnt]=c;
        op[cnt].u=c;
        op[cnt].d=op[c].d;
        op[op[c].d].u=cnt;
        op[c].d=cnt;
        if(h[r]<0) h[r]=op[cnt].l=op[cnt].r=cnt;
        else
        {
            op[cnt].r=h[r];
            op[cnt].l=op[h[r]].l;
            op[op[h[r]].l].r=cnt;
            op[h[r]].l=cnt;
        }
        cnt++;
    }
    void fade(int c)
    {
        op[op[c].l].r=op[c].r;
        op[op[c].r].l=op[c].l;
        for(int i=op[c].d;i!=c;i=op[i].d)
            for(int j=op[i].r;j!=i;j=op[j].r)
            {
                op[op[j].u].d=op[j].d;
                op[op[j].d].u=op[j].u;
                num[col[j]]--;
            }
    }
    void reborn(int c)
    {
        for(int i=op[c].u;i!=c;i=op[i].u)
            for(int j=op[i].l;j!=i;j=op[j].l)
            {
                op[op[j].u].d=j;
                op[op[j].d].u=j;
                num[col[j]]++;
            }
        op[op[c].l].r=c;
        op[op[c].r].l=c;
    }
    bool dis(const int &i,const int &j)
    {
        return i>=0&&i<=8&&j>=0&&j<=8&&!vis[i][j];
    }
    int dfs(int i,int j,int p,int k)
    {
        if(k==10) return f[i][j]*k;
        vis[i][j]=true;
        int val=f[i][j]*k;
        int ni=i+dx[p],nj=j+dy[p];
        if(!dis(ni,nj))
        {
            int q=(p+1)&3;
            ni=i+dx[q],nj=j+dy[q];
            if(!p) return val+dfs(ni,nj,q,k+1);
            else return val+dfs(ni,nj,q,k);
        }
        else return val+dfs(ni,nj,p,k);
    }
    void dance()
    {
        if(op[0].r==0)
        {
            for(auto now:ans)
            {
                int x=now/81,y=now/9%9,val=now%9+1;
                f[x][y]=val;
            }
            memset(vis,false,sizeof vis);
            maxn=max(maxn,dfs(0,0,1,6));
            return;
        }
        int c=op[0].r;
        for(int i=op[0].r;i;i=op[i].r)
            if(num[i]<num[c]) c=i;
        fade(c);
        for(int i=op[c].d;i!=c;i=op[i].d)
        {
            for(int j=op[i].r;j!=i;j=op[j].r) fade(col[j]);
            ans.push_back(row[i]);
            dance();
            ans.pop_back();
            for(int j=op[i].l;j!=i;j=op[j].l) reborn(col[j]);
        }
        reborn(c);
    }
}fu;

int main()
{
    fu.create();
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            f[i][j]=read();
            for(int k=1;k<=9;k++)
            {
                if(f[i][j]&&f[i][j]!=k) continue;
                int p=i*81+j*9+k-1;
                fu.add(p,i*9+j+1);
                fu.add(p,81+i*9+k);
                fu.add(p,81*2+j*9+k);
                fu.add(p,81*3+(i/3*3+j/3)*9+k);
            }
        }
    fu.dance();
    printf("%d\n",maxn);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5;

bool cmp(const vector<int>&a,const vector<int>&b)
{
    for(size_t i=0;i<a.size()&&i<b.size();i++)
        if(a[i]!=b[i]) return a[i]<b[i];
    return a.size()<b.size();
}

struct qwq
{
    int l,r,u,d;
}op[MAX];
int n,cnt;
int row[MAX],col[MAX],h[MAX],num[MAX];
vector<vector<int>>ans;
vector<int>f;

struct fucalorse
{
    void create(int n)
    {
        int size=n*6-2;
        for(int i=0;i<=size;i++)
        {
            op[i].l=i-1,op[i].r=i+1;
            op[i].u=op[i].d=i;
        }
        op[0].l=size,op[size].r=0;
        memset(h,-1,sizeof h);
        cnt=size+1;
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
    void dance()
    {
        if(op[0].r>n)
        {
            vector<int>aft;
            aft.resize(n);
            for(auto now:f)
            {
                int x=now/n+1,y=now%n+1;
                aft[x-1]=y;
            }
            ans.push_back(aft);
            return;
        }
        int c=op[0].r;
        for(int i=op[0].r;i<=n;i=op[i].r)
            if(num[i]<num[c]) c=i;
        fade(c);
        for(int i=op[c].d;i!=c;i=op[i].d)
        {
            for(int j=op[i].r;j!=i;j=op[j].r) fade(col[j]);
            f.push_back(row[i]);
            dance();
            f.pop_back();
            for(int j=op[i].l;j!=i;j=op[j].l) reborn(col[j]);
        }
        reborn(c);
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    fu.create(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int p=i*n+j;
            fu.add(p,i+1);
            fu.add(p,n+j+1);
            fu.add(p,n*2+i-j+n);
            fu.add(p,n*4+i+j);
        }
    fu.dance();
    sort(ans.begin(),ans.end(),cmp);
    for(size_t i=0;i<3;i++)
    {
        for(auto now:ans[i])
            cout<<now<<' ';
        cout<<'\n';
    }
    cout<<ans.size()<<'\n';
    return 0;
}
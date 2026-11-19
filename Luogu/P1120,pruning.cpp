#include <bits/stdc++.h>
using namespace std;

const int MAX=80;

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

int n,each,cnt;
int num[MAX],nxt[MAX];
bool vis[MAX]={false};

int find(const int &pos,const int &x)
{
    int l=pos+1,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(num[mid]>x) l=mid+1;
        else r=mid-1;
    }
    return l;
}

void dfs(int pos,int rest,int id)
{
    if(rest<0) return;
    if(!rest)
    {
        if(id==cnt)
        {
            printf("%d\n",each);
            exit(0);
        }
        int aft;
        for(aft=0;aft<n;aft++)
            if(!vis[aft]) break;
        vis[aft]=true;
        dfs(aft,each-num[aft],id+1);
        vis[aft]=false;
        return;
    }
    int st=find(pos,rest);
    for(int i=st;i<n;i++)
        if(!vis[i])
        {
            vis[i]=true;
            dfs(i,rest-num[i],id);
            vis[i]=false;
            if(rest==each||rest==num[i]) return;
            i=nxt[i]-1;
        }
}

int main()
{
    n=read();
    int total=0,maxn=0;
    for(int i=0;i<n;i++)
    {
        num[i]=read();
        total+=num[i];
        if(num[i]>maxn) maxn=num[i];
    }
    sort(num,num+n,greater<int>());
    int pre=0;
    for(int i=0;i<n;i++)
    {
        while(pre<i&&num[i]!=num[pre]) nxt[pre]=i,pre++;
    }
    while(pre<n) nxt[pre]=n,pre++;
    for(each=maxn;each<=total/2;each++)
    {
        if(total%each!=0) continue;
        cnt=total/each;
        dfs(-1,each,1);
    }
    printf("%d\n",total);
    return 0;
}
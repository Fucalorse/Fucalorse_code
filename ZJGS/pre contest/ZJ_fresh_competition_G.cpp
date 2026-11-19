#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=30;

int n,k,st,ed;
LL s,num[MAX],op[MAX],ans=0;
unordered_map<LL,LL>f[MAX];

void dfs(int pos,int cnt,LL sum)
{
    if(sum>s) return;
    if(pos>ed)
    {
        for(int i=cnt;i<=k;i++)
            f[i][sum]++;
        return;
    }
    dfs(pos+1,cnt,sum);
    dfs(pos+1,cnt,sum+num[pos]);
    if(num[pos]<=18&&cnt<k) dfs(pos+1,cnt+1,sum+op[num[pos]]);
}

void peach(int pos,int cnt,LL sum)
{
    if(sum>s) return;
    if(pos>ed)
    {
        ans+=f[k-cnt][s-sum];
        return;
    }
    peach(pos+1,cnt,sum);
    peach(pos+1,cnt,sum+num[pos]);
    if(num[pos]<=18&&cnt<k) peach(pos+1,cnt+1,sum+op[num[pos]]);
}

int main()
{
    cin>>n>>k>>s;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    op[1]=1;
    for(int i=2;i<=18;i++)
        op[i]=op[i-1]*(LL)i;
    st=1,ed=n/2;
    dfs(st,0,0);
    st=n/2+1,ed=n;
    peach(st,0,0);
    cout<<ans<<'\n';
    return 0;
}
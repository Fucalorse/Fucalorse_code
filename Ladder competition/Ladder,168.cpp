#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int n;
LL l,r;
set<LL>ans;

void dfs(int pos,LL num)
{
    if(pos>n) return;
    LL now=num;
    for(int i=1;i<=n-pos;i++)
        now*=10;
    if(now>r||num%pos!=0) return;
    if(pos==n)
    {
        if(num>=l&&num<=r) ans.insert(num);
        return;
    }
    for(int i=0;i<=9;i++)
        dfs(pos+1,num*10+i);
}

int main()
{
    cin>>n>>l>>r;
    for(int i=1;i<=9;i++)
        dfs(1,i);
    if(ans.size())
    {
        for(auto &i:ans)
            cout<<i<<endl;
    }
    else cout<<"No Solution"<<endl;
    return 0;
}
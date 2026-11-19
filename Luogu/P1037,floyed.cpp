#include <bits/stdc++.h>
using namespace std;

const int MAX=12,LEN=1e5+90;

string s;
int k;
int ans[LEN];
bitset<MAX>f[MAX];

int cal(const int &x,int len)
{
    for(int i=0;i<len;i++)
        ans[i]*=x;
    for(int i=0;i<len;i++)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
        if(ans[len]) len++;
    }
    return len;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>s>>k;
    for(int i=1;i<=k;i++)
    {
        int u,v;
        cin>>u>>v;
        f[u][v]=1;
    }
    for(int i=0;i<=9;i++)
        f[i][i]=1;
    for(int k=0;k<=9;k++)
        for(int i=0;i<=9;i++)
            if(f[i][k]) f[i]|=f[k];
    ans[0]=1;
    int len=1;
    for(auto &i:s)
    {
        int now=f[i-'0'].count();
        len=cal(now,len);
    }
    for(int i=len-1;i>=0;i--)
        cout<<ans[i];
    cout<<'\n';
    return 0;
}
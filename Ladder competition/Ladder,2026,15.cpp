#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100,mod=998244353;

int n;
LL c[MAX],f[MAX];
stack<int>st;
vector<int>p[MAX];
set<LL>ans;

LL find(int pos)
{
    f[pos]=1;
    for(auto &to:p[pos])
        f[pos]+=find(to);
    return f[pos];
}

LL sum(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

LL cal()
{
    stack<int>op=st;
    int len=op.size();
    LL now=1;
    for(int i=1;i<=len;i++)
    {
        int pos=op.top();op.pop();
        now*=sum(c[i],f[pos]);
        now%=mod;
    }
    return now;
}

void dfs(int pos)
{
    // cout<<pos<<endl;
    ans.insert(cal());
    for(auto &to:p[pos])
    {
        st.push(to);
        dfs(to);
        st.pop();
        if(pos>1) dfs(to);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        p[fa].push_back(i);
    }
    for(int i=1;i<=n;i++)
        cin>>c[i];
    find(1);
    st.push(1);
    dfs(1);
    LL now=0;
    for(auto &i:ans) now=(now+i)%mod;
    cout<<now<<endl;
    return 0;
}
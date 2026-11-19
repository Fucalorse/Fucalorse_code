#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=3e5+10;

int n;
int minp[MAX],mu[MAX];
vector<int>op,num[MAX];

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

void oula()
{
    mu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i,mu[i]=-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if((LL)i*j>n) break;
            minp[i*j]=j;
            if(i%j==0)
            {
                mu[i*j]=0;
                break;
            }
            else mu[i*j]=-mu[i];
        }
    }
    for(int i=2;i<=n;i++)
    {
        int x=i;
        while(x>1)
        {
            int p=minp[x];
            while(x%p==0) x/=p;
            num[i].push_back(p);
        }
    }
}

vector<pair<int,int>> cal(const int &m)
{
    vector<pair<int,int>>ans;
    ans.emplace_back(1,1);
    for(auto &p:num[m])
    {
        size_t size=ans.size();
        for(size_t j=0;j<size;j++)
        {
            auto &i=ans[j];
            int d=i.first*p,val=-i.second;
            ans.emplace_back(d,val);
        }
    }
    return ans;
}

int main()
{
    cin>>n;
    oula();
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        int ed=n/i;
        for(int j=1;j<=ed;j++)
        {
            if(gcd(i,j)!=1) continue;
            int N=n/(i*j),m=i*j;
            vector<pair<int,int>>now=cal(m);
            for(auto &cur:now)
                ans+=(LL)cur.second*(N/cur.first);
        }
    }
    cout<<ans;
    return 0;
}
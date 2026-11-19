#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100,LEN=8;

int a[MAX],b[MAX];
double maxn=0;
bool vis[MAX];
vector<int>op;

double win(int x,int y)
{
    if(x>y) return (double)b[op[x]]/(b[op[x]]+a[op[y]]);
    else return (double)a[op[x]]/(a[op[x]]+b[op[y]]);
}

double cal()
{
    vector<double>dp(9,1.00);
    for(int k=2;k<=8;k<<=1)
    {
        vector<double>ndp(9,0.00);
        for(int st=1;st<=8;st+=k)
        {
            int l=st,r=st+k-1;
            int mid=(l+r)>>1;
            for(int i=l;i<=r;i++)
            {
                if(i<=mid)
                {
                    for(int j=mid+1;j<=r;j++)
                        ndp[i]+=dp[i]*dp[j]*win(i,j);
                }
                else
                {
                    for(int j=l;j<=mid;j++)
                        ndp[i]+=dp[i]*dp[j]*win(i,j);
                }
            }
        }
        dp=ndp;
    }

    int pos;
    for(int i=1;i<=8;i++)
        if(op[i]==1)
        {
            pos=i;
            break;
        }
    return dp[pos];
}

void dfs(int cnt)
{
    if(cnt==LEN)
    {
        maxn=max(maxn,cal());
        return;
    }
    for(int i=1;i<=LEN;i++)
        if(!vis[i])
        {
            op.push_back(i);
            vis[i]=true;
            dfs(cnt+1);
            vis[i]=false;
            op.pop_back();
        }
}

void solve()
{
    for(int i=1;i<=LEN;i++)
        cin>>a[i]>>b[i];
    
    op.push_back(-1);
    dfs(0);

    cout<<fixed<<setprecision(18);
    cout<<maxn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}

// g++ M.cpp -O2 -o out.exe && out.exe < in.txt
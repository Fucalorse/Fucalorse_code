#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1090,inf=2e9;

struct point
{
    int x,y;
}pos[MAX];

int n,m,q;
bool op[LEN][LEN],seat[LEN][LEN];
int v[LEN][LEN],opt[MAX];

vector<int> cal_l(int i)
{
    vector<int>ans(n+3,0);
    int pre=0;
    for(int j=1;j<=n;j++)
    {
        if(seat[i][j]) pre=j;
        else ans[j]=pre;
    }
    return ans;
}

vector<int> cal_r(int i)
{
    vector<int>ans(n+3,0);
    int pre=0;
    for(int j=n;j>=1;j--)
    {
        if(seat[i][j]) pre=j;
        else ans[j]=pre;
    }
    return ans;
}

int cal_best(int i)
{
    int best=0,maxn=v[i][1];
    bool f=false;
    for(int j=1;j<=n;j++)
    {
        if(seat[i][j]) continue;
        if(!best) best=j,maxn=v[i][j],f=!op[i][j];
        else if(v[i][j]>maxn)
        {
            maxn=v[i][j];
            best=j;
            f=!op[i][j];
        }
        else if(v[i][j]==maxn&&!op[i][j]&&!f) best=j,f=true;
    }
    return best;
}

void solve()
{
    cin>>n>>m>>q;m<<=1;
    for(int i=1;i<=m;i++)
    {
        opt[i]=1;
        for(int j=1;j<=n;j++)
            v[i][j]=n;
    }
    int total=0;
    while(q--)
    {
        int p,x;
        cin>>p>>x;
        if(p==1)
        {
            if(total==m*n)
            {
                cout<<-1<<' '<<-1<<endl;
                continue;
            }

            int best=0,maxn=v[1][opt[1]];
            bool f=false;
            for(int i=1;i<=m;i++)
            {
                if(!best) best=i,maxn=v[i][opt[i]],f=!op[i][opt[i]];
                else if(v[i][opt[i]]>maxn)
                {
                    maxn=v[i][opt[i]];
                    best=i;
                    f=!op[i][opt[i]];
                }
                else if(v[i][opt[i]]==maxn&&!op[i][opt[i]]&&!f) best=i,f=true;
                // if(x==2) cout<<best<<' '<<opt[best]<<' '<<maxn<<endl;
            }
            
            pos[x]={best,opt[best]};
            seat[best][opt[best]]=true;
            cout<<best<<' '<<opt[best]<<endl;

            int opposite=best&1?best+1:best-1;
            op[opposite][opt[best]]=true;
            vector<int>pre=cal_l(best),suf=cal_r(best);
            for(int i=1;i<=n;i++)
            {
                if(seat[best][i]) continue;
                int now=inf;
                if(pre[i]) now=min(now,i-pre[i]);
                if(suf[i]) now=min(now,suf[i]-i);
                v[best][i]=now;
            }
            opt[best]=cal_best(best);
            opt[opposite]=cal_best(opposite);
            // cout<<opt[best]<<endl;

            ++total;
        }
        else
        {
            auto [x1,y1]=pos[x];
            int opposite=x1&1?x1+1:x1-1;
            op[opposite][y1]=false,seat[x1][y1]=false;

            vector<int>pre=cal_l(x1),suf=cal_r(x1);
            for(int i=1;i<=n;i++)
            {
                if(seat[x1][i]) continue;
                int now=n;
                if(pre[i]) now=min(now,i-pre[i]);
                if(suf[i]) now=min(now,suf[i]-i);
                v[x1][i]=now;
            }
            opt[x1]=cal_best(x1);
            opt[opposite]=cal_best(opposite);

            --total;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9,LEN=12;

int T,n;
int pw3[MAX];
string s[25];

void create()
{
    pw3[0]=1;
    for(int i=1;i<=LEN;i++)
        pw3[i]=pw3[i-1]*3;
}

void solve()
{
    cin>>n;
    int k=0;
    while((1<<k)<=n) k++;

    for(int i=0;i<k;i++)
        cin>>s[i];

    int S=1<<k;
    vector<int>exist(S,0);
    for(int j=0;j<n;j++)
    {
        int mask=0;
        for(int i=0;i<k;i++)
            if(s[i][j]=='1') mask|=1<<i;

        if(!mask||exist[mask])
        {
            cout<<0<<endl;
            return;
        }

        exist[mask]=1;
    }

    vector<int>sup=exist;
    for(int i=0;i<k;i++)
        for(int j=0;j<S;j++)
            sup[j]|=sup[j|(1<<i)];

    LL ans=0;
    int len=pw3[k];
    vector<LL>dp(len,0);
    dp[0]=1;

    for(int state=0;state<len;state++)
    {
        if(dp[state]==0) continue;

        int used=0,one=0,cnt=0;
        for(int i=0,v=state;i<k;i++)
        {
            int now=v%3;v/=3;

            if(now) used|=1<<i,cnt++;
            if(now==2) one|=1<<i;
        }

        if(cnt==k)
        {
            ans+=dp[state];
            continue;
        }

        int bit=k-1-cnt;
        if((n>>bit)&1)
        {
            for(int i=0;i<k;i++)
            {
                if((used>>i)&1) continue;

                // assert(state+pw3[i]*2<len);
                dp[state+pw3[i]*2]+=dp[state];
            }
        }
        else
        {
            for(int i=0;i<k;i++)
            {
                if((used>>i)&1) continue;

                // assert(state+pw3[i]<len);
                int now=one|(1<<i);
                if(!sup[now]) dp[state+pw3[i]]+=dp[state];
            }
        }
    }
    
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}
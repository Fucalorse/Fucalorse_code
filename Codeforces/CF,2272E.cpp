#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
int pre[MAX];
string s,t;

void cal(const string &s,const string &t)
{
    int lens=(int)s.size()-1,lent=(int)t.size()-1,pos=-1,cntW=0;
    vector<LL>f(lent+2,0);
    for(int i=1;i<=lens;i++)
    {
        if(s[i]=='W') pre[i]=i;
        else pre[i]=pre[i-1];
    }
    for(int l=1,r=1;l<=lent;l=r)
    {
        while(r<=lent&&t[l]==t[r]) ++r;
        if(t[l]=='W') pos=r-1,cntW+=r-l;
        else
        {
            if(pos==-1||r>lent) continue;
            ++f[1];
            --f[r-l+1];
        }
    }

    for(int i=1;i<=lent;i++)
        f[i]+=f[i-1];
    for(int i=1;i<=lent;i++)
        f[i]+=f[i-1];

    for(int i=1;i<=lens;i++)
    {
        if(s[i]=='W') continue;

        if(pre[i]==0)
        {
            if(pos==-1) cout<<1<<' ';
            else
            {
                int pre_cnt=i-1;
                // cout<<f[pre_cnt]<<' '<<cntW<<' '<<max(pre_cnt,lent-pos)<<endl;
                cout<<1+f[min(pre_cnt,lent)]+cntW+pre_cnt<<' ';
            }
        }
        else
        {
            if(pos==-1) cout<<lent+1<<' ';
            else cout<<pos+max(lent-pos,i-pre[i]-1)+1<<' ';
        }
    }
    cout<<endl;
}

void solve()
{
    cin>>n>>m>>s>>t;s=' '+s,t=' '+t;

    cal(s,t);
    cal(t,s);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
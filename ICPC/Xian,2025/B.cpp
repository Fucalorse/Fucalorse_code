#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX],pre[MAX],suf[MAX];
int f[MAX][3];
string s;

int get_id(char c)
{
    if(c=='C') return 0;
    else if(c=='W') return 1;
    return 2;
}

char change(int id)
{
    if(id==0) return 'C';
    else if(id==1) return 'W';
    return 'P';
}

string construct(int L,int R)
{
    string ans;
    array<int,3>cnt,D;
    for(int col=0;col<=2;col++)
        cnt[col]=f[R][col]-f[L-1][col];

    for(int i=1;i<L;i++)
        ans.push_back(s[i]);
    
    int left=L>1?get_id(s[L-1]):-1,right=R<n?get_id(s[R+1]):-1,len=R-L+1;
    for(int i=L;i<=R;i++)
    {
        int pos=-1;
        for(int col=0;col<=2;col++)
        {
            int side=0;
            if(i>1&&col==left) ++side;
            if(R<n&&col==right) ++side;
            D[col]=2*cnt[col]+side-len;

            if(cnt[col]&&col!=left&&D[col]==1) pos=col;
        }

        if(pos==-1)
        {
            for(int col=0;col<=2;col++)
                if(cnt[col]&&col!=left)
                {
                    pos=col;
                    break;
                }
        }

        ans.push_back(change(pos));
        --cnt[pos];
        left=pos;
        --len;
    }

    for(int i=R+1;i<=n;i++)
        ans.push_back(s[i]);

    return ans;
}

bool check(const int &len,pair<int,int>& interval)
{
    for(int l=1,r=len;l<=n&&r<=n;l++,r++)
    {
        bool ok=true;

        for(int col=0;col<=2;col++)
        {
            int cnt=f[r][col]-f[l-1][col],side=0;
            if(l>1&&a[l-1]==col) ++side;
            if(r<n&&a[r+1]==col) ++side;

            if(2*cnt+side-len>1)
            {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            int cntL=pre[l-1],cntR=suf[r+1];
            if(!cntL&&!cntR)
            {
                interval={l,r};
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    cin>>n>>s;
    s=' '+s;
    s=s+' ';
    
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=2;j++)
            f[i][j]=f[i-1][j];

        if(s[i]=='C')
        {
            f[i][0]++;
            a[i]=0;
        }
        else if(s[i]=='W')
        {
            f[i][1]++;
            a[i]=1;
        }
        else
        {
            f[i][2]++;
            a[i]=2;
        }
    }

    pre[0]=pre[n+1]=suf[0]=suf[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(s[i]==s[i-1]) pre[i]++;
    }

    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1];
        if(s[i]==s[i+1]) suf[i]++;
    }

    int l=1,r=n;
    pair<int,int>interval;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid,interval)) r=mid-1;
        else l=mid+1;
    }

    if(l==n+1) cout<<"Impossible"<<endl;
    else if(r==0) cout<<"Beautiful"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        cout<<interval.first<<' '<<interval.second<<endl;
        cout<<construct(interval.first,interval.second)<<endl;
    }
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
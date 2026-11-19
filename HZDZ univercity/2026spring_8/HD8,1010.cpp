#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=998244353,G=3,LEN=2e5;

LL cal(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;

        p>>=1;
    }

    return ans;
}

void ntt(vector<LL>& a,bool insert)
{
    int n=a.size();

    for(int i=1,j=0;i<n;i++)
    {
        int bit=n>>1;
        while(j&bit)
        {
            j^=bit;
            bit>>=1;
        }

        j^=bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1)
    {
        LL wlen=cal(G,(MOD-1)/len);
        if(insert) wlen=cal(wlen,MOD-2);

        for(int i=0;i<n;i+=len)
        {
            LL w=1;

            for(int j=0;j<len/2;j++)
            {
                LL u=a[i+j],v=a[i+j+len/2]*w%MOD;

                a[i+j]=(u+v)%MOD;
                a[i+j+len/2]=(u-v+MOD)%MOD;

                w=w*wlen%MOD;
            }
        }
    }

    if(insert)
    {
        LL inv_n=cal(n,MOD-2);
        for(auto &cur:a)
            cur=cur*inv_n%MOD;
    }
}

vector<LL> multiply(const vector<LL>& a,const vector<LL>& b)
{
    vector<LL>fa(a.begin(),a.end()),fb(b.begin(),b.end());

    int n=1,len=a.size()+b.size()-1;
    while(n<len) n<<=1;

    fa.resize(n),fb.resize(n);

    ntt(fa,false);
    ntt(fb,false);

    for(int i=0;i<n;i++)
        fa[i]=fa[i]*fb[i]%MOD;

    ntt(fa,true);
    fa.resize(len);

    return fa;
}

int T,n,B;
int a[MAX],lg[MAX];

void create()
{
    for(int i=2;i<=LEN;i++)
        lg[i]=lg[i>>1]+1;
}

void dfs(int l,int r,vector<LL>&ans)
{
    if(l>=r) return;

    if(r-l+1<=B)
    {
        for(int i=l;i<=r;i++)
            for(int j=i+1;j<=r;j++)
                if(a[i]>=a[j]) ++ans[a[i]-a[j]];

        return;
    }

    int mid=(l+r)>>1;
    dfs(l,mid,ans);
    dfs(mid+1,r,ans);

    vector<LL>num1(n,0),num2(n,0);
    for(int i=l;i<=mid;i++)
        num1[a[i]-1]++;
    for(int i=mid+1;i<=r;i++)
        num2[n-a[i]]++;

    vector<LL>now=multiply(num1,num2);
    for(int i=0;i<n;i++)
    {
        int pos=i+n-1;
        // printf("%d %d\n",pos,(int)now.size());
        assert(pos<(int)now.size());
        ans[i]+=now[pos];
    }
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    B=8000;

    vector<LL>ans(n+1);
    dfs(1,n,ans);

    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct fucalorse
{
    private:
        int n;
        vector<vector<int>>f;
    public:
        fucalorse(int _n,int *a)
        {
            n=_n;
            int size=31-__builtin_clz(n);
            f.assign(size+1,vector<int>(n+1,INF));

            for(int i=1;i<=n;i++)
                f[0][i]=a[i];

            for(int k=1;k<=size;k++)
                for(int i=1;i+(1<<k)-1<=n;i++)
                    f[k][i]=min(f[k-1][i],f[k-1][i+(1<<(k-1))]);
        }

        int query(int st,int ed)
        {
            int k=31-__builtin_clz(ed-st+1);
            return min(f[k][st],f[k][ed-(1<<k)+1]); 
        }
};

int n;
int fs[MAX],ft[MAX];
string s,t;

void solve()
{
    cin>>n>>s>>t;
    s=' '+s,t=' '+t;

    int cs=0,ct=0;
    for(int i=1;i<=n;i++)
    {
        fs[i]=fs[i-1];
        ft[i]=ft[i-1];

        if(s[i]=='(') fs[i]++;
        else fs[i]--;

        if(t[i]=='(') ft[i]++;
        else ft[i]--;

        if(i<n&&s[i]=='('&&s[i+1]==')') ++cs;
        if(i<n&&t[i]=='('&&t[i+1]==')') ++ct;
    }

    if(cs!=ct)
    {
        cout<<"NO"<<endl;
        return;
    }

    auto get=[&](const string &s,int *a)
    {
        fucalorse fu(n,a);
        int cnt=0,pos=1,mid=n>>1;
        while(pos<mid)
        {
            if(s[pos]==')') break;
            int l=pos+1,r=n-pos;
            int minn=fu.query(l,r);
            if(minn-pos<0) break;
            ++cnt;
            ++pos;
        }
        
        if(pos==mid) ++cnt;
        return cnt;
    };

    if(get(s,fs)!=get(t,ft)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
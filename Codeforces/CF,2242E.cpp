#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=29,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

template <typename T>
T __lcm(T a,T b) { return a/__gcd(a,b)*b; }

int L,R,n;

void print(const vector<int>& op)
{
    for(auto &cur:op)
        cout<<cur;
    cout<<endl;
}

void solve()
{
    cin>>L>>R>>n;

    int maxn=-1;
    int st=32-__builtin_clz(L),ed=32-__builtin_clz(R);
    vector<vector<int>>ans;
    for(int i=st;i<=ed;i++)
        for(int j=i;j<=ed;j++)
        {
            int l=max(L,1<<(i-1)),r=min(R,(1<<j)-1);
            if(i==j)
            {
                if(l>=r) continue;

                vector<int>cur;
                int high_bit=31-__builtin_clz(l),diff=-1;
                for(int k=high_bit;k>=0;k--)
                {
                    int pl=(l>>k)&1,pr=(r>>k)&1;
                    if(pl!=pr)
                    {
                        diff=k;
                        break;
                    }
                    cur.push_back(pl&pr);
                }
                for(int k=diff;k>=0;k--)
                    cur.push_back(0);
                ans.push_back(move(cur));
            }
            else
            {
                int len=__lcm(i,j);
                int x=1<<(i-1),y=1<<(j-1);
                if(x>=l)
                {
                    maxn=max(maxn,len);
                    continue;
                }
    
                x=(1<<i)-1;
                int cnt=i/__gcd(i,j);
                for(int k=1;k<cnt;k++)
                {
                    int pos=i-(k*j)%i-1;
                    int nx=x^(1<<pos);
                    if(nx>=l) x=nx;
                }

                vector<int>cur;
                for(int k=0;k<min(n,len);k++)
                {
                    int px=i-1-k%i,py=j-1-k%j;
                    int bx=(x>>px)&1,by=(y>>py)&1;
                    cur.push_back(bx&by);
                }

                ans.push_back(move(cur));
            }
        }

    if(maxn!=-1)
    {
        vector<int>cur(min(maxn,n),0);
        cur[0]=1;
        ans.push_back(move(cur));
    }
    auto &op=*min_element(ans.begin(),ans.end(),[&](const vector<int>& a,const vector<int>& b){
        int lena=a.size(),lenb=b.size();
        for(int i=0;i<n;i++)
        {
            int pa=a[i%lena],pb=b[i%lenb];
            if(pa!=pb) return pa<pb;
        }
        return false;
    });

    for(int i=0;i<n;i++)
        cout<<op[i%(int)op.size()];
    cout<<endl;
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
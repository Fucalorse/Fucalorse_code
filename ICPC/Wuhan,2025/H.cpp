#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9,FULL=(1<<30)-1;
const LL LINF=1e18;

int ask(int c)
{
    cout<<"? "<<c<<endl<<flush;
    int ans;
    cin>>ans;
    return ans^c;
}

int n;
vector<int>ans;

void dfs(int a,int k)
{
    if((int)ans.size()==n||k<0) return;

    int mask=(1<<(k+1))-1;
    int num=FULL^mask^a;
    int cur=ask(num);
    if(cur==a) return;

    ans.push_back(cur);
    int bit=31-__builtin_clz(cur^a);
    dfs(a,bit-1);
    dfs(cur,bit-1);
}

void solve()
{
    cin>>n;

    ans.clear();
    int st=ask(0);
    ans.push_back(st);
    dfs(st,29);

    cout<<"! ";
    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl<<flush;
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
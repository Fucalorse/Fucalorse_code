#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=110,LEN=1e6,MOD=998244353,INF=2e9;

int n,m;
int x[MAX];
bool drop[MAX];
string s[MAX];

string get()
{
    string ans(m,0);

    for(int i=1;i<=n;i++)
    {
        if(drop[i]) continue;

        string &op=s[i];
        int len=(int)op.size();
        for(int j=0,pos=x[i];j<len;j++,pos++)
        {
            // cout<<ans[pos]<<' '<<op[j]<<endl;
            if(!ans[pos]) ans[pos]=op[j];
            else if(ans[pos]!=op[j]) return "";
        }
    }

    for(int i=0;i<m;i++)
        if(!ans[i]) return "";

    return ans;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>s[i];
        --x[i];
    }

    set<string>op;
    string st=get();
    if(st.size()) op.insert(st);

    for(int i=1;i<=n;i++)
    {
        drop[i]=true;
        string now=get();
        if(now.size()) op.insert(now);
        drop[i]=false;
    }

    if(op.empty())
    {
        cout<<-1<<endl;
        return;
    }

    if((int)op.size()>=2) cout<<-2<<endl;
    else cout<<*op.begin()<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
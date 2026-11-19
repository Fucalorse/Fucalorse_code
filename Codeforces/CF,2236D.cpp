#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct qwq
{
    int val,cnt;
}op[MAX];

int T,n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    vector<int>cnt(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        cnt[a[i]]++;
    }

    int qwq=0;
    bool have_link=false,even=false;
    for(int i=1;i<=n;i++)
        if(cnt[i]) op[++qwq]={i,cnt[i]};
    
    for(int i=1;i<=qwq;i++)
    {
        if(op[i].cnt%2==0) even=true;

        if(i>1&&op[i].val-op[i-1].val<=k) have_link=true;
    }

    if(!even&&!have_link) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}
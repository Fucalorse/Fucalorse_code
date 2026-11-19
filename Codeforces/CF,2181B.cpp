#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    priority_queue<int>qa,qb;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qa.push(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        qb.push(b[i]);
    }

    int col=1;
    while(qa.size()&&qb.size())
    {
        int numa=qa.top();qa.pop();
        int numb=qb.top();qb.pop();
        if(col==1)
        {
            if(numb<=numa) qa.push(numa);
            else
            {
                numb-=numa;
                qa.push(numa);
                qb.push(numb);
            }
        }
        else
        {
            if(numa<=numb) qb.push(numb);
            else
            {
                numa-=numb;
                qa.push(numa);
                qb.push(numb);
            }
        }
        col^=1;
    }

    if(qa.size()) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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
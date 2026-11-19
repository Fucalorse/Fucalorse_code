#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int ask(int i,int j)
{
    cout<<"? "<<i<<' '<<j<<endl<<flush;
    int col;
    cin>>col;
    return col;
}

int n;

void solve()
{
    cin>>n;

    int x=-1,y=-1;
    for(int i=1;i<n;i++)
    {
        int col=ask(i,i+1);
        if(col==1)
        {
            x=i,y=i+1;
            break;
        }
    }

    if(x==-1)
    {
        cout<<"! ";
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<endl<<flush;
        return;
    }

    deque<int>left,right;
    for(int i=1;i<x;i++)
    {
        int col=ask(i,y);
        if(col==0) left.push_back(i);
        else right.push_back(i);
    }

    left.push_back(y);
    right.push_back(x);

    for(int i=y+1;i<=n;i++)
    {
        int belong=ask(i,y);
        if(belong==0)
        {
            int col=ask(left.back(),i);
            if(col==1) left.push_front(i);
            else left.push_back(i);
        }
        else
        {
            int col=ask(right.back(),i);
            if(col==1) right.push_front(i);
            else right.push_back(i);
        }
    }

    auto print=[&](deque<int>& q)
    {
        while(q.size())
        {
            cout<<q.front()<<' ';
            q.pop_front();
        }
    };

    cout<<"! ";
    print(left),print(right);
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
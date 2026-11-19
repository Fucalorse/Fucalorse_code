#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=3;
const char s[]={' ','R','G','B'};

struct qwq
{
    char c;
    int cnt;
    bool operator<(const qwq &a)const { return cnt<a.cnt; }
}op[10];

int t;

void solve()
{
    for(int i=1;i<=LEN;i++)
    {
        op[i].c=s[i];
        cin>>op[i].cnt;
    }
    sort(op+1,op+LEN+1);
    int x=op[1].cnt+op[2].cnt-op[3].cnt;
    if(x>0) op[1].cnt-=x,op[2].cnt-=x,op[3].cnt-=x;
    for(int i=1;i<=op[1].cnt;i++)
        cout<<op[3].c<<op[1].c;
    for(int i=1;i<=op[2].cnt;i++)
        cout<<op[3].c<<op[2].c;
    if(x>0)
    {
        char now[5]={op[3].c,op[2].c,op[1].c};
        for(int s=1,p=0;s<=x;s++)
        {
            int i=p,j=(p+1)%3,k=(j+1)%3;
            cout<<now[i]<<now[j]<<now[k];
            p=j;
        }
    }
    if(x<0) cout<<op[3].c;
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
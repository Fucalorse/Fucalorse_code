#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=20;
const vector<vector<int>>h={{1,2,3},{4,5,6},{7,8,9},{1,5,9},{3,5,7},{1,4,7},{2,5,8},{3,6,9}};

struct qwq
{
    int x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        else return y<a.y;
    }
}num[MAX];

int t,n;
int op[MAX];

void clear()
{
    for(int i=1;i<=9;i++)
        op[i]=0;
}

void solve()
{
    cin>>n;
    clear();
    for(int i=1;i<=n;i++)
    {
        cin>>num[i].x>>num[i].y;
        int pos=(num[i].x-1)*3+num[i].y;
        op[pos]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        int pos=(x-1)*3+y;
        op[pos]=2;
    }
    vector<qwq>rest;
    int st=(num[1].x-1)*3+num[1].y;
    for(size_t i=0;i<h.size();i++)
    {
        int cnt=0,pos=0;
        for(auto &cur:h[i])
        {
            if(op[cur]==1)
            {
                ++cnt;
                if(n==3&&cur==st) --cnt;
            }
            else if(!op[cur]) pos=cur;
        }
        // cout<<i<<' '<<cnt<<endl;
        if(cnt==2&&pos)
        {
            int x=(pos-1)/3+1,y=(pos-1)%3+1;
            rest.push_back({x,y});
        }
    }
    if(rest.empty()) cout<<"Columbina Hyposelenia"<<endl;
    else
    {
        sort(rest.begin(),rest.end());
        cout<<rest.front().x<<' '<<rest.front().y<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}
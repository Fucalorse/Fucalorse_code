#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1010;

struct qwq
{
    string day,t;
    int id,s,pos;
    bool operator<(const qwq &a)const { return s<a.s; }
};

bool cmp(const qwq &a,const qwq &b) { return a.pos<b.pos; }

int n,m;
vector<qwq>ans;
priority_queue<qwq>q[25];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        qwq now;
        cin>>now.day>>now.t>>now.id>>now.s;
        now.pos=i;
        q[now.id].push(now);
    }
    for(int i=1;i<=m;i++)
        if(q[i].size()) ans.push_back(q[i].top());
    sort(ans.begin(),ans.end(),cmp);
    for(auto &[d,t,id,s,pos]:ans)
        cout<<d<<' '<<t<<' '<<id<<' '<<s<<endl;
    return 0;
}
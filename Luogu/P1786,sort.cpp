#include <bits/stdc++.h>
using namespace std;

struct qwq
{
    string name,pos;
    int val,level,id;
};
vector<qwq>op,rest;

int get(const string &s)
{
    if(s=="BangZhong") return 1;
    else if(s=="JingYing") return 2;
    else if(s=="TangZhu") return 3;
    else if(s=="ZhangLao") return 4;
    else if(s=="HuFa") return 5;
    else if(s=="FuBangZhu") return 6;
    else return 7;
}

bool cmp1(const qwq &a,const qwq &b)
{
    if(a.val!=b.val) return a.val>b.val;
    return a.id<b.id;
}

bool cmp2(const qwq &a,const qwq &b)
{
    int x=get(a.pos),y=get(b.pos);
    if(x!=y) return x>y;
    else if(a.level!=b.level) return a.level>b.level;
    else return a.id<b.id;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        qwq now;
        cin>>now.name>>now.pos>>now.val>>now.level;
        now.id=i;
        if(now.pos=="FuBangZhu"||now.pos=="BangZhu") op.push_back(now);
        else rest.push_back(now);
    }
    sort(rest.begin(),rest.end(),cmp1);
    for(size_t i=0;i<rest.size();i++)
    {
        int x=i+1;
        if(x>=1&&x<=2) rest[i].pos="HuFa";
        else if(x<=6) rest[i].pos="ZhangLao";
        else if(x<=13) rest[i].pos="TangZhu";
        else if(x<=38) rest[i].pos="JingYing";
        else rest[i].pos="BangZhong";
    }
    sort(op.begin(),op.end(),cmp2);
    sort(rest.begin(),rest.end(),cmp2);
    for(auto &i:op)
        cout<<i.name<<' '<<i.pos<<' '<<i.level<<'\n';
    for(auto &i:rest)
        cout<<i.name<<' '<<i.pos<<' '<<i.level<<'\n';
    return 0;
}
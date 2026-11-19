#include <bits/stdc++.h>
using namespace std;

const string ans="123804765";
const vector<vector<int>>p={{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{6,4,8},{5,7}};

int cal(const string &s)
{
    int total=0,len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0') continue;
        int j=ans.find(s[i]);
        total+=abs(i/3-j/3)+abs(i%3-j%3);
    }
    return total;
}

int hash_s(const string &s)
{
    int total=0;
    for(size_t i=0;i<s.size();i++)
        total=(total<<3)+total+s[i]-'0';
    return total;
}

struct qwq
{
    string w;
    int step,assess;
    bool operator<(const qwq &a)const{ return step+assess>a.step+a.assess;}
};

string s;
priority_queue<qwq>q;
unordered_set<int>vis;

void bfs()
{
    q.push({s,0,cal(s)});
    vis.insert(hash_s(s));
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(cur.w==ans)
        {
            cout<<cur.step<<'\n';
            exit(0);
        }
        int pos=cur.w.find('0');
        for(auto i:p[pos])
        {
            string aft=cur.w;
            swap(aft[pos],aft[i]);
            int val=hash_s(aft);
            if(vis.count(val)) continue;
            vis.insert(val);
            q.push({aft,cur.step+1,cal(aft)});
        }
    }
}

int main()
{
    cin>>s;
    bfs();
    return 0;
}
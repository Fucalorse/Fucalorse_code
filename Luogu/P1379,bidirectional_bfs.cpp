#include <bits/stdc++.h>
using namespace std;

const string ans="123804765";
const vector<vector<int>>p={{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{6,4,8},{5,7}};

string s;
queue<string>qst,qed;
unordered_map<string,int>fst,fed;
typedef unordered_map<string,int> ovo;

int expand(queue<string>&q,ovo &f,ovo &g)
{
    int len=q.size();
    while(len--)
    {
        string cur=q.front();q.pop();
        int pos=cur.find('0');
        for(auto i:p[pos])
        {
            string aft=cur;
            swap(aft[i],aft[pos]);
            if(f.count(aft)) continue;
            if(g.count(aft)) return f[cur]+1+g[aft];
            f[aft]=f[cur]+1;
            q.push(aft);
        }
    }
    return -10086;
}

void bfs()
{
    if(s==ans)
    {
        cout<<0<<'\n';
        exit(0);
    }
    qst.push(s),qed.push(ans);
    fst[s]=0,fed[ans]=0;
    while(qst.size()&&qed.size())
    {
        int res;
        if(qst.size()<=qed.size()) res=expand(qst,fst,fed);
        else res=expand(qed,fed,fst);
        if(res!=-10086)
        {
            cout<<res<<'\n';
            exit(0);
        }
    }
}

int main()
{
    cin>>s;
    bfs();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const string ans="123804765";
const vector<vector<int>>p={{1,3},{0,2,4},{1,5},{0,4,6},{1,3,5,7},{2,4,8},{3,7},{6,4,8},{5,7}};

struct qwq
{
    int x,y;
    bool operator==(const qwq &a)const { return x==a.x&&y==a.y; }
};

string s;
int depth;

int cal()
{
    int total=0,len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0') continue;
        int j=ans.find(s[i]);
        qwq a={i/3,i%3},b={j/3,j%3};
        total+=abs(a.x-b.x)+abs(a.y-b.y);
    }
    return total;
}

bool dfs(int cnt,qwq now,qwq pre)
{
    int res=cal();
    if(!res) return true;
    if(cnt+res>depth) return false;
    int pos=now.x*3+now.y;
    for(auto i:p[pos])
    {
        qwq aft={i/3,i%3};
        if(pre==aft) continue;
        swap(s[pos],s[i]);
        if(dfs(cnt+1,aft,now)) return true;
        swap(s[pos],s[i]);
    }
    return false;
}

int main()
{
    cin>>s;
    depth=cal();
    int pos=s.find('0');
    qwq st={pos/3,pos%3};
    while(1)
    {
        if(dfs(0,st,{-1,-1}))
        {
            cout<<depth<<'\n';
            exit(0);
        }
        depth++;
    }
    return 0;
}
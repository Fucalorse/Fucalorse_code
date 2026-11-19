#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e6+90;

struct qwq
{
    int x1,x2,x3;
    bool operator<(const qwq &a)const
    {
        if(x2!=a.x2) return x2<a.x2;
        else return x1<a.x1;
    }
};

int n;
unordered_map<int,unordered_map<int,bool>>op;
vector<int>f,g;
vector<qwq>ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(op[x][y]) continue;
        op[x][y]=true;
        if(!y) f.push_back(x);
        if(y==1) g.push_back(x);
    }
    for(auto &i:f)
        for(auto &j:g)
        {
            int now=2*j-i;
            if(op[now][2])
                ans.push_back({i,j,now});
        }
    if(ans.empty())
    {
        printf("-1\n");
        return 0;
    }
    sort(ans.begin(),ans.end());
    for(auto &[i,j,k]:ans)
        printf("[%d, 0] [%d, 1] [%d, 2]\n",i,j,k);
    return 0;
}
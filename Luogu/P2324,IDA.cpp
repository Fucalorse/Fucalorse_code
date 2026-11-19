#include <bits/stdc++.h>
using namespace std;

const int MAX=25;
const vector<int>h={0,1,2,3,4,6,7,8,9,13,14,19};
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={-2,-1,1,2,2,1,-1,-2};

int op[MAX+6],depth,t,st;

int cal()
{
    int cnt=0,k=op[12]==2?0:-1;
    for(auto i:h)
    {
        if(op[i]==0) cnt++;
        else if(op[i]==2) k=1;
    }
    if(k==1) return (cnt<<1)+2-op[12];
    else if(k==-1) return (cnt<<1)+1-op[12];
    else return cnt<<1;
}

bool dis(const int &i,const int &j)
{
    return i>=0&&i<=4&&j>=0&&j<=4;
}

bool dfs(int cnt,int now,int pre)
{
    int res=cal();
    if(!res) return true;
    if(cnt+res>depth) return false;
    int x=now/5,y=now%5;
    for(int s=0;s<8;s++)
    {
        int nx=x+dx[s],ny=y+dy[s];
        int aft=nx*5+ny;
        if(!dis(nx,ny)||aft==pre) continue;
        swap(op[now],op[aft]);
        if(dfs(cnt+1,aft,now)) return true;
        swap(op[now],op[aft]);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        for(int i=0;i<MAX;i++)
        {
            char c;
            cin>>c;
            if(c=='*') op[i]=2,st=i;
            else op[i]=c-'0';
        }
        depth=cal();
        bool f=false;
        while(depth<=15)
        {
            f=dfs(0,st,-1);
            if(f) break;
            depth++;
        }
        if(f) printf("%d\n",depth);
        else printf("-1\n");
    }
    return 0;
}
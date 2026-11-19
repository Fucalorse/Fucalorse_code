#include <bits/stdc++.h>
using namespace std;

const int MAX=50;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y;
    int step,assess;
    bool operator<(const qwq &a)const { return step+assess>a.step+a.assess; }
}st,ed;

int n,m;
char op[MAX][MAX];
priority_queue<qwq>q;
unordered_map<int,int>f;

int cal(const qwq &a)
{
    return abs(a.x-ed.x)+abs(a.y-ed.y);
}

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m&&op[i][j]!='#';
}

void bfs()
{
    st.assess=cal(st);
    q.push(st);
    f[st.x*m+st.y]=0;
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(!cur.assess)
        {
            cout<<cur.step<<'\n';
            return;
        }
        int x=cur.x,y=cur.y;
        for(int s=0;s<4;s++)
        {
            int nx=x+dx[s],ny=y+dy[s],pos=nx*m+ny;
            if(dis(nx,ny))
            {
                if(f.count(pos)&&cur.step+1>f[pos]) continue;
                f[pos]=cur.step+1;
                qwq aft={nx,ny,cur.step+1,0};
                aft.assess=cal(aft);
                q.push(aft);
            }
        }
    }
    cout<<"NO ANSWER\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    srand(time(0));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int now=rand()%4;
            if(now==0) op[i][j]='#';
            else if(now==1) op[i][j]='.';
            else if(now==2) op[i][j]='S',st={i,j,0,0};
            else op[i][j]='E',ed={i,j,0,0};
        }
    bfs();
    return 0;
}
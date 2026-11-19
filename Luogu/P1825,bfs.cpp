#include <bits/stdc++.h>
using namespace std;

const int MAX=350;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y,t;
}st;

int n,m;
char op[MAX][MAX];
bool vis[MAX][MAX]={false};
vector<qwq>p[30];

void change(int &i,int &j)
{
    const char &c=op[i][j];
    const qwq &p1=p[c-'A'][0],&p2=p[c-'A'][1];
    if(i==p1.x&&j==p1.y) i=p2.x,j=p2.y;
    else i=p1.x,j=p1.y;
}

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m&&op[i][j]!='#';
}

void bfs()
{
    queue<qwq>q;
    q.push(st);
    vis[st.x][st.y]=true;
    while(q.size())
    {
        qwq cur=q.front();q.pop();
        int i=cur.x,j=cur.y,now=cur.t;
        if(op[i][j]=='=')
        {
            cout<<now<<endl;
            exit(0);
        }
        if(isupper(op[i][j])) change(i,j);
        for(int s=0;s<4;s++)
        {
            int ni=i+dx[s],nj=j+dy[s];
            if(dis(ni,nj)&&!vis[ni][nj])
            {
                vis[ni][nj]=true;
                q.push({ni,nj,now+1});
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>op[i][j];
            if(op[i][j]=='@') st={i,j,0};
            if(isupper(op[i][j])) p[op[i][j]-'A'].push_back({i,j,0});
        }
    bfs();
    return 0;
}
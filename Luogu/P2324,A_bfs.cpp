#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=25;
const vector<int>h={0,1,2,3,4,6,7,8,9,13,14,19};
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={-2,-1,1,2,2,1,-1,-2};

struct qwq
{
    int op[MAX+5],pos;
    int step,assess;
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
    LL HASH()
    {
        LL total=0;
        for(int i=0;i<MAX;i++)
            total|=(LL)op[i]<<(i<<1);
        return total;
    }
    void change(const int &aft)
    {
        swap(op[aft],op[pos]);
        pos=aft;
        step++;
        assess=cal();
    }
    bool operator<(const qwq &a)const { return step+assess>a.step+a.assess; }
};

bool dis(const int &i,const int &j)
{
    return i>=0&&i<=4&&j>=0&&j<=4;
}

int bfs(qwq &st)
{
    st.assess=st.cal(),st.step=0;
    priority_queue<qwq>q;
    unordered_set<LL>vis;
    q.push(st);
    vis.insert(st.HASH());
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(!cur.assess) return cur.step;
        if(cur.assess+cur.step>15) continue;
        int x=cur.pos/5,y=cur.pos%5;
        for(int s=0;s<8;s++)
        {
            int nx=x+dx[s],ny=y+dy[s];
            if(dis(nx,ny))
            {
                qwq aft=cur;
                aft.change(nx*5+ny);
                if(aft.step+aft.assess>15) continue;
                LL val=aft.HASH();
                if(vis.count(val)) continue;
                vis.insert(val);
                q.push(aft);
            }
        }
    }
    return -10086;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        qwq st;
        for(int i=0;i<MAX;i++)
        {
            char c;
            cin>>c;
            if(c=='*') st.op[i]=2,st.pos=i;
            else st.op[i]=c-'0';
        }
        int now=bfs(st);
        if(now!=-10086) cout<<now<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}
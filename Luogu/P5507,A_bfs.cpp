#include <bits/stdc++.h>
using namespace std;

const int MAX=12,LEN=1<<25;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

int f[20][6];
struct qwq
{
    int mask;
    int step,assess;
    vector<int>ans;
    int cal()
    {
        int total=0;
        for(int i=0;i<MAX;i++)
        {
            int pos=(mask>>(i<<1))&3;
            total+=(4-pos)&3;
        }
        return total>>1;
    }
    void flip(const int &i)
    {
        int p1=(mask>>(i<<1))&3;
        int j=f[i][p1],p2=(mask>>(j<<1))&3;
        int aft=mask^(p1<<(i<<1))^(((p1+1)&3)<<(i<<1));
        aft=aft^(p2<<(j<<1))^(((p2+1)&3)<<(j<<1));
        mask=aft;
        step++;
        assess=cal();
        ans.push_back(i);
    }
    void print()
    {
        for(auto i:ans)
            printf("%d ",i+1);
        printf("\n");
    }
    bool operator<(const qwq &a)const { return step+assess>a.step+a.assess; }
};

qwq st;
priority_queue<qwq>q;
bool vis[LEN]={false};

void bfs()
{
    st.assess=st.cal();
    st.step=0;
    q.push(st);
    vis[st.mask]=true;
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(!cur.assess)
        {
            printf("%d\n",cur.step);
            cur.print();
            exit(0);
        }
        for(int i=0;i<MAX;i++)
        {
            qwq aft=cur;
            aft.flip(i);
            if(vis[aft.mask]) continue;
            vis[aft.mask]=true;
            q.push(aft);
        }
    }
}

int main()
{
    for(int i=0;i<MAX;i++)
    {
        int a=read()-1;
        st.mask|=a<<(i<<1);
        for(int j=0;j<4;j++)
            f[i][j]=read()-1;
    }
    bfs();
    return 0;
}
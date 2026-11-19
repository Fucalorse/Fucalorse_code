#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5,LEN=18;

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

struct fucalorse
{
    private:
        int op[MAX+90];
        int lowbit(int n) { return n&-n; }
    public:
        void update(int n,const int &k)
        {
            while(n<=MAX)
            {
                op[n]+=k;
                n+=lowbit(n);
            }
        }
        int query(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=op[n];
                n-=lowbit(n);
            }
            return ans;
        }
        int find(const int &ed)
        {
            int pos=0,sum=0,cnt=query(ed);
            for(int k=LEN;k>=0;k--)
            {
                int aft=pos+(1<<k);
                if(aft<ed&&sum+op[aft]<cnt)
                {
                    sum+=op[aft];
                    pos=aft;
                }
            }
            return pos+1;
        }
}fu;

int q;
int r[MAX+90];

int main()
{
    q=read();
    int total=0;
    while(q--)
    {
        char c;
        scanf(" %c",&c);
        if(c=='A')
        {
            int st=read(),ed=read(),del=0;
            while(1)
            {
                int pos=fu.find(ed);
                if(r[pos]>=st)
                {
                    del++;
                    fu.update(pos,-1);
                    r[pos]=0;
                    total--;
                }
                else break;
            }
            printf("%d\n",del);
            fu.update(st,1);
            r[st]=ed;
            total++;
        }
        else printf("%d\n",total);
    }
    return 0;
}
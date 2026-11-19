#include <bits/stdc++.h>
using namespace std;

#define UI unsigned int

const int MAX=1e5+90;

struct read
{
    int num_read()
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
    pair<UI,UI> string_read()
    {
        pair<UI,UI>ans={0,0};
        UI f=1;
        char c=getchar();
        while(c!='1'&&c!='0'&&c!='?') c=getchar();
        while(c=='1'||c=='0'||c=='?')
        {
            if(c^'?')
            {
                if(c^'0') ans.first|=f;
                else ans.second|=f;
            }
            f<<=1;
            c=getchar();
        }
        return ans;
    }
}fu;

struct fucalorse
{
    private:
        struct qwq
        {
            UI a1,a0;
            qwq operator|(const qwq &other)const
            {
                return {a1|other.a1,a0|other.a0};
            }
            qwq operator~()const
            {
                return {~a1,~a0};
            }
            qwq operator&(const qwq &other)const
            {
                return {a1&other.a1,a0&other.a0};
            }
        };
        vector<qwq>op,num;
        int size;
        int lowbit(int n) { return n&-n; }
        qwq query(int x,int y)
        {
            if(x==y) return num[x];
            if(y-lowbit(y)<x) return num[y]|query(x,y-1);
            else return op[y]|query(x,y-lowbit(y));
        }
    public:
        fucalorse(int n)
        {
            size=n;
            op.resize(n+10,{0,0});
            num.resize(n+10,{0,0});
        }
        void update(int n)
        {
            int m=n;
            const qwq &pre=num[n];
            while(m<=size)
            {
                op[m]=op[m]&(~pre);
                m+=lowbit(m);
            }
            auto p=fu.string_read();
            num[n]={p.first,p.second};
            const qwq &now=num[n];
            while(n<=size)
            {
                op[n]=op[n]|now;
                n+=lowbit(n);
            }
        }
        UI find(const int &st,const int &ed,const int &k)
        {
            qwq now=query(st,ed);
            if(now.a0&now.a1) return 0;
            else
            {
                UI ans=(~now.a0)&(~now.a1)&((1<<k)-1);
                bitset<32>bit(ans);
                return 1<<(bit.count());
            }
        }
};

int main()
{
    int k=fu.num_read(),n=fu.num_read(),q=fu.num_read();
    fucalorse fufu(n);
    for(int i=1;i<=n;i++)
        fufu.update(i);
    UI ans=0;
    while(q--)
    {
        int p=fu.num_read();
        if(!p)
        {
            int st=fu.num_read(),ed=fu.num_read();
            ans^=fufu.find(st,ed,k);
        }
        else
        {
            int x=fu.num_read();
            fufu.update(x);
        }
    }
    printf("%u\n",ans);
    return 0;
}
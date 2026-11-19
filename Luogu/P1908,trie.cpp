#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e5+90,LEN=29;

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
        struct qwq
        {
            qwq *op[2];
            int cnt;
            qwq() { op[0]=op[1]=nullptr,cnt=0; }
        };
        qwq *root=new qwq;
    public:
        int update(const int &sum)
        {
            int ans=0;
            qwq *now=root;
            for(int i=LEN;i>=0;i--)
            {
                int p=(sum>>i)&1;
                if(!p&&now->op[1]) ans+=now->op[1]->cnt;
                if(!now->op[p]) now->op[p]=new qwq;
                now=now->op[p];
                now->cnt++;
            }
            return ans;
        }
}fu;

int main()
{
    int n=read();
    LL total=0;
    for(int i=1;i<=n;i++)
        total=total+fu.update(read());
    printf("%lld\n",total);
    return 0;
}
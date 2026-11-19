#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;

struct node
{
    LL P,M;
    node():P(0),M(0){}
};

struct qwq
{
    node top,bottom,left,right;
    qwq():top(node()),bottom(node()),left(node()),right(node()){}
};

int n;
LL p[MAX];

qwq merge1(const qwq &A,const qwq &B,LL a,LL b,LL TR,LL BL)
{
    qwq ans;
    LL len=a+b;

    ans.top.P=max(A.top.P,TR+len-1);
    ans.top.M=max(A.top.M,TR-(len-1));

    ans.right.P=max(TR,B.right.P+a);
    ans.right.M=max(TR,B.right.M-a);

    ans.bottom.P=max(BL,B.bottom.P+a);
    ans.bottom.M=max(BL,B.bottom.M-a);

    ans.left.P=max(A.left.P,BL+len-1);
    ans.left.M=max(A.left.M,BL-(len-1));

    return ans;
}

qwq merge2(const qwq &A,const qwq &B,LL a,LL b,LL TL,LL BR)
{
    qwq ans;
    LL len=a+b;

    ans.top.P=max(TL,B.top.P+a);
    ans.top.M=max(TL,B.top.M-a);

    ans.right.P=max(B.right.P,BR+len-1);
    ans.right.M=max(B.right.M,BR-(len-1));

    ans.bottom.P=max(A.bottom.P,BR+len-1);
    ans.bottom.M=max(A.bottom.M,BR-(len-1));

    ans.left.P=max(TL,A.left.P+b);
    ans.left.M=max(TL,A.left.M-b);

    return ans;
}

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>p[i];

    LL ans=0;
    vector<pair<int,int>>h;
    vector<qwq>op;

    for(int i=1;i<=n;i++)
    {
        h.push_back({p[i],p[i]});
        op.push_back(qwq());

        while((int)h.size()>=2)
        {
            auto x=h[(int)h.size()-2],y=h.back();

            if(x.first==y.second+1)
            {
                h.pop_back(),h.pop_back();

                qwq A=op[(int)op.size()-2],B=op.back();
                op.pop_back(),op.pop_back();

                LL a=x.second-x.first+1,b=y.second-y.first+1;
                LL TR=max(A.right.P+b,B.top.M+a+b-1),BL=max(A.bottom.P+b,B.left.M+a+b-1);

                ans=max(ans,max(TR,BL));
                h.push_back({y.first,x.second});
                op.push_back({merge1(A,B,a,b,TR,BL)});
            }
            else if(x.second+1==y.first)
            {
                h.pop_back(),h.pop_back();

                qwq A=op[(int)op.size()-2],B=op.back();
                op.pop_back(),op.pop_back();

                LL a=x.second-x.first+1,b=y.second-y.first+1;
                LL TL=max(B.left.P+a,A.top.P+b),BR=max(A.right.M+a+b-1,B.bottom.M+a+b-1);

                ans=max(ans,max(TL,BR));
                h.push_back({x.first,y.second});
                op.push_back({merge2(A,B,a,b,TL,BR)});
            }
            else break;
        }
    }

    if((int)h.size()==1) cout<<ans<<endl;
    else cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}
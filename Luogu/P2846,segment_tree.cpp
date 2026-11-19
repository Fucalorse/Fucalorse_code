#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m;

struct peach
{
    private:
        struct qwq
        {
            int cnt;
            bool flip;
        }op[MAX<<2];

        void reverse(int id,int len)
        {
            op[id].cnt=len-op[id].cnt;
            op[id].flip^=1;
        }
        void down(int l,int r,int id)
        {
            if(op[id].flip)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                reverse(hl,lenl),reverse(hr,lenr);
                op[id].flip=false;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                reverse(id,r-l+1);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);
            op[id].cnt=op[hl].cnt+op[hr].cnt;
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return 0;
            if(st<=l&&r<=ed) return op[id].cnt;
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }
    public:
        void update(int st,int ed) { dfs(1,n,1,st,ed); }
        int get(int st,int ed) { return query(1,n,1,st,ed); }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    while(m--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        if(p==0) fu.update(l,r);
        else cout<<fu.get(l,r)<<endl;
    }
    return 0;
}
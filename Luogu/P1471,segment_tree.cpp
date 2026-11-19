#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int n,q;
struct fucalorse
{
    private:
        struct tree
        {
            double sum,square,lazy;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            if(l==r)
            {
                cin>>op[id].sum;
                op[id].square=op[id].sum*op[id].sum;
                return;
            }
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].sum=op[hl].sum+op[hr].sum;
            op[id].square=op[hl].square+op[hr].square;
        }
        void down(int l,int r,int id)
        {
            if(op[id].lazy)
            {
                int mid=(l+r)>>1;
                int hl=id<<1,hr=id<<1|1;
                int lenl=mid-l+1,lenr=r-mid;
                const double &k=op[id].lazy;

                op[hl].square+=lenl*k*k+2*k*op[hl].sum;
                op[hl].sum+=lenl*k;
                op[hl].lazy+=k;

                op[hr].square+=lenr*k*k+2*k*op[hr].sum;
                op[hr].sum+=lenr*k;
                op[hr].lazy+=k;

                op[id].lazy=0.0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const double &k)
        {
            if(st<=l&&r<=ed)
            {
                int len=r-l+1;
                op[id].square+=len*k*k+2*k*op[id].sum;
                op[id].sum+=len*k;
                op[id].lazy+=k;
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id].sum=op[hl].sum+op[hr].sum;
            op[id].square=op[hl].square+op[hr].square;
        }
        pair<double,double> query(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed) return {op[id].sum,op[id].square};
            down(l,r,id);
            int mid=(l+r)>>1;
            int hl=id<<1,hr=id<<1|1;
            pair<double,double>f={0.0,0.0},g={0.0,0.0};
            if(st<=mid) f=query(l,mid,hl,st,ed);
            if(mid<ed) g=query(mid+1,r,hr,st,ed);
            return {f.first+g.first,f.second+g.second};
        }
        public:
            void debut() { create(1,n,1); }
            void update(const int &st,const int &ed,const double &k)
            {
                dfs(1,n,1,st,ed,k);
            }
            double find(const int &st,const int &ed,const int &p)
            {
                auto now=query(1,n,1,st,ed);
                int len=ed-st+1;
                if(p==2) return now.first/len;
                else
                {
                    double a=now.first/len;
                    return (now.second-2*a*now.first)/len+a*a;
                }
            }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    fu.debut();
    while(q--)
    {
        int p,st,ed;
        cin>>p>>st>>ed;
        if(p==1)
        {
            double k;
            cin>>k;
            fu.update(st,ed,k);
        }
        else cout<<fixed<<setprecision(4)<<fu.find(st,ed,p)<<'\n';
    }
    return 0;
}
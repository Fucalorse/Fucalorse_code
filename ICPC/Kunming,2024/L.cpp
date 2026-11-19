#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e6+90;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    int rest=0,total=0;
    bool have_one=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)
        {
            ++rest;
            --a[i];
        }
        else have_one=true;
    }

    int maxb=-1;
    map<int,int>fa,fb;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        ++fb[b[i]];
        maxb=max(maxb,b[i]);
    }

    for(int i=1;i<=n;i++)
        if(a[i]<=maxb) ++fa[a[i]];

    if(have_one)
    {
        --fa[1];
        if(fa[1]==0) fa.erase(1);
        ++total;
        ++rest;
    }

    auto ita=fa.begin(),itb=fb.begin();
    while(ita!=fa.end()||itb!=fb.end())
    {
        bool updated=false;

        auto update_fa=[&]()->void
        {
            while(ita!=fa.end())
            {
                if(total<ita->first) break;

                total+=ita->second;
                ++ita;
                updated=true;
            }            
        };

        update_fa();
        while(itb!=fb.end())
        {
            while(itb->second)
            {
                if(total>=itb->first) ++total;
                else
                {
                    int dx=itb->first-total;
                    if(rest<dx) break;
                    rest-=dx;
                    ++total;
                }

                updated=true;
                update_fa();
                --itb->second;
            }

            if(itb->second==0) ++itb;
            else break;
        }

        if(!updated) break;
    }

    if(itb==fb.end()) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ L.cpp -O2 -o out && ./out < in.txt
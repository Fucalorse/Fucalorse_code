#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    if (s[n - 1] == '0' && s[n - 2] == '0') {
        cout << "Yes" << endl;
        return;
    }
    
    int cnt[2] = {};
    int last[2] = {};
    for (int i = 0; i < n; i++) {
        int v = s[i] - '0';
        if (v == 0 && cnt[0] + 1 > cnt[1]) {
            cnt[0] = 0, cnt[1] = 0;
            continue;
        }

        cnt[v]++;

        if (s[i] == '1') {
            last[0] = cnt[0], last[1] = cnt[1];
        }
    }

    int tail = 0;
    for (int i = n - 1; i >= 0 && s[i] == '0'; i--) {
        ++tail;
    }

    if (tail + last[0] >= 2) {
        cout << "Yes" << endl;
    } else {
        int c0=last[0]+tail,c1=last[1];
        if(c0+c1>=4) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
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

// g++ D.cpp -O2 -o out.exe && .\out.exe < in.txt
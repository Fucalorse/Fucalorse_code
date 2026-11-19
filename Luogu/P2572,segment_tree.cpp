#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 90, inf = 2e9;

int read()
{
    int ans = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans * f;
}

int n, q;
struct fucalorse
{
private:
    struct qwq
    {
        int c0, max0, l0, r0;
        int c1, max1, l1, r1;
        bool to0, to1, flip;
    } op[MAX << 2];

    qwq assign(int a, int b, bool f1, bool f2, bool f3)
    {
        return {a, a, a, a, b, b, b, b, f1, f2, f3};
    }

    void change(qwq &now)
    {
        swap(now.c0, now.c1), swap(now.max0, now.max1);
        swap(now.l0, now.l1), swap(now.r0, now.r1);
        now.flip ^= 1;
    }

    qwq merge(const qwq &a, const qwq &b)
    {
        if (a.c0 == inf)
            return b;
        else if (b.c0 == inf)
            return a;
        int mid0 = a.r0 + b.l0, mid1 = a.r1 + b.l1;
        int max0 = max(max(a.max0, b.max0), mid0);
        int max1 = max(max(a.max1, b.max1), mid1);
        int l0 = a.c1 ? a.l0 : mid0, r0 = b.c1 ? b.r0 : mid0;
        int l1 = a.c0 ? a.l1 : mid1, r1 = b.c0 ? b.r1 : mid1;
        return {a.c0 + b.c0, max0, l0, r0, a.c1 + b.c1, max1, l1, r1, false, false, false};
    }

    void down(int l, int r, int id)
    {
        int mid = (l + r) >> 1;
        int hl = id << 1, hr = id << 1 | 1;
        int lenl = mid - l + 1, lenr = r - mid;
        if (op[id].to0)
        {
            op[hl] = assign(lenl, 0, true, false, false);
            op[hr] = assign(lenr, 0, true, false, false);
            op[id].to0 = false;
        }
        else if (op[id].to1)
        {
            op[hl] = assign(0, lenl, false, true, false);
            op[hr] = assign(0, lenr, false, true, false);
            op[id].to1 = false;
        }
        if (op[id].flip)
        {
            change(op[hl]);
            change(op[hr]);
            op[id].flip = false;
        }
    }

    void create(int l, int r, int id)
    {
        if (l == r)
        {
            int now = read();
            if (now)
                op[id] = assign(0, 1, false, false, false);
            else
                op[id] = assign(1, 0, false, false, false);
            return;
        }
        int mid = (l + r) >> 1;
        int hl = id << 1, hr = id << 1 | 1;
        create(l, mid, hl);
        create(mid + 1, r, hr);
        op[id] = merge(op[hl], op[hr]);
    }

    void dfs(int l, int r, int id, const int &st, const int &ed, const int &p)
    {
        if (st <= l && r <= ed)
        {
            int len = r - l + 1;
            if (p == 0)
                op[id] = assign(len, 0, true, false, false);
            else if (p == 1)
                op[id] = assign(0, len, false, true, false);
            else
                change(op[id]);
            return;
        }
        down(l, r, id);
        int mid = (l + r) >> 1;
        int hl = id << 1, hr = id << 1 | 1;
        if (st <= mid)
            dfs(l, mid, hl, st, ed, p);
        if (mid < ed)
            dfs(mid + 1, r, hr, st, ed, p);
        op[id] = merge(op[hl], op[hr]);
    }

    qwq query(int l, int r, int id, const int &st, const int &ed)
    {
        if (r < st || l > ed)
            return assign(inf, inf, false, false, false);
        if (st <= l && r <= ed)
            return op[id];
        down(l, r, id);
        int mid = (l + r) >> 1;
        int hl = id << 1, hr = id << 1 | 1;
        return merge(query(l, mid, hl, st, ed), query(mid + 1, r, hr, st, ed));
    }

public:
    void debut() { create(1, n, 1); }
    void update(const int &st, const int &ed, const int &p)
    {
        dfs(1, n, 1, st, ed, p);
    }
    int find(const int &st, const int &ed, const int &p)
    {
        qwq now = query(1, n, 1, st, ed);
        if (p == 3)
            return now.c1;
        else
            return now.max1;
    }
} fu;

int main()
{
    n = read(), q = read();
    fu.debut();
    while (q--)
    {
        int p = read(), st = read() + 1, ed = read() + 1;
        if (p <= 2)
            fu.update(st, ed, p);
        else
            printf("%d\n", fu.find(st, ed, p));
    }
    return 0;
}
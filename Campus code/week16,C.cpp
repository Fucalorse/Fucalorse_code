#include <stdio.h>
#include <string.h>

#define MAXN 100

char s[MAXN];
char buf[MAXN];
int len;

void erase_range(int l, int r)
{
    // 删除 [l, r]
    memmove(s + l, s + r + 1, len - r);
    len -= r - l + 1;
    s[len] = '\0';
}

void local_eliminate(int pos)
{
    if (len == 0 || pos < 0 || pos >= len)
        return;

    int l = pos, r = pos;
    char c = s[pos];

    while (l - 1 >= 0 && s[l - 1] == c)
        l--;
    while (r + 1 < len && s[r + 1] == c)
        r++;

    if (r - l + 1 < 3)
        return;

    while (1)
    {
        int mid = l;   // 删除后左右两边会在 mid 这个位置接上

        erase_range(l, r);

        if (len == 0)
            return;

        // 必须左右两边都存在，并且左右边界字符相同，才可能发生连锁
        if (mid <= 0 || mid >= len)
            return;

        if (s[mid - 1] != s[mid])
            return;

        c = s[mid];

        l = mid - 1;
        r = mid;

        while (l - 1 >= 0 && s[l - 1] == c)
            l--;
        while (r + 1 < len && s[r + 1] == c)
            r++;

        if (r - l + 1 < 3)
            return;
    }
}

void global_eliminate()
{
    int changed;

    do
    {
        changed = 0;
        int i = 0;
        int k = 0;

        while (i < len)
        {
            int j = i + 1;

            while (j < len && s[j] == s[i])
                j++;

            if (j - i >= 3)
            {
                changed = 1;
            }
            else
            {
                while (i < j)
                    buf[k++] = s[i++];
                continue;
            }

            i = j;
        }

        buf[k] = '\0';

        if (changed)
        {
            strcpy(s, buf);
            len = k;
        }

    } while (changed);
}

int main()
{
    char op[10];
    int pos;

    scanf("%s", s);
    len = strlen(s);

    while (scanf("%s %d", op, &pos) == 2)
    {
        if (op[0] == '@')
        {
            global_eliminate();
        }
        else if (op[0] == '#')
        {
            // # pos：第 pos 个字符变成前一个字符，pos 是 1-based
            int idx = pos - 1;

            if (idx > 0 && idx < len)
            {
                s[idx] = s[idx - 1];
                local_eliminate(idx);
            }
        }
        else
        {
            // 普通字符：插入到第 pos 个字符后面
            // 等价于插入到数组下标 pos 的位置
            char ch = op[0];

            if (pos < 0)
                pos = 0;
            if (pos > len)
                pos = len;

            memmove(s + pos + 1, s + pos, len - pos + 1);
            s[pos] = ch;
            len++;

            local_eliminate(pos);
        }

        if (len == 0)
        {
            printf("You win!\n");
            break;
        }
        else
        {
            printf("%s\n\n", s);
        }
    }

    return 0;
}
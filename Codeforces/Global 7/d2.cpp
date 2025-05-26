#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1000000;
char s[maxn + 5];
char t[maxn * 2 + 5];
char ans[maxn + 5];

int p[maxn * 2 + 5];

void prefix_function(char *str, int n)
{
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = p[i - 1];
        while (j > 0 && str[i] != str[j])
        {
            j = p[j - 1];
        }
        if (str[i] == str[j])
            j++;
        p[i] = j;
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%s", s);
        int len;
        len = strlen(s);
        int pre;
        for (pre = 0; pre < len / 2; pre++)
        {
            if (s[pre] != s[len - pre - 1])
            {
                break;
            }
        }
        int suff = 0;
        bool start = true;

        int cur = 0;
        int len2 = (len - (pre * 2)) * 2 + 1;
        if (len2 > 1)
        {
            for (int i = pre; i < len - pre; i++)
            {
                t[cur] = t[len2 - cur - 1] = s[i];
                cur++;
            }
            t[cur] = '$';
            t[len2] = '\0';
            prefix_function(t, len2);
            suff = p[len2 - 1];

            cur = 0;
            for (int i = len - pre - 1; i >= pre; i--)
            {
                t[cur] = t[len2 - cur - 1] = s[i];
                cur++;
            }
            t[cur] = '$';
            t[len2] = '\0';
            prefix_function(t, len2);

            if (p[len2 - 1] > suff)
            {
                suff = p[len2 - 1];
                start = false;
            }
        }

        int ans_len = pre * 2 + suff;
        cur = 0;
        for (int i = 0; i < pre; i++)
        {
            ans[cur] = ans[ans_len - cur - 1] = s[i];
            cur++;
        }
        if (start)
        {
            memcpy(ans + cur, s + pre, suff);
        }
        else
        {
            memcpy(ans + cur, s + len - pre - suff, suff);
        }
        ans[ans_len] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
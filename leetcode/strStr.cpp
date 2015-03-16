class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int m = strlen(needle);
        int n = strlen(haystack);
        if(m == 0)
            return 0;
        if(n == 0)
            return -1;
        int f[m + 1];
        f[0] = f[1] = 0;
        for(int i = 1; i < m; i++) {
            int j = f[i];
            while(j && needle[i] != needle[j])
                j = f[j];
            f[i+1] = needle[i] == needle[j] ? j + 1 : 0;
        }
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j && haystack[i] != needle[j])
                j = f[j];
            if(haystack[i] == needle[j])
                j++;
            if(j == m)
                return i - m + 1;
        }
        return -1;
    }
};

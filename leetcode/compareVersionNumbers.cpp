class Solution {
private:
    int decode(string& v) {
        if(v.empty())
            return 0;
        int dot = -1;
        for(int i = 0; i < v.length(); i++) {
            if(v[i] == '.') {
                dot = i;
                break;
            }
        }
        if(dot == -1) {
            int ans = atoi(v.c_str());
            v = "";
            return ans;
        } else {
            int ans = atoi(v.substr(0, dot).c_str());
            v = v.substr(dot+1);
            return ans;
        }
    }
public:
    int compareVersion(string version1, string version2) {
        int v1 = decode(version1);
        int v2 = decode(version2);
        if(v1 != v2) {
            return v1 < v2 ? -1 : 1;
        }
        if(version1.empty() && version2.empty())
            return 0;
        else
            return compareVersion(version1, version2);
    }
};

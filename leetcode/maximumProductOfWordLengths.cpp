class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            int mask = 0;
            for(int j = 0; j < word.length(); j++) {
                mask |= (1 << (word[j] - 'a'));
            }
            masks.push_back(mask);
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            for(int j = i + 1; j < words.size(); j++) {
                if(masks[i] & masks[j]) {
                    continue;
                } else {
                    int cur = words[i].length() * words[j].length();
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};

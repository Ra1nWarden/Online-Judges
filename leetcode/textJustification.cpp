#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<vector<int> > indices;
        for(int i = 0; i < words.size(); i++) {
            vector<int> row;
            int length = words[i].length();
            row.push_back(i);
            for(i++; i < words.size(); i++) {
                if(length + 1 + words[i].length() > maxWidth) {
                    i--;
                    break;
                } else {
                    row.push_back(i);
                    length += (1 + words[i].length());
                }
            }
            indices.push_back(row);
        }
        for(int i = 0; i < indices.size() - 1; i++) {
            string each = "";
            int total = 0;
            for(int j = 0; j < indices[i].size(); j++) {
                total += words[indices[i][j]].length();
            }
            int r, d;
            if (indices[i].size() > 1) {
                r = (maxWidth - total) % (indices[i].size() - 1);
                d = (maxWidth - total) / (indices[i].size() - 1);
            }
            for(int j = 0; j < indices[i].size(); j++) {
                if(j > 0) {
                    if(r > 0) {
                        each += string(d+1, ' ');
                        r--;
                    } else {
                        each += string(d, ' ');
                    }
                }
                each += words[indices[i][j]];
            }
            while(each.length() < maxWidth)
                each += " ";
            ans.push_back(each);
        }
        string finalrow = "";
        for(int j = 0; j < indices.back().size(); j++) {
            if(j > 0)
                finalrow += " ";
            finalrow += words[indices.back()[j]];
        }
        while(finalrow.length() < maxWidth)
            finalrow += " ";
        ans.push_back(finalrow);
        return ans;
    }
};

int main() {
  Solution sol;
  vector<string> words;
  words.push_back("Here");
  words.push_back("is");
  words.push_back("an");
  words.push_back("example");
  words.push_back("of");
  words.push_back("text");
  words.push_back("justification.");
  sol.fullJustify(words, 16);
  return 0;
}

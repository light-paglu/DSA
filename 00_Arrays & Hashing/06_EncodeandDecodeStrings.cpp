#include <bits/stdc++.h>
using namespace std;

// Encode and Decode Strings
// Input: strs = ["Hello","World"]
// Output: ["Hello","World"]

// Make string as: size + # + string
// IMP: substr, length
// TC & SC : based on inputs

class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";
        for (auto str : strs) {
            s += to_string(str.size());
            s += '#';
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int size = stoi(s.substr(i, j - i));

            i = j + 1;
            ans.push_back(s.substr(i, size));

            i = i + size;
        }

        return ans;
    }
};
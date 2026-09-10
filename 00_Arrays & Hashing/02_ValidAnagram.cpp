#include <bits/stdc++.h>
using namespace std;

// Valid Anagram
// Input: s = "anagram", t = "nagaram"
// Output: true

// Map of count, at same time add and remove same array or map
// TC - O(N)
// SC - O(1) (only 26 or 256 char fixed)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n != m)
            return false;

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto it : mp) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
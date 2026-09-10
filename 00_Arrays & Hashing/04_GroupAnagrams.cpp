#include <bits/stdc++.h>
using namespace std;

// Group Anagrams
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// If input is any characters
// Map
// Key: sorted string
// Value: vector of strings
// TC - O(M * N logN)
// SC - O(M * N)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto str : strs) {
            vector<int> freq(26, 0);
            for (auto ch : str) {
                freq[ch - 'a']++;
            }

            string s = to_string(freq[0]);
            for (int i = 1; i < 26; i++) {
                s += ',';
                s += to_string(freq[i]);
            }

            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
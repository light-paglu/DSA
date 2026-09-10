#include <bits/stdc++.h>
using namespace std;

// Longest Substring Without Repeating Characters
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. 
// Note that "bca" and "cab" are also correct answers.

// Hash Map + Sliding window
// Here we store last index where char appers so direct we can jump left to that index.
// TC - O(N)
// SC - O(M)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;

        int l = 0, r = 0;
        while (r < n) {
            if (mp.contains(s[r]) && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }

            ans = max(ans, (r - l + 1));
            mp[s[r]] = r;
            r++;
        }

        return ans;
    }
};
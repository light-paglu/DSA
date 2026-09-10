#include <bits/stdc++.h>
using namespace std;

// Longest Repeating Character Replacement
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.

// Hash Map + Two pointers
// (Window length - Window's max frequent element) > k -> push left pointer
// TC - O(N)
// SC - O(26) ~ O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        int maxf = 0;
        unordered_map<char, int> mp;

        int l = 0, r = 0;
        while (r < n) {
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);

            if ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, (r - l + 1));
            r++;
        }

        return ans;
    }
};
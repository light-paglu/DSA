#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

// Set to remove duplicates.
// Check in that set: (num - 1) if not there, go for (num + length) till someone not present.
// TC - O(N)
// SC - O(N)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;

        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }

        for (auto num : st) {
            if (st.contains(num - 1)) {
                continue;
            }

            int len = 1;
            while (st.contains(num + len)) {
                len++;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
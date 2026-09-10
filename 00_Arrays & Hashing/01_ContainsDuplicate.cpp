#include <bits/stdc++.h>
using namespace std;

// Contains Duplicate
// Input: nums = [1,2,3,1]
// Output: true
// Explanation: The element 1 occurs at the indices 0 and 3.

// Map of count
// Set size (because it'll have only unique)
// TC - O(N)
// SC - O(N)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto num : nums) {
            st.insert(num);
        }

        return (st.size() != nums.size());
    }
};
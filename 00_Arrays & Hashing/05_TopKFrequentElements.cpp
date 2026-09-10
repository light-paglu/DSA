#include <bits/stdc++.h>
using namespace std;

// Top K Frequent Elements
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Bucket-Sort:
// Max freq can be length of array
// So use index as freq of any number
// TC - O(N)
// SC - O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num]++;
        }

        vector<vector<int>> freq(n + 1);
        for (auto it : mp) {
            freq[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (auto num : freq[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
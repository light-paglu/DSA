#include <bits/stdc++.h>
using namespace std;

// Two Sum
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Map, check remaining is there in map or not.
// TC - O(N)
// SC - O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i];

            if (mp.find(rem) != mp.end()) {
                return {i, mp[rem]};
            }

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
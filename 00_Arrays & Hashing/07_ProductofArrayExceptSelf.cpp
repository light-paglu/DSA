#include <bits/stdc++.h>
using namespace std;

// Product of Array Except Self
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// // 1 2 3 4

// // Pre
// // 1 1 2 6

// // last = 1 4 12 24
// // 24 12 8 6

// 1st - Make prefix array
// 2nd - Directly modify that array using one variable
// TC - O(N)
// SC - O(1) (No extra space, direct modify ans)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int last = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * last;
            last = last * nums[i];
        }

        return ans;
    }
};
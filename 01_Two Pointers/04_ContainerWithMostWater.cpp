#include <bits/stdc++.h>
using namespace std;

// Container With Most Water
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are as [1,8,6,2,5,4,8,3,7]. 
// In this case, the max area of water the container can contain is 49.

// Area for both pointers and move the minimum one.
// TC - O(N)
// SC - O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int l = 0, r = n - 1;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};
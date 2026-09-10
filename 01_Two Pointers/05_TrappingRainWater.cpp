#include <bits/stdc++.h>
using namespace std;

// Trapping Rain Water
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map is as [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped.

// leftMax, rightMax, left & right pointer
// always move smaller from left and right, so that we don't need to worry about other side of max.
// TC - O(N)
// SC - O(1)

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int total = 0, l_max = 0, r_max = 0;
        int l = 0, r = n - 1;

        while (l < r) {
            if (arr[l] <= arr[r]) {
                if (l_max > arr[l]) {
                    total += (l_max - arr[l]);
                } else {
                    l_max = arr[l];
                }
                l++;
            } else {
                if (r_max > arr[r]) {
                    total += (r_max - arr[r]);
                } else {
                    r_max = arr[r];
                }
                r--;
            }
        }

        return total;
    }
};
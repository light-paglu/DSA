#include <bits/stdc++.h>
using namespace std;

// Two Sum II - Input Array Is Sorted
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. 
// Therefore, index1 = 1, index2 = 2. We return [1, 2].

// TC - O(N)
// SC - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int total = numbers[l] + numbers[r];

            if (total > target) {
                r--;
            } else if (total < target) {
                l++;
            } else {
                return {l + 1, r + 1};
            }
        }

        return {-1, -1};
    }
};
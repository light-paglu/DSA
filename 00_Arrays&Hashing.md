 # NC 150: Arrays & Hashing

## Contains Duplicate

**Input:** `nums = [1, 2, 3, 1]`  
**Output:** `true`

**Explanation:** The element `1` occurs at indices `0` and `3`.

- Map of count
- Set size (because it contains only unique elements)
- **Time:** $O(N)$
- **Space:** $O(N)$

```cpp
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
```

## Valid Anagram

**Input:** `s = "anagram", t = "nagaram"`  
**Output:** `true`

Map of count. At the same time, add and remove from the same array or map.

- **Time:** $O(N)$
- **Space:** $O(1)$ (only 26 or 256 characters are fixed)

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n != m)
            return false;

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for (auto it : mp) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
```

## Two Sum

**Input:** `nums = [2, 7, 11, 15], target = 9`  
**Output:** `[0, 1]`

**Explanation:** Because `nums[0] + nums[1] == 9`, we return `[0, 1]`.

Map: check whether the remainder is already in the map.

- **Time:** $O(N)$
- **Space:** $O(N)$

```cpp
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
```

## Group Anagrams

**Input:** `strs = ["eat", "tea", "tan", "ate", "nat", "bat"]`

**Output:** `[["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]`

### If the input contains any characters

- Map
- **Key:** Sorted string
- **Value:** Vector of strings
- **Time:** $O(M * N \log N)$
- **Space:** $O(M * N)$

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;
        for (auto str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
```

## Top K Frequent Elements

**Input:** `nums = [1, 1, 1, 2, 2, 3], k = 2`  
**Output:** `[1, 2]`

### Bucket sort

The maximum frequency can be the length of the array, so use the index as the frequency of any number.

- **Time:** $O(N)$
- **Space:** $O(N)$

```cpp
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
```

## Encode and Decode Strings

**Input:** `strs = ["Hello", "World"]`  
**Output:** `["Hello", "World"]`

Make the string as: `size + # + string`.

**Important:** `substr`, `length`  
**Time and space:** Based on the inputs

```cpp
class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";
        for (auto str : strs) {
            s += to_string(str.size());
            s += '#';
            s += str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }

            int size = stoi(s.substr(i, j - i));

            i = j + 1;
            ans.push_back(s.substr(i, size));

            i = i + size;
        }

        return ans;
    }
};
```

## Product of Array Except Self

**Input:** `nums = [1, 2, 3, 4]`  
**Output:** `[24, 12, 8, 6]`

```text
1 2 3 4

Pre:
1 1 2 6

Last: 1 4 12 24
Result: 24 12 8 6
```

1. Make the prefix array.
2. Directly modify that array using one variable.

- **Time:** $O(N)$
- **Space:** $O(1)$ (no extra space; directly modify `ans`)

```cpp
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
```

## Valid Sudoku

Map of sets for rows, columns, and boxes.

- **Time:** $O(N^2)$
- **Space:** $O(N^2)$ (here, $N$ is just 9)

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row, col;
        map<pair<int, int>, unordered_set<char>> box;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];
                    pair<int, int> p = {i / 3, j / 3};

                    if (row[i].count(ch) || col[j].count(ch) ||
                        box[p].count(ch)) {
                        return false;
                    }

                    row[i].insert(ch);
                    col[j].insert(ch);
                    box[p].insert(ch);
                }
            }
        }

        return true;
    }
};
```

## Longest Consecutive Sequence

**Input:** `nums = [100, 4, 200, 1, 3, 2]`  
**Output:** `4`

**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore, its length is `4`.

Use a set to remove duplicates. Check whether `num - 1` is absent from the set; if it is, check `num + length` until a number is not present.

- **Time:** $O(N)$
- **Space:** $O(N)$

```cpp
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
```
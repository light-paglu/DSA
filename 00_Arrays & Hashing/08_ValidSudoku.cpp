#include <bits/stdc++.h>
using namespace std;

// Valid Sudoku
// Map of set: for row, col and box.
// TC - O(N²)
// SC - O(N²) (but here N is just 9)

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
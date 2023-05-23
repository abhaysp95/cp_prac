// https://leetcode.com/problems/valid-sudoku/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint8_t nums[10];  // don't use int here (see bottom)
        memset(nums, 1, sizeof(nums));

        // check cols
        for (size_t i = 0; i < 9; i++) {
            memset(nums, 1, sizeof(nums));
            for (size_t j = 0; j < 9; j++) {
                int num = 0;
                if (board[j][i] == '.') continue;
                num = board[j][i] - '0';
                if (nums[num] - 1 < 0) {
                    return false;
                }
                nums[num]--;
            }
        }

        // check row
        for (size_t i = 0; i < 9; i++) {
            memset(nums, 1, sizeof(nums));
            for (size_t j = 0; j < 9; j++) {
                int num = 0;
                if (board[i][j] == '.') continue;
                num = board[i][j] - '0';
                if (nums[num] - 1 < 0) {
                    return false;
                }
                nums[num]--;
            }
        }

        // check 3x3

        for (size_t x = 0; x < 9; x += 3) {
            for (size_t y = 0; y < 9; y += 3) {
                memset(nums, 1, sizeof(nums));
                for (size_t i = x; i < x + 3; i++) {
                    for (size_t j = y; j < y + 3; j++) {
                        int num = 0;
                        if (board[i][j] == '.') continue;
                        num = board[i][j] - '0';
                        cout << num << endl;
                        if (nums[num] == 0) {
                            return false;
                        }
                        nums[num]--;
                    }
                }
                cout << '\n';
                for (size_t i = 0; i < 10; i++) {
                    cout << nums[i] << " ";
                }
                cout << "\n******" << endl;
            }
        }

        return true;
    }
};

/**
 * If you have int or any other datatype which has size of more than 1 byte and
 * you want each block to have value != 0, then memset is not a recommended
 * approach.
 * In this case, I wanted to initialize array with 1. If I have 'int' datatype what will happen is:
 * memset(nums, 1, sizeof(nums));
 * for each block: 00000001 00000001 00000001 00000001 =>  16843009
 * +>>> i = 0
 * +>>> pos = 0
 * +>>> for _ in range(0, 4):
 * +...    i |= (1 << pos)
 * +...    pos += 8
 * +...
 * +>>> i
 * 16843009
 *
 * thus, I used the datatype of 1 byte
 *
 * Furthermore, this approach would only support the number that can fit in 1 byte and not more
 */

// https://leetcode.com/problems/pascals-triangle
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int en(int row, int col) {
        int &m = memo[row][col];
        if (m != -1) {
            return m;
        }

        return (m = memo[row - 1][col - 1] + memo[row - 1][col]);
    }

    vector<vector<int>> generate(int numRows) {
        memo.resize(numRows);
        for (int i = 0; i < numRows; i++) {
            auto &row = memo[i];
            row.resize(i + 1, -1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++) {
                memo[i][j] = en(i, j);
            }
        }
        return memo;
    }

private:
    vector<vector<int>> memo;
};

int main() {
    Solution sol;
    for (const auto &row: sol.generate(10)) {
        for (const auto &en: row) {
            cout << en << ' ';
        }
        cout << endl;
    }
}
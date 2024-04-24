#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int c(int m, int n) {
        if (m < 0 || n < 0 || m >= boundM || n >= boundN) {
            return 0;
        }

        if (m == 0 && n == 0) {
            return 1;
        }

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        return (memo[m][n] = c(m-1, n) + c(m, n-1));
    }

    int uniquePaths(int m, int n) {
        boundM = m;
        boundN = n;

        memo.resize(m, vector<int>(n, -1));
        return c(m-1, n-1);
    }
private:
    vector<vector<int>> memo;
    int boundM, boundN;
};

int main() {
    Solution sol;
    cout << sol.uniquePaths(3, 7) << endl;
}
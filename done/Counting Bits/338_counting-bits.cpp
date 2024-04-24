#include <bits/stdc++.h>
using namespace std;

// learning from https://leetcode.com/problems/counting-bits/solutions/270693/intermediate-process-solution-for-the-most-voted-solution-i-e-no-simplification-trick-hidden/
class Solution {
public:
    int c(int n) {
        int& memoEntry = memo[n];
        if (memoEntry != -1) {
            return memoEntry;
        }

        // if a number is even, it has a zero as a last bit.
        // therefore, the last bit doesn't matter,
        // and you can simply return the amount of 1s
        // in the number shifted once (divided by 2)
        //
        // if a number is odd, it has a one as a last bit.
        // therefore, you can simply return the amount of 1s
        // in the number shifted once (divided by 2), plus 1
        // for the last bit.
        return (memoEntry = c(n >> 1) + n % 2);
    }

    vector<int> countBits(int n) {
        memo.resize(n + 1, -1);
        memo[0] = 0;
        for (int i = 1; i <= n; i++) {
            memo[i] = c(i);
        }
        return memo;
    }

private:
    vector<int> memo;
};

int main() {
    Solution sol;
    for (int b: sol.countBits(300)) {
        cout << b << ' ';
    }
    cout << endl;
}
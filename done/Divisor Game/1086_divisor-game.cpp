// https://leetcode.com/problems/divisor-game
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool d(int n) {
        short& m = memo[n];
        if (m != -1) {
            return m;
        }

        for (int x = 1; x < n; x++) {
            if (n % x == 0) {
                return (m = !d(n-x));
            }
        }

        return (m = false);
    }

    bool divisorGame(int n) {
        memo.resize(max(n,2)+1, -1);
        memo[2] = 1;
        return d(n);
    }
private:
    vector<short> memo;
};

int main() {
    Solution sol;
    cout << boolalpha << sol.divisorGame(4);
}
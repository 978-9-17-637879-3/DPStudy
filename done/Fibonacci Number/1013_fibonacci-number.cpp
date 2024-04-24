// https://leetcode.com/problems/fibonacci-number
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n) {
        int& m = memo[n];
        if (m != -1) {
            return m;
        }

        return (m = f(n-1) + f(n-2));
    }

    int fib(int n) {
        memo.resize(max(n+1, 2), -1);
        memo[0] = 0;
        memo[1] = 1;
        return f(n);
    }
private:
    vector<int> memo;
};

int main() {
    Solution sol;
    cout << sol.fib(7) << endl;
}
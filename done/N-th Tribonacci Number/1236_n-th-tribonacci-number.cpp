#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t(int n) {
        int& m = memo[n];

        if (m != -1) {
            return m;
        }

        return (m = t(n-1) + t(n-2) + t(n-3));
    }

    int tribonacci(int n) {
        memo.resize(max(n+1,3), -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return t(n);
    }

private:
    vector<int> memo;
};

int main() {
    Solution sol;
    cout << sol.tribonacci(25) << endl;
}
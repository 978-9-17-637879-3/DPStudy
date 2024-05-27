#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int checkRecord(int n) {
    static constexpr long base = 1000000007L;

    // first dimension is number of As in the string (0 or 1),
    // second dimension is number of Ls at the end of the string (0, 1, or 2)
    // base case for n = 1 -> P = [0][0] = 1, L = [0][1] = 1, A = [1,0] = 1
    std::array<std::array<long, 3>, 2> memo = {{{{1, 1, 0}}, {{1, 0, 0}}}};

    for (int i = 2; i <= n; ++i) {
      long n0A0L = (memo[0][0] + memo[0][1] + memo[0][2]) % base;// add P

      memo[0][2] = memo[0][1];// add L
      memo[0][1] = memo[0][0];// add L

      memo[0][0] = n0A0L;

      long n1A0L = (n0A0L + memo[1][0] + memo[1][1] + memo[1][2]) % base;// add P or A

      memo[1][2] = memo[1][1];// add L
      memo[1][1] = memo[1][0];// add L

      memo[1][0] = n1A0L;
    }

    return static_cast<int>((memo[0][0] + memo[0][1] + memo[0][2] + memo[1][0] +
                             memo[1][1] + memo[1][2]) %
                            base);
  }
};

int main() {
  Solution solution;
  for (int i = 1; i <= 10000; ++i) {
    cout << i << " " << solution.checkRecord(i) << '\n';
  }
  return 0;
}
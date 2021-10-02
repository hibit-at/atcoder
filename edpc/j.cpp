#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

const ll mod = 1e9 + 7;

void print_vector_vector(vector<vector<double>> vv) {
  for (vector<double> v : vv) {
    for (double i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

int n;
int how1 = 0;
int how2 = 0;
int how3 = 0;
vector<vector<vector<double>>> dp;
vector<vector<vector<bool>>> flag;

double f(int c1, int c2, int c3) {
  if (flag[c1][c2][c3])
    return dp[c1][c2][c3];
  flag[c1][c2][c3] = 1;
  double fans = 1;
  if (c1 > 0) {
    fans += (double)c1 / n * f(c1 - 1, c2, c3);
  }
  if (c2 > 0) {
    fans += (double)c2 / n * f(c1 + 1, c2 - 1, c3);
  }
  if (c3 > 0) {
    fans += (double)c3 / n * f(c1, c2 + 1, c3 - 1);
  }
  fans *= (double)n / (c1 + c2 + c3);
  return dp[c1][c2][c3] = fans;
}

int main() {
  cin >> n;
  rep(i, n) {
    int a;
    cin >> a;
    if (a == 1) {
      how1++;
    }
    if (a == 2) {
      how2++;
    }
    if (a == 3) {
      how3++;
    }
  }
  dp.resize(n + 1);
  rep(i, n + 1) { dp[i].resize(n + 1, vector<double>(n + 1, 0)); }
  flag.resize(n + 1);
  rep(i, n + 1) { flag[i].resize(n + 1, vector<bool>(n + 1, false)); }
  flag[0][0][0] = true;
  cout << setprecision(20) << f(how1, how2, how3) << endl;
}
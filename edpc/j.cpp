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

double dfs(int d1, int d2, int d3) {
  cout << "now " << d1 << d2 << d3 << endl;
  if (d1 < 0) {
    return 0;
  }
  if (d2 < 0) {
    return 0;
  }
  if (d3 < 0) {
    return 0;
  }
  if(d1 == 0 && d2 == 0 && d3 == 0){
    cout << "initial state is 0" << endl;
    return 0;
  }
  double any = d1 + d2 + d3;
  double ans = 1;
  if (d1 > 0) {
    ans += dfs(d1 - 1, d2, d3) * (d1 - 1) / n;
  }
  if (d1 <= how1 && d2 > 0) {
    ans += dfs(d1 + 1, d2 - 1, d3) * (d2 - 1) / n;
  }
  if (d2 <= how2 && d3 > 0) {
    ans += dfs(d1, d2 + 1, d3 - 1) * (d3 - 1) / n;
  }
  ans /= (1-any/n);
  cout << d1 << d2 << d3 <<  " ans is " << ans << endl;
  return dp[d1][d2][d3] = ans;
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
  dp.resize(how1 + 1);
  rep(i, how1 + 1) { dp[i].resize(how2 + 1, vector<double>(how3 + 1, 0)); }
  dp[0][0][0] = 0;
  cout << dfs(how1, how2, how3) << endl;
}
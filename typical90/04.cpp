#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> table(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) { cin >> table[i][j]; }
  }
  vector<int> h_sum(h), w_sum(w);
  rep(i, h) {
    rep(j, w) { h_sum[i] += table[i][j]; }
  }
  rep(j, w) {
    rep(i, h) { w_sum[j] += table[i][j]; }
  }
  // print_vector(h_sum);
  // print_vector(w_sum);
  rep(i, h) {
    rep(j, w) { cout << h_sum[i] + w_sum[j] - table[i][j] << " "; }
    cout << endl;
  }
}
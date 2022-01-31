#include <algorithm>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main(void) {
  int n, m, l;
  cin >> n >> m >> l;
  vector<vector<int>> d(n, vector<int>(m));
  vector<vector<int>> p(l, vector<int>(m));
  rep(i, n) {
    rep(j, m) { cin >> d[i][j]; }
  }
  rep(i, l) {
    rep(j, m) { cin >> p[i][j]; }
  }
  rep(i, l - 1) {
    vector<int> dif(m);
    rep(j, m) { dif[j] = p[i + 1][j] - p[i][j]; }
    rep(j, n) {
      if (dif == d[j]) {
        cout << j + 1 << endl;
      }
    }
  }
}
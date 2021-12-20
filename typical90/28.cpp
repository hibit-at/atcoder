#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int grid_size = 1010;
  vector<vector<int>> imos(grid_size, vector<int>(grid_size, 0));
  vector<vector<int>> sum(grid_size, vector<int>(grid_size, 0));
  rep(i, n) {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    imos[lx][ly] += 1;
    imos[lx][ry] -= 1;
    imos[rx][ly] -= 1;
    imos[rx][ry] += 1;
  }
  rep(i, grid_size) {
    rep(j, grid_size) {
      sum[i][j] += imos[i][j];
      if (j > 0) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  rep(j, grid_size) {
    rep(i, grid_size) {
      if (i > 0) {
        sum[i][j] += sum[i - 1][j];
      }
    }
  }
  vector<int> buc(n + 1, 0);
  rep(i, grid_size) {
    rep(j, grid_size) { buc[sum[i][j]] += 1; }
  }
  rep1(i, n) { cout << buc[i] << endl; }
}
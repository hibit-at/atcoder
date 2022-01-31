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

void print_set(set<int> s) {
  for (int i : s) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n), b(n);
  set<int> h_set, w_set;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    a[i] = x;
    b[i] = y;
    h_set.insert(x);
    w_set.insert(y);
  }
  vector<int> h_vec(all(h_set)), w_vec(all(w_set));
  rep(i, n) {
    cout << lower_bound(all(h_vec), a[i]) - h_vec.begin() + 1;
    cout << " ";
    cout << lower_bound(all(w_vec), b[i]) - w_vec.begin() + 1;
    cout << endl;
  }
}
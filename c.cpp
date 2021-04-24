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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  bool isFlip = false;
  vector<int> order(2 * n);
  rep(i, 2 * n) { order[i] = i; }
  rep(i, q) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      a--;
      b--;
      if (isFlip) {
        a = (a + n) % (2 * n);
        b = (b + n) % (2 * n);
      }
      swap(order[a], order[b]);
    }
    if (t == 2) {
      isFlip = !isFlip;
    }
    // print_vector(order);
  }
  rep(i, 2 * n) {
    int pos = i;
    if (isFlip) {
      pos = (pos + n) % (2 * n);
    }
    cout << s[order[pos]];
  }
  cout << endl;
}
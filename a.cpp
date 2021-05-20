#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
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

void output(int a) {
  int bitnum = __builtin_popcount(a);
  cout << bitnum;
  rep(i, 8) {
    if (a >> i & 1) {
      cout << " " << i + 1;
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n), buc(200, 0);
  rep(i, n) cin >> a[i];
  rep(i, 1 << min(n, 8)) {
    ll check = 0;
    rep(j, 8) {
      if (i >> j & 1) {
        check += a[j];
        check %= 200;
      }
    }
    if (buc[check] == 0) {
      buc[check] = i;
    } else {
      cout << "Yes" << endl;
      output(buc[check]);
      output(i);
      return 0;
    }
  }
  cout << "No" << endl;
}
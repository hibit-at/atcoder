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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

int toInt(char c) {
  int ans = c - '0';
  return ans;
}

int main() {
  string s;
  cin >> s;
  bool isFail = true;
  rep(i, 3) {
    if (s[i] != s[i + 1]) {
      isFail = false;
    }
  }
  if (isFail) {
    cout << "Weak" << endl;
    return 0;
  }
  isFail = true;
  rep(i, 3) {
    if ((toInt(s[i]) + 1) % 10 != toInt(s[i + 1])) {
      isFail = false;
    }
  }
  if (isFail) {
    cout << "Weak" << endl;
  } else {
    cout << "Strong" << endl;
  }
}
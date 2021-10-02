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

void YesNo(bool b) {
  if (b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  int n, x;
  cin >> n >> x;
  int tmp = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if (i % 2 == 1) {
      a--;
    }
    tmp += a;
  }
  YesNo(x >= tmp);
}
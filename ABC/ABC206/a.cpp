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

int main() {
  int n;
  cin >> n;
  int tax = n * 108 / 100;
  if (tax < 206) {
    cout << "Yay!" << endl;
  } else if (tax == 206) {
    cout << "so-so" << endl;
  } else {
    cout << ":(" << endl;
  }
}
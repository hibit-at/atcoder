#include <algorithm>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
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

const ll inf = 9e18;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  ll n, k;
  cin >> n >> k;
  rep(q, k) {
    vector<int> eight(0);
    while (n > 0) {
      eight.push_back(n % 10);
      n /= 10;
    }
    reverse(all(eight));
    ll tmp = 0;
    for (int e : eight) {
      tmp *= 8;
      tmp += e;
    }
    vector<int> nine(0);
    while (tmp > 0) {
      nine.push_back(tmp % 9);
      tmp /= 9;
    }
    reverse(all(nine));
    n = 0;
    for (int ni : nine) {
      n *= 10;
      if (ni == 8) {
        ni = 5;
      }
      n += ni;
    }
  }
  cout << n << endl;
}
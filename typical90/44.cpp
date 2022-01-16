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

int n, q;

// int submod(int a,int b,int mod){
//   a -= b;
//   a %= mod;
//   a += mod;
//   a %= mod;
//   return a;
// }

void submod(int &a, int b, int mod) {
  a -= b;
  a %= mod;
  a += mod;
  a %= mod;
  return;
}

int main() {
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int shift = 0;
  rep(i, q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      y--;
      submod(x, shift, n);
      submod(y, shift, n);
      swap(a[x], a[y]);
    }
    if (t == 2) {
      shift++;
    }
    if (t == 3) {
      x--;
      submod(x, shift, n);
      cout << a[x] << endl;
    }
  }
}
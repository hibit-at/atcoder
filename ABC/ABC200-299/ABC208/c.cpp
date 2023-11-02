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

const ll mod = 1e9 + 7;

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, n) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(all(b));
  // print_vector(b);
  rep(i, n) {
    ll ans = k / n;
    int id = a[i];
    int ng = -1;
    int ok = n + 1;
    while (abs(ng - ok) > 1) {
      int mid = (ng + ok) / 2;
      if (b[mid] >= id) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    if(ok < k % n){
      ans ++;
    }
    cout << ans << endl;
  }
}
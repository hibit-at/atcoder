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

const ll mod = 1e9+7;

vector<ll> make_fact(int limit) {
  vector<ll> ans(limit, 1);
  rep(i, limit - 1) {
    ans[i + 1] = ans[i] * (i + 1);
    ans[i + 1] %= mod;
  }
  return ans;
}

void print_vector_ll(vector<ll> v) {
  for (ll i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int p;
  cin >> p;
  auto fact = make_fact(12);
  reverse(all(fact));
  int ans = 0;
  int cnt = 0;
  while(p > 0){
    ans += p/fact[cnt];
    p %= fact[cnt];
    cnt ++;
  }
  cout << ans << endl;
}
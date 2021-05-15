#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
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

int main() {
  ll k, n, m;
  cin >> k >> n >> m;
  vector<ll> lefts(k);
  vector<ll> head(k);
  vector<bool> isZero(k, false);
  rep(i, k) {
    ll b;
    cin >> b;
    ll up = b * m;
    ll left = up % n;
    cout << left << endl;
    if (left > n / 2) {
      left -= n;
    }
    cout << left << endl;
    lefts[i] = left;
    head[i] = up / n;
    if (b == 0) {
      isZero[i] = true;
    }
  }
  ll check = 0;
  rep(i, k) { check += lefts[i]; }
  if (check == 0) {
    rep(i, k) {
      if (isZero[i]) {
        cout << 0;
      } else {
        if (lefts[i] >= 0) {
          cout << head[i];
        } else {
          cout << head[i] + 1;
        }
      }
      if (i < k - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  } else {
    ll count_num = check / n;
    count_num = (count_num + n) % n;
    rep(i, k) {
      if (isZero[i]) {
        cout << 0;
      } else {
        if (count_num > 0) {
          cout << head[i] + 1;
          count_num--;
        } else {
          cout << head[i];
        }
      }
      if (i < k - 1) {
        cout << " ";
      } else {
        cout << endl;
      }
    }
  }
}
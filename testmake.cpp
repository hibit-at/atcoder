#include <string>
#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;
using PIL = pair<int, ll>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Cost_Graph = vector<vector<PIL>>;

template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T> bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
#define REP(i, n) for (int i = 0; i < int(n); i++)
#define ROUNDUP(a, b) ((a + b - 1) / b)
#define YESNO(T) cout << (T ? "YES" : "NO") << endl
#define yesno(T) cout << (T ? "yes" : "no") << endl
#define YesNo(T) cout << (T ? "Yes" : "No") << endl

const int INFint = 1 << 30;
const ll INFLL = 1LL << 60;
const ll MOD = 1000000007LL;
const double pi = 3.14159265358979;

string main_test(ll n) {
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout << fixed << setprecision(15);

  // ll n;
  // cin >> n;

  ll left = (n + 2) / 2, right = n;
  bool winner = false;
  // cout << (winner ? "win" : "lose") << " " << left << " " << right << endl;
  while (left > 1) {
    if (winner) {
      right = left - 1;
      left = (right + 2) / 2;
    } else {
      right = left - 1;
      left = (right + 1) / 2;
    }

    winner = !winner;

    // cout << (winner ? "win" : "lose") << " " << left << " " << right << endl;
  }

  if (winner) {
    return "Takahashi";
  } else {
    return "Aoki";
  }
}

string main_mine(ll n) {
  // ll n;
  // cin >> n;
  if (n == 1) {
    return "Aoki";
  }
  bool isOK = true;
  ll low_limit = n / 2 + 1;
  while (low_limit > 3) {
    low_limit /= 2;
    isOK = !isOK;
    // cout << low_limit << endl;
  }
  if (low_limit == 3) {
    return "Takahashi";
  }
  if (low_limit == 2) {
    if (isOK) {
      return "Takahashi";
    } else {
      return "Aoki";
    }
  }
  return "None";
}

int main() {
  for (int i = 1; i <= 32; i++) {
    cout << i << ":" << main_test(i) << "," << main_mine(i) << endl;
  }
}
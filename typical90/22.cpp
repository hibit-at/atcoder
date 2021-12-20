#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll gcd_of_abc = gcd(a, gcd(b, c));
  a /= gcd_of_abc;
  b /= gcd_of_abc;
  c /= gcd_of_abc;
  cout << (a - 1) + (b - 1) + (c - 1) << endl;
}
#include <algorithm>
#include <iostream>
#include <limits.h>
#include <iomanip>
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
  double a,b;
  cin >> a >> b;
  cout << setprecision(20) << (a-b)/3+b << endl;
}
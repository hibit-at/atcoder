#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  if (h == 1) {
    cout << w << endl;
  } else if (w == 1) {
    cout << h << endl;
  } else {
    cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;
  }
}
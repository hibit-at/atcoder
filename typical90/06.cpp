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

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  string::iterator start = s.begin();
  string::iterator end = s.end() - (k - 1);
  rep(i, k) {
    cout << *min_element(start, end + i);
    start = min_element(start, end + i) + 1;
  }
  cout << endl;
}
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
  cin >> n >> k;
  priority_queue<pair<int, int>> q;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    q.push({b, a});
  }
  ll ans = 0;
  while (k > 0) {
    pair<int, int> now = q.top();
    q.pop();
    ans += now.first;
    q.push({now.second - now.first, -1});
    k--;
  }
  cout << ans << endl;
}
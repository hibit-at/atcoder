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
const ll inf = 1e18;

void print_priority_queue(priority_queue<int> q) {
  while (q.size() > 0) {
    int now = q.top();
    q.pop();
    cout << now << " ";
  }
  cout << endl;
}

int main() {
  int Q;
  cin >> Q;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  ll shift = 0;
  rep(_, Q) {
    int p;
    cin >> p;
    if (p == 1) {
      ll x;
      cin >> x;
      q.push(x - shift);
    }
    if (p == 2) {
      ll x;
      cin >> x;
      shift += x;
    }
    if (p == 3) {
      ll now = q.top();
      q.pop();
      cout << now + shift << endl;
    }
  }
}
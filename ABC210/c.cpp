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

void print_map(map<int, int> mp) {
  for (auto p : mp) {
    cout << "key : " << p.first << ", value : " << p.second << endl;
  }
}

void print_queue(queue<int> q) {
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    cout << now << " ";
  }
  cout << endl;
}

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  map<int, int> mp;
  int ans = 0;
  int tmp = 0;
  rep(i, k) {
    int c;
    cin >> c;
    q.push(c);
    mp[c]++;
    if (mp[c] == 1) {
      tmp++;
    }
  }
  ans = tmp;
  // print_queue(q);
  // print_map(mp);
  // cout << tmp << endl;
  rep(i, n - k) {
    int c;
    cin >> c;
    q.push(c);
    mp[c]++;
    if (mp[c] == 1) {
      tmp++;
    }
    int rem = q.front();
    q.pop();
    mp[rem]--;
    if (mp[rem] == 0) {
      tmp--;
    }
    // print_queue(q);
    // print_map(mp);
    // cout << tmp << endl;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
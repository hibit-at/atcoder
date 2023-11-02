#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
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

int n, m, q;
vector<pair<int, int>> vw;
vector<pair<int, int>> box_index;
vector<int> box;
vector<int> match;

void solve(int l, int r) {
  vector<bool> used_box(m, false);
  for (int i = l; i <= r; i++){
    cout << match[i] << endl;
    used_box[match[i]] = true;
  }
  vector<bool> used_item(n, false);
  int ans = 0;
  rep(i, m) {
    if (used_box[i])
      continue;
    // cout << "selected box is " << x[i] << endl;
    rep(j, n) {
      if (used_item[j])
        continue;
      int v = vw[j].first;
      int w = vw[j].second;
      if (w <= box[i]) {
        ans += v;
        // cout << "selected item is v:" << v << " w:" << w << endl;
        used_item[j] = true;
        break;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> n >> m >> q;
  vw.resize(n);
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    vw[i] = make_pair(v, w);
  }
  sort(all(vw));
  reverse(all(vw));
  box_index.resize(m);
  box.resize(m);
  match.resize(m);
  rep(i, m) {
    int x;
    cin >> x;
    box_index[i] = make_pair(x, i);
  }
  sort(all(box_index));
  rep(i, m) {
    box[i] = box_index[i].first;
    match[i] = box_index[i].second;
  }
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    solve(l, r);
  }
}
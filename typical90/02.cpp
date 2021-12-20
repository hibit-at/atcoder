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

int main() {
  int n;
  cin >> n;
  vector<string> ans;
  rep(i, 1 << n) {
    int bit_count = 0;
    rep(j, n) {
      bool bit = i >> j & 1;
      if (bit) {
        bit_count++;
      } else {
        bit_count--;
      }
      if (bit_count < 0) {
        break;
      }
    }
    if (bit_count == 0) {
      string tmp = "";
      rep(j, n) {
        bool bit = i >> j & 1;
        if (bit) {
          tmp.push_back('(');
        } else {
          tmp.push_back(')');
        }
      }
      ans.push_back(tmp);
    }
  }
  sort(all(ans));
  for (string a : ans) {
    cout << a << endl;
  }
}
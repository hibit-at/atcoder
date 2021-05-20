#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
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
  string s, t;
  cin >> n >> s >> t;
  rep(i, n) {
    if (s[i] == '1' && t[i] == '1') {
      continue;
    } else {
      cout << s[i];
    }
  }
  cout << endl;
  rep(i, n) {
    if (s[i] == '1' && t[i] == '1') {
      continue;
    } else {
      cout << t[i];
    }
  }
}
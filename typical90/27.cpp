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
  map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    if (mp[s] > 0) {
      continue;
    } else {
      cout << i + 1 << endl;
      mp[s]++;
    }
  }
}
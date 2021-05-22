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
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

char process(char c) {
  if (c == '6') {
    return '9';
  }
  if (c == '9') {
    return '6';
  }
  return c;
}

int main() {
  string s;
  cin >> s;
  reverse(all(s));
  for (char c : s) {
    cout << process(c);
  }
  cout << endl;
}
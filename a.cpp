#include <algorithm>
#include <deque>
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
  string s;
  cin >> s;
  bool isReverse = false;
  deque<char> q;
  int n = s.size();
  rep(i, n) {
    char now = s[i];
    if (now == 'R') {
      isReverse = !isReverse;
    } else {
      // 空qなら無条件に挿入
      if (q.size() == 0){
        q.push_back(now);
        continue;
      }
      if (isReverse) {
        char back_check = q.back();
        if (back_check != now) {
          q.push_back(now);
        } else {
          q.pop_back();
        }
      } else {
        char front_check = q.front();
        if (front_check != now) {
          q.push_front(now);
        } else {
          q.pop_front();
        }
      }
    }
  }
  deque<char> t = q;
  if (isReverse) {
    while (t.size() > 0) {
      char now = t.front();
      t.pop_front();
      cout << now;
    }
  } else {
    while (t.size() > 0){
      char now = t.back();
      t.pop_back();
      cout << now;
    }
  }
  cout << endl;
}
#include <algorithm>
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
  bool check_zero = false;
  //元となるキューpと、尺取り中の列q
  queue<int> p, q;
  rep(i, n) {
    int s;
    cin >> s;
    if (s == 0) { //この問題では0を含む場合のコーナーケースが必要
      check_zero = true;
    }
    p.push(s);
  }
  if (check_zero) {
    cout << p.size() << endl;
    return 0;
  }
  int ans = 0;
  //基準となる処理（尺取り中の列の積は？）
  ll criterion = 1;
  while (p.size() > 0) {
    int now = p.front();
    p.pop();
    criterion *= now;
    q.push(now);
    cout << "p : ";
    print_queue(p);
    cout << "q : ";
    print_queue(q);
    cout << "criterion : " << criterion << endl;
    //次の数を入れていい状態になるまでqを整理
    while (criterion > k && q.size() > 0) {
      int front = q.front();
      q.pop();
      criterion /= front;
      cout << "p : ";
      print_queue(p);
      cout << "q : ";
      print_queue(q);
      ans = max(ans, int(q.size()));
      cout << "criterion : " << criterion << endl;
    }
    ans = max(ans, int(q.size()));
  }
  cout << ans << endl;
}
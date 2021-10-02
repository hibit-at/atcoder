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

void clear_queue(queue<int> &q) {
  queue<int> empty;
  swap(q, empty);
}

int main() {
  int n;
  cin >> n;
  //元となるキューpと、尺取り中の列q
  queue<int> p, q;
  rep(i, n) {
    int a;
    cin >> a;
    p.push(a);
  }
  p.push(0); //この問題では末尾に番兵を入れる
  ll ans = 0;
  //この問題では基準処理に新たな変数は必要ない
  while (p.size() > 0) {
    int now = p.front();
    p.pop();
    //次の数を入れていい状態になるまでqを整理
    if (q.size() > 0) {
      if (q.back() >= now) {
        ll len = q.size();
        ans += len * (len + 1) / 2;
        while (q.size() > 0) {
          q.pop();
        }
      }
    }
    q.push(now);
  }
  cout << ans << endl;
}
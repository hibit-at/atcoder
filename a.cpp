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

int main() {
  int n;
  cin >> n;
  //元となるキューpと、尺取り中の列q
  queue<int> p,q;
  rep(i,n){
    int a;
    cin >> a;
    p.push(a);
  }
  int ans = 0;
  //基準となる処理（既にその数が含まれているか？）
  vector<bool> criterion(1e5 + 1);
  while(p.size()>0){
    int now = p.front();
    p.pop();
    //次の数を入れていい状態になるまでqを整理
    while (criterion[now]) {
      int front = q.front();
      q.pop();
      criterion[front] = false;
    }
    q.push(now);
    criterion[now] = true;
    ans = max(ans, (int)q.size());
  }
  cout << ans << endl;
}
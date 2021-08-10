#include <algorithm>
#include <iomanip>
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

const int inf = 2e9;

void chmin(int &a, int b) { a = min(a, b); }

vector<int> bfs(int n, vector<vector<int>> to, int start) {
  vector<int> dist(n + 1, inf);
  queue<int> q;
  dist[start] = 0;
  q.push(start);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (dist[next] <= dist[now] + 1) {
        continue;
      }
      dist[next] = dist[now] + 1;
      q.push(next);
    }
  }
  return dist;
}

void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void print_to(vector<vector<int>> to) {
  int n = to.size();
  rep(i, n) {
    cout << "from " << i << " : to ";
    for (int next : to[i]) {
      cout << next << ",";
    }
    cout << endl;
  }
}


int main() {
  int n,k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<vector<int>> to(n);
  rep(i,n){
    rep(step,k){
      int next = i + step + 1;
      if(next >= n){
        break;
      }
      to[i].push_back(next);
    }
  }
  vector<int> dp(n,inf);
  queue<int> q;
  q.push(0);
  dp[0] = 0;
  while(q.size()>0){
    int now = q.front();
    q.pop();
    for(int next : to[now]){
      int add_h = abs(h[next] - h[now]);
      if(dp[next] <= dp[now] + add_h){
        continue;
      }
      dp[next] = dp[now] + add_h;
      q.push(next);
    }
  }
  cout << dp[n-1] << endl;
}
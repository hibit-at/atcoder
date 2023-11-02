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

const ll mod = 1e9 + 7;
const ll inf = 1e18;

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

void print_vector_ll(vector<ll> v) {
  for (ll i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n + 1, vector<int>(0));
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<ll> dist(n + 1, inf);
  dist[1] = 0;
  queue<int> q;
  q.push(1);
  // print_to(to);
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for (int next : to[now]) {
      if (dist[now] + 1 < dist[next]) {
        dist[next] = dist[now] + 1;
        q.push(next);
      }
    }
  }
  // print_vector_ll(dist);
  q.push(1);
  vector<ll> way(n + 1, 0);
  way[1] = 1;
  while (q.size() > 0) {
    int now = q.front();
    q.pop();
    for(int next : to[now]){
      if(dist[next] > dist[now]){
        if(way[next] == 0){
          q.push(next);
        }
        way[next] += way[now];
        way[next] %= mod;
      }
    }
  }
  // print_vector_ll(way);
  cout << way[n] << endl;
}
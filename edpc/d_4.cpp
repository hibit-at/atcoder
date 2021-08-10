#include <algorithm>
#include <fstream>
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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
typedef long long ll;

class item {
public:
  int weight;
  int value;
  item() {}
  item(int weight, int value) {
    this->weight = weight;
    this->value = value;
  }
};

class edge {
public:
  int next_kind;
  int next_weight;
  ll add_value;
  pair<int,int> next;
  edge() {}
  edge(int next_kind, int next_weight, ll add_value) {
    this->next_kind = next_kind;
    this->next_weight = next_weight;
    this->add_value = add_value;
    this->next = make_pair(next_kind, next_weight);
  }
};

void chmax(ll &a, ll b) { a = max(a, b); }

void print_vector_vector_ll(vector<vector<ll>> vv) {
  for (vector<ll> v : vv) {
    for (ll i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

int n, W;

int main() {
  cin >> n >> W;
  vector<item> items(n);
  rep(i, n) {
    int w, v;
    cin >> w >> v;
    items[i] = item(w, v);
  }
  vector<vector<vector<edge>>> to(n+1,vector<vector<edge>>(W+1,vector<edge>(0)));
  rep(kind,n+1){
    rep(weight,W+1){
      if(kind < n){
        to[kind][weight].push_back(edge(kind+1,weight,0));
        int next_weight = weight + items[kind].weight;
        ll add_val = items[kind].value;
        if(next_weight <= W){
          to[kind][weight].push_back(edge(kind+1,next_weight,add_val));
        }
      }
    }
  }
  vector<vector<ll>> value(n + 1, vector<ll>(W + 1, -1));
  pair<int, int> start = make_pair(0, 0);
  value[0][0] = 0;
  queue<pair<int, int>> q;
  q.push(start);
  ll ans = 0;
  while (q.size() > 0) {
    pair<int, int> now = q.front();
    q.pop();
    int kind = now.first;
    int weight = now.second;
    ll now_val = value[kind][weight];
    chmax(ans, now_val);
    // cout << kind << "," << weight << " val " << now_val << endl;
    for(edge e : to[kind][weight]){
      int nk = e.next_kind;
      int nw = e.next_weight;
      int add_val = e.add_value;
      if(now_val + add_val <= value[nk][nw]){
        continue;
      }
      value[nk][nw] = now_val + add_val;
      q.push(e.next);
    }
  }
  print_vector_vector_ll(value);
  cout << ans << endl;
}
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

void print_vector_vector(vector<vector<int>> vv) {
  for (vector<int> v : vv) {
    for (int i : v) {
      cout << i << ",";
    }
    cout << endl;
  }
}

void print_vector_pair(vector<pair<ll, ll>> v) {
  for (pair<ll, ll> i : v) {
    cout << "(" << i.first << "," << i.second << ")"
         << " ";
  }
  cout << endl;
}

int main() {
  int n,m;
  cin >> n >> m;
  vector<vector<int>> to(n+1,vector<int>(n+1,0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    to[a].push_back(b);
  }
  const int inf = 1e9;
  vector<vector<int>> dists(n+1,vector<int>(n+1,inf));
  rep1(i,n){
    queue<int> q;
    q.push(i);
    dists[i][i] = 0;
    while(q.size()>0){
      int now = q.front();
      q.pop();
      for(int next : to[now]){
        if(dists[i][next] <= dists[i][now]+1){
          continue;
        }
        dists[i][next] = dists[i][now] + 1;
        q.push(next);
      }
    }
  }
  // print_vector_vector(dists);
  int ans = 0;
  rep1(i,n){
    rep1(j,n){
      if(dists[i][j] != inf){
        ans ++;
      }
    }
  }
  cout << ans << endl;
}
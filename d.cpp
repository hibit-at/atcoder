#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <stack>
#include <set>
#include <string>
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

int main() {
  set<pair<int,int>> s;
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  vector<set<int>> to(n+1);
  rep(i,n/2){
    int first = a[i];
    int second = a[n-1-i];
    cout << first << "-" << second << endl;
    if(first == second){
      continue;
    }
    cout << "add" << first << "," << second << endl;
    to[first].insert(second);
    to[second].insert(first);
  }
  vector<bool> seen(2e5+1,false);
  ll ans = 0;
  for(int start : a){
    if(seen[start]){
      continue;
    }
    cout << start << endl;
    stack<int> q;
    int cnt = 0;
    q.push(start);
    while(q.size()>0){
      int now = q.top();
      cout << "now in " << now << endl;
      q.pop();
      seen[now] = true;
      for(int next : to[start]){
        if(seen[next]){
          continue;
        }
        cout << "next is" << next << endl;
        cnt ++;
        q.push(next);
      }
    }
    cout << "start " << start << " cnt " << cnt << endl;
  }
}
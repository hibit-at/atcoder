#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
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


int n,m;
vector<vector<pair<int,int>>> to;

void print_to_with_cost(vector<vector<pair<int,int>>> to){
  int n = to.size();
  rep(i,n){
    for (auto p : to[i]){
      cout << "(to " << p.first << ",cost " << p.second << ") ";
    }
    cout << endl;
  }
}

int bfs(int disable){
  // cout << "disable pattern is " << disable << endl;
  queue<int> q;
  q.push(1);
  vector<int> dist(n+1,(int)1e9);
  dist[1] = 0;
  while(q.size()>0){
    int now = q.front();
    q.pop();
    // cout << "now searching " << now << " (dist" << dist[now] << ")" << endl;
    for(auto p : to[now]){
      int next = p.first;
      int cost = p.second;
      if(now == 1 && next == disable) continue;
      if(dist[next] > dist[now] + cost){
        dist[next] = dist[now] + cost;
        q.push(next);
        // cout << " .. hit! next target is " << next << " update dist " << dist[next] << endl;
      }
    }
  }
  return dist[disable];
}

int main(){
  cin >> n >> m;
  to.resize(n+1);
  rep(i,m){
    int v1,v2,l;
    cin >> v1 >> v2 >> l;
    to[v1].push_back({v2,l});
    to[v2].push_back({v1,l});
  }
  // print_to_with_cost(to);
  int ans = (int)1e9;
  for(auto p : to[1]){
    int disable = p.first;
    ans = min(ans,bfs(disable)+p.second);
  }
  if(ans == (int)1e9) ans = -1;
  cout << ans << endl;
}
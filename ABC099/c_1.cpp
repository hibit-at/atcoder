#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
typedef long long ll;

const ll mod = (ll)1e9 + 7;
const int inf = 2e5; 
void chmin(int &a, int b) { a = min(a, b); }
void print_vector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}


int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,inf);
  vector<int> steps;
  steps.push_back(1);
  int pow6 = 1;
  while(pow6 <= n){
    pow6 *= 6;
    steps.push_back(pow6);
  }
  int pow9 = 1;
  while(pow9 <= n){
    pow9 *= 9;
    steps.push_back(pow9);
  }
  dp[0] = 0;
  rep(now,n){
    for(int step : steps){
      int next = now + step;
      if(next > n){
        continue;
      }
      chmin(dp[next],dp[now]+1);
    }
  }
  cout << dp.back() << endl;
}
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
  string a,b,c,d;
  cin >> a >> b >> c >> d;
  map<string,int> mp;
  mp[a] ++;
  mp[b] ++;
  mp[c] ++;
  mp[d] ++;
  bool suc = true;
  if(mp["H"] == 0){
    suc = false;
  }
  if(mp["2B"] == 0){
    suc = false;
  }
  if(mp["3B"] == 0){
    suc = false;
  }
  if(mp["HR"] == 0){
    suc = false;
  }
  if(suc){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}
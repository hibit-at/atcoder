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

int main(){
  int n,m;
  cin >> n >> m;
  map<int,int> mp;
  rep(i,n){
    int a;
    cin >> a;
    mp[a] = 1;
  }
  rep(i,n){
    int b;
    cin >> b;
    mp[b] ++;
  }
  vector<int> ans;
  for(auto p : mp){
    if(p.second == 1){
      ans.push_back(p.first);
    }
  }
  rep(i,ans.size()){
    cout << ans[i];
    if(i == ans.size()-1){
      cout << endl;
    }else{
      cout << " ";
    }
  }

}
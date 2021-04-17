#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <ostream>
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
  int a,b;
  cin >> a >> b;
  int ans = 1;
  for(int i=a;i<b;i++){
    // cout << "searching " << i << endl;
    for(int y=1;y*y<=i;y++){
      if(i%y != 0){
        continue;
      }
      // cout << "...yakusuu is " << y << endl; 
      if(b >= i+y){
        ans = max(ans,y);
      }
      int o = i/y;
      // cout << "...opposite is " << o << endl;
      if(b >= i+o){
        ans = max(ans,o);
      }
    }
  }
  cout << ans << endl;
}
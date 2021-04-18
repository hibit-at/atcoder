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

int main() {
  int a,b;
  cin >> a >> b;
  int ans = 1;
  for(int i=2;i*i<=b;i++){
    if(b%i == 0){
      continue;
    }
    int divB = b/i;
    int divA = (a-1)/i;
    if(divB - divA >= 2){
      ans = max(ans,i);
    }
  }
  cout << ans << endl;
}
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

int main_test(int n){
  // ll n;
  // cin >> n;
  if(n == 1){
    cout << "Aoki" << endl;
    return 0;
  }
  bool isOK = true;
  ll low_limit = n/2 + 1;
  while(low_limit > 3){
    low_limit /= 2;
    isOK = !isOK;
    // cout << low_limit << endl;
  }
  if(isOK){
    cout << "Takahashi" << endl;
  }else{
    if(low_limit == 2){
      cout << "Aoki" << endl;
    }else{
      cout << "Takahashi" << endl;
    }
  }
  return 0;
}

int main(){
  rep1(i,64){
    cout << "N=" << i << ", ";
    main_test(i);
  }
}
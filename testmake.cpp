#include <algorithm>
#include <iostream>
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

vector<bool> make_erat(int limit) {
  vector<bool> erat(limit, true);
  erat[0] = false;
  erat[1] = false;
  for (int i = 0; i * i < limit; i++) {
    if (erat[i]) {
      int j = i * i;
      while (j < limit) {
        erat[j] = false;
        j += i;
      }
    }
  }
  return erat;
}


int main(){
    vector<bool> erat = make_erat(50);
    vector<int> primes;
    rep(i,50){
        if(erat[i]) primes.push_back(i);
    }
    cout << primes.size() << endl;
    for(int i : primes){
        cout << i << " ";
    }
    cout << endl;
}
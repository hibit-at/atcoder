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

int main(){
  vector<int> score(3);
  vector<int> compare(3);
  rep(i,3){
    int a;
    cin >> a;
    score[i] = a;
    compare[i] = a;
  }
  sort(all(compare));
  rep(i,3){
    if(score[i] == compare[0]){
      cout << 3 << endl;
    }
    if(score[i] == compare[1]){
      cout << 2 << endl;
    }
    if(score[i] == compare[2]){
      cout << 1 << endl;
    }
  }
}
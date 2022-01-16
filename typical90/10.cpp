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

void print_vector_ll(vector<ll> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<ll> one(n + 1), two(n + 1);
  rep1(i, n) {
    int c, p;
    cin >> c >> p;
    if (i > 0) {
      one[i] = one[i - 1];
      two[i] = two[i - 1];
    }
    if (c == 1) {
      one[i] += p;
    } else {
      two[i] += p;
    }
  }
  // print_vector_ll(one);
  // print_vector_ll(two);
  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--;
    cout << one[r] - one[l] << " " << two[r] - two[l] << endl;
  }
}
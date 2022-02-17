#include <algorithm>
#include <iostream>
#include <iomanip>
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
#include <stack>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

int n, W;
vector<ll> v, w;
vector<vector<ll>> memo;

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
  for (vector<T> v : vv)
  {
    for (T i : v)
    {
      cout << i << ",";
    }
    cout << endl;
  }
}

ll knap(int i, int j)
{
  // debug(i);
  // debug(j);
  if (memo[i][j] > -1)
  {
    return memo[i][j];
  }
  ll ans = knap(i - 1, j);
  if (j >= w[i - 1])
  {
    chmax(ans, knap(i - 1, j - w[i - 1]) + v[i - 1]);
  }
  print_vector_vector(memo);
  return memo[i][j] = ans;
}

int main(void)
{
  cin >> n >> W;
  v.resize(n);
  w.resize(n);
  rep(i, n)
  {
    cin >> w[i] >> v[i];
  }
  memo.resize(n + 1);
  rep(i, n + 1)
  {
    memo[i].resize(W + 1, -1);
  }
  rep(i, W + 1)
  {
    memo[0][i] = 0;
  }
  rep(i,W+1){
    knap(n,W);
  }
  print_vector_vector(memo);
}
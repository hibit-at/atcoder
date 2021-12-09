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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

vector<vector<int>> to;
const int inf = 1e9;
int ans = 0;

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

bool top_sort(int n, vector<vector<int>> to)
{
  vector<int> graph(n);
  rep(i, n)
  {
    for (int next : to[i])
    {
      graph[next]++;
    }
  }
  stack<int> st;
  rep(i, n)
  {
    if (graph[i] == 0)
    {
      st.push(i);
    }
  }
  while (st.size() > 0)
  {
    int now = st.top();
    st.pop();
    for (int next : to[now])
    {
      graph[next]--;
      if (graph[next] == 0)
      {
        st.push(next);
      }
    }
  }
  rep(i, n)
  {
    if (graph[i] > 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  to.resize(n);
  rep(i, m)
  {
    int a, b;
    cin >> a >> b;
    to[a].push_back(b);
  }
  if (top_sort(n, to))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}
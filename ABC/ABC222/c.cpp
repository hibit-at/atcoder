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
#include <stack>

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

template <typename S, typename T>
void print_vector_pair(vector<pair<S, T>> v)
{
    for (pair<S, T> i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << " ";
    }
    cout << endl;
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
  for (vector<T> v : vv)
  {
    for (int i : v)
    {
      cout << i << ",";
    }
    cout << endl;
  }
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(2 * n);
    rep(i, 2 * n)
    {
        vp[i] = {0, i};
    }
    vector<vector<char>> hand(2 * n, vector<char>(m));
    rep(i, 2 * n)
    {
        rep(j, m)
        {
            cin >> hand[i][j];
        }
    }
    rep(_, m)
    {
        rep(i, n)
        {
            int a = vp[2 * i].second;
            int b = vp[2 * i + 1].second;
            // debug(a);
            // debug(b);
            char hand_a = hand[a][_];
            char hand_b = hand[b][_];
            // debug(hand_a);
            // debug(hand_b);
            if (hand_a == hand_b)
            {
                continue;
            }
            bool sub1 = hand_a == 'G' && hand_b == 'C';
            bool sub2 = hand_a == 'C' && hand_b == 'P';
            bool sub3 = hand_a == 'P' && hand_b == 'G';
            if (sub1 || sub2 || sub3)
            {
                vp[2 * i].first--;
            }
            else
            {
                vp[2 * i + 1].first--;
            }
        }
        sort(all(vp));
        // print_vector_pair<int, int>(vp);
    }
    rep(i,2*n){
        cout << vp[i].second+1 << endl;
    }
}
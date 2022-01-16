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

template <typename T>
void print_vector(vector<T> v)
{
  for (T i : v)
  {
    cout << i << ",";
  }
  cout << endl;
  return;
}

int main(void)
{
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    vector<double> t(n);
    rep(i,n){
        t[i] = a[i] / b[i];
    }
    print_vector<double>(t);
    vector<double> left_sum(n),right_sum(n);
    rep(i,n){
        int j = n-1-i;
        if(i == 0){
            left_sum[0] = t[0];
            right_sum[j] = t[n-1]; 
        }
        else{
            left_sum[i] = t[i] + left_sum[i-1];
            right_sum[j] = t[j] + right_sum[j+1];
        }
    }
    right_sum.push_back(0);
    print_vector<double>(left_sum);
    print_vector<double>(right_sum);
    rep(i,n){
        double diff = left_sum[i] - right_sum[i+1];
        debug(diff)
        if(diff == 0){

        }
    }
}
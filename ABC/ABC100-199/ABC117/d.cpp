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

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    vector<ll> buc(40);
    rep(i, 40)
    {
        rep(j, N)
        {
            buc[i] += A[j] & 1;
            A[j] /= 2;
        }
    }
    vector<bool> kbit(40);
    rep(i, 40)
    {
        kbit[i] = K & 1;
        K /= 2;
    }

    long long res = 0;
    for (int d = -1; d < 40; d++)
    {
        if (d != -1 && !kbit[d])
        {
            continue;
        }

        long long tmp = 0;
        rep(e, 40)
        {
            long long factor = 1LL << e;
            if (e > d)
            {
                if (kbit[e])
                {
                    tmp += factor * (N - buc[e]);
                }
                else
                {
                    tmp += factor * buc[e];
                }
            }
            else if (e == d)
            {
                tmp += factor * buc[e];
            }
            else
            {
                tmp += factor * max(buc[e], N - buc[e]);
            }
        }
        chmax(res, tmp);
    }
    cout << res << endl;
}
#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<vector<int>> T;
    vector<long long> Q;
    for (int k = 1; k <= N; ++k) {
        long long ans = 0;
        if (k == 1) {
            ans = N;
        } else if (k == 2) {
            ans = (long long)N * (N - 1) / 2;
            ans %= MOD;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    T.push_back({i, j});
                }
            }
        } else {
            vector<vector<int>> S;
            for (auto &&v : T) {
                int diff = v[1] - v[0];
                for (int i = v.back() + 1; i < N; ++i) {
                    vector<int> tmp = v;
                    if (A[i] - A[v.back()] == diff) {
                        tmp.push_back(i);
                    } else {
                        continue;
                    }
                    S.push_back(tmp);
                }
            }
            ans = S.size();
            ans %= MOD;
            T = S;
        }
        Q.push_back(ans);
    }
    int _ = 0;
    for (auto &&v : Q) {
        if (_++) cout << " ";
        cout << v;
    }
    cout << endl;
}

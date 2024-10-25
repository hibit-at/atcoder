#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<tuple<int, int, int>> edges(m);
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;  // 0-indexed
        edges[i] = make_tuple(a, b, c);
    }

    vector<vector<int>> queries(q);
    for(int i = 0; i < q; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int idx;
            cin >> idx;
            --idx;  // 0-indexed
            queries[i] = {t, idx};
        }
        else if(t == 2){
            int x, y;
            cin >> x >> y;
            --x; --y;  // 0-indexed
            queries[i] = {t, x, y};
        }
    }

    const int N = n;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for(int i = 0; i < N; ++i){
        dist[i][i] = 0;
    }

    // 辺の存在を管理するためのフラグ
    vector<bool> edge_exists(m, false);

    for(const auto& q : queries){
        int t = q[0];
        if(t == 1){
            // 辺の復活
            int idx = q[1];
            if(!edge_exists[idx]){
                edge_exists[idx] = true;
                int u, v, w;
                tie(u, v, w) = edges[idx];
                // 距離行列の更新
                if(dist[u][v] > w){
                    dist[u][v] = w;
                }
                // 新しい辺が追加されたので、影響を受ける経路を更新
                for(int i = 0; i < N; ++i){
                    for(int j = 0; j < N; ++j){
                        if(dist[i][u] != INF && dist[v][j] != INF){
                            if(dist[i][j] > dist[i][u] + w + dist[v][j]){
                                dist[i][j] = dist[i][u] + w + dist[v][j];
                            }
                        }
                        // 始点・終点が新しい辺に関連する場合の更新
                        if(dist[i][v] > dist[i][u] + w){
                            dist[i][v] = dist[i][u] + w;
                        }
                        if(dist[u][j] > w + dist[v][j]){
                            dist[u][j] = w + dist[v][j];
                        }
                    }
                }
            }
        }
        else if(t == 2){
            // 最短経路の問い合わせ
            int x = q[1];
            int y = q[2];
            int ans = dist[x][y];
            if(ans < INF){
                cout << ans << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}

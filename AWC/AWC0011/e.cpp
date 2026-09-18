#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18; // 十分に大きな値

int main() {
    // 入力の高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second; // {重さ a, 価値 b}
    }

    // prefix[i][w]: 0番目からi-1番目までのアイテムを使い、重さwのときの最大価値
    vector<vector<ll>> prefix(n + 1, vector<ll>(m + 1, -INF));
    prefix[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int a = items[i].first;
        int b = items[i].second;
        for (int w = 0; w <= m; w++) {
            if (prefix[i][w] == -INF) continue;
            // 選ばない
            prefix[i + 1][w] = max(prefix[i + 1][w], prefix[i][w]);
            // 選ぶ
            if (w + a <= m) {
                prefix[i + 1][w + a] = max(prefix[i + 1][w + a], prefix[i][w] + b);
            }
        }
    }

    // suffix[i][w]: i番目からN-1番目までのアイテムを使い、重さwのときの最大価値
    vector<vector<ll>> suffix(n + 1, vector<ll>(m + 1, -INF));
    suffix[n][0] = 0;
    for (int i = n - 1; i >= 0; i--) {
        int a = items[i].first;
        int b = items[i].second;
        for (int w = 0; w <= m; w++) {
            if (suffix[i + 1][w] == -INF) continue;
            // 選ばない
            suffix[i][w] = max(suffix[i][w], suffix[i + 1][w]);
            // 選ぶ
            if (w + a <= m) {
                suffix[i][w + a] = max(suffix[i][w + a], suffix[i + 1][w] + b);
            }
        }
    }

    // suffix_max[i][w]: suffix[i][0...w] の中の最大値（w以下ならOKにするための累積最大値）
    vector<vector<ll>> suffix_max(n + 1, vector<ll>(m + 1, -INF));
    for (int i = 0; i <= n; i++) {
        ll current_max = -INF;
        for (int w = 0; w <= m; w++) {
            current_max = max(current_max, suffix[i][w]);
            suffix_max[i][w] = current_max;
        }
    }

    // 全体の最大価値を求める
    ll global_max_value = -INF;
    for (int w = 0; w <= m; w++) {
        global_max_value = max(global_max_value, prefix[n][w]);
    }

    // 各アイテム k について判定
    for (int k = 0; k < n; k++) {
        int a = items[k].first;
        int b = items[k].second;
        bool can_include = false;

        for (int w1 = 0; w1 <= m - a; w1++) {
            if (prefix[k][w1] == -INF) continue;
            
            // アイテム k を選んだとき、残りの重さは m - a - w1
            int max_w2 = m - a - w1;
            ll best_suffix = suffix_max[k + 1][max_w2];

            if (best_suffix != -INF) {
                if (prefix[k][w1] + b + best_suffix == global_max_value) {
                    can_include = true;
                    break;
                }
            }
        }

        cout << (can_include ? "Yes" : "No") << "\n";
    }

    return 0;
}
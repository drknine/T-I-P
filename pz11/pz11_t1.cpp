#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    const long long NEG = -(1LL << 60);

    vector<vector<long long>> dp(n, vector<long long>(m, NEG));
    dp[0][0] = a[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;

            long long bestPrev = NEG;

            if (i > 0) bestPrev = max(bestPrev, dp[i - 1][j]);
            if (j > 0) bestPrev = max(bestPrev, dp[i][j - 1]);

            dp[i][j] = bestPrev + a[i][j];
        }
    }

    // Восстановление маршрута с конца в начало
    int i = n - 1;
    int j = m - 1;

    vector<pair<int, int>> path;
    path.push_back({i, j});

    while (i != 0 || j != 0) {
        if (i > 0 && (j == 0 || dp[i - 1][j] >= dp[i][j - 1])) {
            --i;
        } else {
            --j;
        }
        path.push_back({i, j});
    }

    reverse(path.begin(), path.end());

    cout << "Максимальная сумма: " << dp[n - 1][m - 1] << "\n";
    cout << "Маршрут:\n";

    for (auto [x, y] : path) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
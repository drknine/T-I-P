#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, L;
    cin >> N >> K >> L;

    vector<int> cost(N);
    for (int &x : cost) cin >> x;

    // сортируем стоимости по убыванию
    sort(cost.rbegin(), cost.rend());

    long long answer = 0;
    int taken = 0;

    // берём самые дорогие растения,
    // но не более L штук каждого вида
    for (int i = 0; i < N && taken < K; ++i) {
        int take = min(L, K - taken);
        answer += 1LL * take * cost[i];
        taken += take;
    }

    cout << answer << '\n';
    return 0;
}
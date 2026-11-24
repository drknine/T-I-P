#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<long long> a(N);
    for (long long &x : a) cin >> x;

    sort(a.begin(), a.end());

    auto can = [&](long long diff) -> bool {
        int days = 0;
        int i = 0;

        while (i < N) {
            int j = i;

            // в один день берём максимально возможный отрезок
            // с разницей не больше diff
            while (j + 1 < N && a[j + 1] - a[i] <= diff) {
                ++j;
            }

            ++days;
            i = j + 1;

            if (days > D) return false;
        }

        return days <= D;
    };

    long long left = -1;
    long long right = a.back() - a.front();

    while (right - left > 1) {
        long long mid = (left + right) / 2;

        if (can(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << '\n';

    return 0;
}
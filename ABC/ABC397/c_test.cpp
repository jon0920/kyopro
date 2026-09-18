#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> l(n), r(n);
    unordered_set<int> seen;

    // 左から distinct 数を数える
    for (int i = 0; i < n; i++) {
        seen.insert(a[i]);
        l[i] = seen.size();
    }

    seen.clear();

    // 右から distinct 数を数える
    for (int i = n - 1; i >= 0; i--) {
        seen.insert(a[i]);
        r[i] = seen.size();
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, l[i] + r[i + 1]);
    }

    cout << ans << endl;
}

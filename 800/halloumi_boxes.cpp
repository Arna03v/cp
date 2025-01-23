#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (is_sorted(a.begin(), a.end()) || k > 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}

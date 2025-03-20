#include <iostream>

using namespace std;

#define nl "\n"
#define int long long

inline void solve() {
    int n;
    cin >> n;

    // If n is odd or n is 2, there is no valid solution
    if (n & 1 || n == 2) {
        cout << -1 << nl;
        return;
    }

    int min_buses = (n + 6 - 1) / 6; // Equivalent to ceil(n/6)
    int max_buses = n / 4;           // Equivalent to floor(n/4)

    cout << min_buses << " " << max_buses << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}

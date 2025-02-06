#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    bool found = false;
    for (int x = 0; x < 2; x++) {
        if (n - x * k >= 0 && (n - x * k) % 2 == 0) {
            cout << "YES" << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
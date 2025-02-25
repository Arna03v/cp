#include <iostream>
using namespace std;

void solve() {

    // some math thing, dont have to simulate it
    // find min sum posisble
    // find max sum possible
    // can make any number between these

    
    long long n, x, k;
    cin >> n >> x >> k;

    // Calculate minimum sum using first x natural numbers
    long long mini = (x * (x + 1)) / 2;

    // Calculate maximum sum using x largest numbers from n
    long long maxi = (x * (2 * n - x + 1)) / 2;

    if (mini <= k && k <= maxi) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}

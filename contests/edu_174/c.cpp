#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> nums(n - 2);
    
    // Ensure we get enough inputs to fill the vector
    for (int i = 0; i < n - 2; ++i) {
        cin >> nums[i];
    }


    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] == 1 && nums[i + 1] == 0 && nums[i + 2] == 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}

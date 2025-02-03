#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n; vector<int> nums(n); for(int& i : nums) cin >> i;

    int smallest_difference = INT_MAX;

    if(!is_sorted(nums.begin(), nums.end())){
        cout << 0 << endl;
        return;
    }

    for(int i=0; i<n-1; i++){
        smallest_difference = min(smallest_difference, nums[i+1] - nums[i]);
    }

    cout << smallest_difference/2 + 1 << endl;
    return;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
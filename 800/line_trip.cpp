#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    // we need just enough to go from the one point to the next
    int res = INT_MIN;
    res = max(nums[0] - 0, 2*(x - nums[nums.size()-1]));

    for(int i=1; i<nums.size(); i++){
        res = max(res, nums[i] - nums[i-1]);
    }

    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
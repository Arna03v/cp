#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
#include <utility>
#include <numeric>
using namespace std;

inline void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // 4 cases
    // 1. dont rotate
    int res = nums[n-1]-nums[0];
    // 2. rotation includes both potential start and end
    for(int i=0; i<n-1; i++){
        res = max(nums[(i-1+n)%n]-nums[i], res);
    }
    // 3. rotation includes only the start; end is fixed
    for(int i=0; i<n-1; i++){
        res = max(res, nums[n-1] - nums[i]);
    }
    // 4. rotation includes only the end; start is fixed
    for(int i=1; i<n; i++){
        res = max(res, nums[i] - nums[0]);
    }

    cout << "res\n" << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
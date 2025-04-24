#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <string>
#include <cctype>
#include <utility>
#include <numeric>
#include <sstream>
using namespace std;

#define nl "\n"
#define int long long
#define zz "res is : " << 

// i - a[i]
// when we traverse across the array, the value `i` is increasing
// if we sort in decreasing order
// initially the value will be very small (as i == 0)
// and lter the value will be very large 
// the values of i - a[i] is monotonic in this case

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    sort(nums.rbegin(), nums.rend());
    for(int& el : nums) cout << el << " ";
    cout << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
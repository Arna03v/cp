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
#include <sstream>
using namespace std;

#define nl "\n"
#define int long long

void solve(){
    int n, k; cin >> n >> k; vector<int> nums(n*k);
    for(int& el : nums) cin >> el;

    // from lft take floor (n/2) elements
    // from right take ceil(n/2) elements

    int steps_to_skip = (k+1)/2;
    int index = n*k;
    int res = 0;

    for(int i=1; i<n; i++){
        index -= steps_to_skip;
        if(index < 0)break;
        res += nums[index];
    }

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
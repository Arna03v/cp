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
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // the smallest possible answer is when all bits are 0
    // if we have 2 numbers a and b. if they have bits set in differeing places then a&b = 0
    // the only bit we cant make 0 is when all numbers have that bit = 1
    // do and &
    int res = nums[0];
    for(int i=0; i<nums.size(); i++){
        res = res&nums[i];
    }

    cout << res << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
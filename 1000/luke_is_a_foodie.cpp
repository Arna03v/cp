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

// find minimum number of changes to v

// v <= ai + x
// v >= ai - x

// start with  v that works innitially, change when it doesnt
// nothing about choosing an optimal value, just have to check if ranges intersect
// if they do we can satisfy in one value of v
// else we cant

void solve(){
    int n, x; cin >> n >> x; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    int r = x + nums[0];
    int l = nums[0] - x;

    int res = 0;

    for(int i=0; i<n; i++){
        int new_l = nums[i] - x;
        int new_r = nums[i] + x;


        // check if there is a overlap in this new range and the old

        // choosing only the intersection part, so that future comparisions are not independent of the previous ones
        l = max(l, new_l);
        r = min(r, new_r);

        if(l > r){
            // ther eis no intersection
            res++;
            l = new_l;
            r = new_r;
        }

    }

    cout << res << nl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
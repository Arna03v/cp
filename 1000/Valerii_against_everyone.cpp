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

// define `a` st, a[i] = 2^b[i]

// if any element repeats, we can select them as subarrays
// if they dont repeat
    // say we have an answer
    // the 2 subarrays = setting the bits of a number in a binary representation
    // and since the numbers dont repeat
    // it is impossible to get the same binary representation twice
    // therefore there is no answer


// use  map if we want to return the indexes as well
void solve(){
    int n; cin >> n; vector<int> nums(n);
    set<int> s;

    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        if(s.count(nums[i]) >= 1){
            cout << "YES" << nl;
            return;
        }
        s.insert(nums[i]);
    }
    cout << "NO" << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
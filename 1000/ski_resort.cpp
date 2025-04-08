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

// n days of vacation
// he will only go for atleast k days for skiing
// nums gives the temperature on the i'th day
// can go for skiing if the temp <= q degrees

// number of ways to choose the vacation dates

void solve(){
    int n, k, q; cin >> n >> k >> q; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // cannot go for anydays
    if(q < *min_element(nums.begin(), nums.end())){
        cout << 0 << nl;
        return;
    }

    vector<int > days; // stores the number of days in a consecutive session
    
    int curr = 0;
    for(int i=0; i<n; i++){
        if (nums[i] <= q) {
            curr++;
        } else {
            if (curr > 0) days.push_back(curr);
            curr = 0;
        }
    }
    if(curr > 0) days.push_back(curr);

    // cout << "printing the days" << "->";
    // for(int& el : days) cout << el << " ";
    // cout << nl;

    int res = 0;


    /*
    And for a segment of length l
, the number of ways to choose a trip of at least length k
 is  (l-k+2) C (l-k)
    */
    for (int el : days) {
        if (el >= k) {
            res += ((el - k + 1)*(el - k + 2)) / 2;
        }
    }

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
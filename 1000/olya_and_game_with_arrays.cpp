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

// from ech array; take the min element and sum them up
// return the minimum possible sum
// from each array; move 0/1 element to any other array

// move all the minimums into one array
// this way the array with all the minimums will contribute with the smallest value among all arrays

// return max beauty score

// for each array we want the minimum element to be as big as possible 
// move the minimum element from each array
// where to move them
    // elements can't go out, we need to put them in some existing array
    // if we had a seaprate array to dump; the beauty will be the sum of second minimum elements
    // dump it in the array where the second minimum is the least (we might be able to ignore some of the mallest elements)
    // this way we will reduce the smallest second minimum from the result instead of a large one
// max beauty = sum(2nd min elements) - min(2nd min element) + minimum element

void solve(){
    int n; cin >> n; 

    int mini = INT_MAX; // to keep track of the smallest element
    vector<int> res;
    
    for(int i=0; i<n; i++){
        int m; cin >> m;

        vector<int> v(m);
        for(auto& el : v) cin >> el; 

        // now we have the array
        // find the minimum element and the second minimum element

        int min_el = *min_element(v.begin(), v.end());
        mini = min(mini, min_el);

        // now remove the smallest element
        v.erase(find(v.begin(), v.end(), min_el));

        // now add this second smallest element in a vector; as we need to remove the smallest among this as well later
        // eaiser than keep track for this as well
        res.push_back(*min_element(v.begin(), v.end()));

    }

    int ans = accumulate(res.begin(), res.end(), 0LL) - *min_element(res.begin(), res.end()) + mini;

    cout << ans << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
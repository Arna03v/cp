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

/*
UPSOLVING : using 1 based indexing for upsolving; code as needed

mex = minimum value that has not appeared in the selected interval

case1 : all elements > 0
    take all elements and replace; the final element remaining will be 0
    l = 1; r = n;

case 2 : at least one 0
    if (a[1] != 0)
        we know that some zero exists after a[0]
        l = 2; r = n; -> this interval will contain a 0 -> mex(interval) > 0
        now choose l=1, r=2; -> since this interval does not contain 0; the mex(interval) = 0
    if (a[n] != 0)
        similarly choose l=1; r=n-1 and then do the mex again after this
    if (a[1] == 0 && a[n] == 0 )
        note that n >= 4; 
        first take l=1, r=2 which and then take the last 2 elements;
        first mex will not contain a 0; the last mex will not contain a 0
        mex the remainder and the result will be 0

    use a vector<pair<int,int>> to store the operations

*/

// upsolved solution
void solve2(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;


}

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // break it into 3 cases
    // size is 2
    // size is 3
    // size > 3

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
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

    int one_count = 0;
    int zero_count = 0;
    int sum = 0;

    for(int& el : nums){
        if(el == 1)one_count++;
        if(el == 0)zero_count++;
        sum += el;
    }

    if(zero_count == 0){
        cout << one_count << nl;
        return;

    }

    // for each one, we can choose or not choose a 0
    int res = (1ll << zero_count)*(one_count);

    cout << res << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}

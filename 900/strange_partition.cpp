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
    int n, x; cin >> n >> x; vector<int> nums(n);
    
    int sum = 0;
    int maxi = 0;
    int curr = 0;
    for(int& el : nums) {
        cin >> el;
        sum += el;

        maxi += (el + x - 1)/x;
        
    }

    // to find the maximum and minimum beauty we can get
    // max beauty = ceil(a1/x) + ceil(a2/x) ...
    // min beauty = ceil(a1 + a2 .../x)

    cout << (sum + x - 1)/x << " " << maxi << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
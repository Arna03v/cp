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

inline void solve(){
    int n; cin >> n; map<int, int> freq;
    int max_freq = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
        max_freq = max(max_freq, freq[x]);
    }

    // optjimising to perform max while adding because teh solution is giving TLE

    // int max_el = -1;
    // int max_freq = 0;

    // for(auto& el : freq){
    //     int num = el.first;
    //     int freq = el.second;

    //     if(freq > max_freq){
    //         max_el = num;
    //         max_freq = freq;
    //     }
    // }

    // cout << "max freq is  : " << max_freq << nl;

    int res = 0;
    while(max_freq < n){
        int diff = min(n - max_freq, max_freq); // if more than half the array is same

        res += 1 + diff; // 1 to clone; diff to swap those common elements in
        max_freq += diff; // max_frequency increase by the number of elements we have swapped

        // cout << "res is now : " << res << nl;

    }

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
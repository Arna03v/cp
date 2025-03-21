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
    int x, n; cin >> x >> n; 

    // brute force -> will time out
    // for(int i=1; i<=n; i++){
    //     if(x&1){
    //         x+= i;
    //     }else x-= i;
    // }

    // finding the patter
    // starting at 0; 0, -1, 1, 3, 0
    // starting at odd position; 1, 2, 0, -3, 1
    // starting at even position; 2, 1, 3, 6, 2

    // cant do +-1, it is doing +-n

    if (n % 4 == 0) {
        cout << x << nl;
    } else if (n % 4 == 1) {
        cout << (x % 2 == 0 ? x - n : x + n) << nl;
    } else if (n % 4 == 2) {
        cout << (x % 2 == 0 ? x + 1 : x - 1) << nl;
    } else { // n % 4 == 3
        cout << (x % 2 == 0 ? x + n + 1 : x - n - 1) << nl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
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

// one torch = one stick + one coal
// we want to light k torches and we have 1 stick initially

// exchange 1 stick for x sticks
// exchange y sticks for one coal

// find minimum number of trades to light at least k torches

// for k torches
    // k sticks + k coal
    // k sticks + k.y sticks
    // k(1+y) sticks

    // every trade we gain (x-1) sticks
    // number of trades = `z` to get all the sticks

    // 1 + z(x-1) >= k(1+y)

    // now get coals from these sticks
    
    // total number of trades => total number of sticks/trades per stick + trades to get the coals
    // total number of trades = > (k*(1+y) - 1)/(x-1) + k

void solve(){
    int x, y, k; cin >> x >> y >> k;

    // ceil(a/b) = a + b - 1/b

    int a = k*(1+y) - 1;
    int b = x-1;

    int res = (a+b-1)/b;
    res += k;

    cout << res << nl;
    return;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}

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
    int a,b,c; cin >> a >> b >> c;

    // the only condition is 2b = a + c
    // we can try all three cases

    // changing a
    // b and c form and AP
    int diff = c-b;
    int new_a = b - diff;
    if(new_a >= a && new_a % a == 0 && new_a != 0){
        // we can do this
        cout << "YES" << nl;
        return;
    }

    // changing b
    int new_b;
    if((a+c)%2 == 0){
        new_b = (a+c)/2;
        if(new_b >= b && new_b % b == 0 && new_b != 0){
            cout << "YES" << nl;
            return;
        }
    }

    // changing c
    diff = b - a;
    int new_c = b + diff;
    if(new_c >= c && new_c % c == 0 && new_c != 0){
        cout << "YES" << nl;
        return;
    }

    cout << "NO" << nl;
    return;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
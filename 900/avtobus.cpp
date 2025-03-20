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
using namespace std;

#define nl "\n"

inline void solve(){
    int n; cin >> n; 

    // IF N IS ODD THEN ITS NOT POSSIBLE
    if(n&1 || n==2){
        cout << -1 << nl;
        return;
    }

    // 4x + 6y = n
    // 2x + 3y = n/2

    // maximise the number of buses; increase value of x
    // if n/2 is even (say n = 12)
    // x = 3
    // if n/2 is odd (say n=14)
    // x = 2, y = 1
    // so we have floor(n/2) buses

    // minimise the buses; increase value of y
    // 3k, 3k+1, 3k+2
    // we get ceil(n/3)

    cout << ceil(n/3) << " " << floor(n/2) << nl;
    return;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
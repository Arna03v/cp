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
using namespace std;

// spectattor plays the winner
// winner can play 2 matches in a row max; then sit out

// given the integer n; determine if the spectator of match 1 can be the sepctator of match n

void solve(){
    int n; cin >> n; 

    // 2, 4, 6, ...
    // -, 2, 3, -, 5, 6, -, ...
    
    if(n%3 == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    return;

}

int main(){
    int t; cin >> t; while(t--) solve();
}   
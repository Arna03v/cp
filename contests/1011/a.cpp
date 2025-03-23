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

// note
// if the string is not universal initially
// and barring all the edge cases
// one swap is always enough to make it universal

/*
UPSOLVING

when k=0;we cannot make any swaps
    if s < rev(s) then return true else return false

when k>=1
    when all the characters are same; then no
    else always yes
        if first char are diff; one is less than other so swap if necessary and we are done
        else
            if second and second last are diff; repeat the same
            this goes on till at least 2 chars are diff otherwise all characters are same
*/


void solve(){
    // cout << "hit 1" << nl;
    int n,k; cin >> n >> k; string s; cin >> s;
    int i = 0;
    int j = n-1;

    int swaps = 0;

    if(n==1){
        cout << "NO" << nl;
        return;
    }

    string t = s;
    sort(t.begin(), t.end());
        
    if(t[0] == t[n-1]){
        cout << "NO" << nl;
        return;
    }

    t = s;
    reverse(t.begin(), t.end());

    // is this already universal?
    if(s<t){
        cout << "YES" << nl;
        return;
    }


    if(k>=1) {
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


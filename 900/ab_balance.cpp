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
    string s; cin >> s;

    // this has a trick
    // note that when s[0] == s[n-1]
    // ab == ba (we need to always come back to the starting letter no matter how)
    // otherwise the difference is 1
    // if the difference is 1; just change the letter at either end

    if(s[0] == s[s.size()-1]) cout << s << nl;
    else {
        s[0] = s[s.size()-1];
        cout << s << nl;
    }

    return;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
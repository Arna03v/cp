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

// n is even
// string s contains n/2 opening and n/2 closing brackets

// choose any index and move the character from that index to the beginning or the end
// minimum number of moves to obtain a regular bracket string

// a regular bracket string; count of open >= count of closing when traversing from left to right

void solve(){
    int n; cin >> n; string s; cin >> s;

    int mini = INT_MAX;
    int curr = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '(')curr++;
        else curr--;

        mini = min(mini, curr);
    }

    cout << abs(mini) << nl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
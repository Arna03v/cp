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

void solve(){
    int n, k; cin >> n >> k; 
    string s; cin >> s;

    // take two pointers; at 0 and length k-1
    // traverse and keep track of number of whites
    // return the min

    int res = INT_MAX;
    int curr = 0;

    int j=0;

    while(j<k){
        if(s[j] == 'W')curr++;
        j++;
    }

    // now we have count from 0 to k-1
    res = min(res, curr);

    int i = 1;

    while(j<n){
        if(s[i-1] == 'W'){ // getting rid of the white
            curr--;
        }

        if(s[j] == 'W'){
            curr++;
        }

        res = min(res, curr);
        i++;
        j++;
    }

    cout << res << nl;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
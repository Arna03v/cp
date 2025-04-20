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

// if len(a) > 0; delete a[0]. same for b
// if len(a) > 0; delete a[a.size() - 1]. same for b

// return min number of operations such that a == b
// note that empty strings are equal

// this is just finding the longest common subsequence
// and comparing that with the empty string?

// wrong

// we can only delete from front or back
// which means we need the longest common substring
// not the longest common subsequence

void solve(){
    string a; cin >> a;
    string b; cin >> b;

    int n = a.size();
    int m = b.size();

    // dp[i][j] = longest common substring using 0..i of a and 0..j of b
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0)); // each string is of length 20

    // base case : can be removed because we are initialising to 0
    // when i == 0 or j == 0 we cannot have any common substring
    for(int i=0; i<n; i++){ // -> the second string has length = 0
        dp[i][0] = 0;
    }

    for(int j=0; j<m; j++){ // -> the first string has a length = 0
        dp[0][j] = 0;
    }

    int res = 0;

    // in tabuation we build from the base case

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }

            res = max(res, dp[i][j]);
        }
    }

    cout << (n+m) - (2*res) << nl; // these many characters we have to remove
    return;


}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
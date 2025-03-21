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

int solve2(string num, string s){
    // how many characters do we need to delete to get the string s at the end
    int i = num.size()-1;
    int j = 1;
    int res = 0;

    while(i>=0 && j >= 0){
        if(num[i] == s[j]){
            i--;
            j--;
        }else{
            i--;
            res++;
        }

        if(j==-1)break;
    }
    if(j < 0){
        // we matched with 2 numbers
        return res;
    }else{
        // string got over
        return INT_MAX;
    }
}

void solve(){
    int n; cin >> n; 
    string num = to_string(n);

    // start from behind
    // find either 25/50/75/00
    // find either 0 /5
    
    // find min number of steps to get 25
    // then for 50 then for 75 and then for 00

    vector<string> nums = {"25", "50", "75", "00"};
    int res = INT_MAX;
    for(string s : nums){
        int steps = solve2(num, s);
        res = min(res, steps);
    }

    cout << res << nl;
    return;
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}

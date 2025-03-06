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

void solve(){
    int n; cin >> n; 
    string s; cin >> s;

    // find the longest cons seq of same characters
    // for <<<<><<<<<
    // after the '>'; we can just print the element as 1 again and the sequence starts again

    // whenever a new segment beguns, the value will be (res+)/0
    int curr = 1;
    int res = 1;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            curr++;
            res = max(res, curr);
        }else{
            curr = 1;
        }
    }

    cout << res+1 << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}

/*

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
*/
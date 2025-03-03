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
    int n, k; cin >> n >> k; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    sort(nums.begin(), nums.end());

    int res = 1;
    int curr = 1;

    for(int i=0; i<n-1; i++){
        if(nums[i+1] - nums[i] <= k){
            curr ++;
            res = max(res, curr);
        }else{
            curr = 1;
        }
    }

    res = n - res;
    cout << res << endl;   
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
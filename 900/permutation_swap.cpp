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

int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // nums[i] will be at position (i+1)
    // nums[i] - i - 1 must be divisible by k; 
    // do that for all numbers

    vector<int> val;
    for(int i=0; i<n; i++){
        val.push_back(abs(nums[i] - (i+1)));
    }

    int res = val[0];
    for(int i=1; i<n; i++){
        res = gcd(val[i], res);

        if(res == 1)break;
    }

    cout << res << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
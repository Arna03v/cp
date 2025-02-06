#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    int sum = n+1;
    vector<int> res;
    for(int i=0; i<n; i++){
        res.push_back(sum - nums[i]);
    }

    // printing
    for(int& el : res) cout << el << " ";
    cout << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
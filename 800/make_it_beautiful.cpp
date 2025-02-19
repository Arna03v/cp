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

// if amx element is first, only the second element can make it ugly
// put min element as second
// done

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    sort(nums.begin(), nums.end());
    int maxi = nums[n-1];
    int mini = nums[0];

    if(maxi == mini) {
        cout << "NO" << endl;
        return;
    }
    vector<int> res;
    res.push_back(maxi);
    res.push_back(mini);
    for(int i=1; i<n-1; i++){
        res.push_back(nums[i]);
    }
    cout << "YES" << endl;
    for(int& el : res) cout << el << " ";
    cout << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
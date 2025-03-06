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

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    if(nums[0] == 1)nums[0]++;

    for(int i=1; i<n; i++){
        if(nums[i] == 1)nums[i]++;
        if(nums[i]%nums[i-1] == 0){
            nums[i]++;
        }
    }

    for(int& el : nums) cout << el << " ";
    cout << endl;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
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

    int curr = 0;
    int res = 0;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 0){
            curr++;
            res = max(res, curr);
        }else{
            curr = 0;
        }
    }

    cout << res << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
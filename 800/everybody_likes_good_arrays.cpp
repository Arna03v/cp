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
    for(int& el : nums){
        cin >> el;
        if(el % 2 == 0){
            el = 0;
        }else el = 1;

        // cout << el << " " << "-> ";
    }

    // cout << endl;

    

    // even * even stays even
    // odd * odd stays odd

    // so now we have strips of 0s and strips of 1s in he array and we need the final array to be
    // 101010 / 010101
    // in each strip, an operation reduces the size of strip by 1
    // result = n - no.of non-adj elements - 1

    if(nums.size() == 1) {
        cout << 0 << endl;
        return;
    }

    int count = 0;
    for(int i=1; i<n; i++){
        if(nums[i] != nums[i-1]){
            count++;
        }
    }

    cout << n - count - 1 << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
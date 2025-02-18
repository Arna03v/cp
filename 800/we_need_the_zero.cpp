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

    int res = 0;

    for(int i=0; i<256; i++){
        vector<int> b(n);
        int sum = 0;
        for(int j=0; j<n; j++){
            b[j] = nums[j]^i;
            sum ^= b[j];
        }

        if(sum == 0) {cout << "res is :" << i << endl; return;}
    }

    cout << -1 << endl;
    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}

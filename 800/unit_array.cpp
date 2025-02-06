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

    // need more 1s than -1
    // even number of -1s

    int sum = 0;
    int res = 0;
    for(int i=0; i<n; i++) sum += nums[i];

    int i=0;
    while(sum < 0){
        if(nums[i] == -1){
            nums[i] = 1;
            sum += 2;
            res++;
        }
        i++;
    }

    int count = 0;
    for(int i=0; i<n; i++){
        if(nums[i] == -1)count++;
    }

    if(count%2 == 0) cout << res << endl;
    else cout << res + 1 << endl;

    return;
}

int main(){
    int t; cin >> t; while(t--) solve();
}
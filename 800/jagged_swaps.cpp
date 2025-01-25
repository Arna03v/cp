#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    // the first element cannot be moved
    // so if the first element is !=1, it can be never be sorted

    if(nums[0] != 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
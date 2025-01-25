#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    // if there is no k in the vector then return no else return yes
    if(find(nums.begin(), nums.end(), k) != nums.end()){
        cout << "YES" << endl;
        return;
    }else{
        cout << "NO" << endl;
        return;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
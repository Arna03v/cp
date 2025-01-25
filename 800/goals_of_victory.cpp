#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n-1);

    for(int& i : nums) cin >> i;

    int res = 0;
    for(int i=0; i<n-1; i++){
        res += nums[i];
    }

    cout << -1*res << endl;

}

int main(){
    int t; cin >> t;
    while(t--)solve();
}
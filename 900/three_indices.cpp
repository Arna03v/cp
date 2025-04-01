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
#include <sstream>
using namespace std;

#define nl "\n"
#define int long long

void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    // brute force

    for(int i=0; i<n-2; i++){
        int j = i+1;
        bool got_j = false;
        bool got_k = false;
        while(nums[j] <= nums[i] && j <= n-2){
            j++;
        }
        if(j<=n-2 && nums[j] > nums[i])got_j = true;

        int k = j+1;
        while(nums[k]>=nums[j] && k <= n-1){
            k++;
        }

        if(k<=n-1 && nums[j] > nums[k])got_k = true;

        if(got_j && got_k){
            cout << "YES" << nl;
            cout << i+1 << " " << j+1 << " " << k+1 << nl;
            return;
        }
    }

    cout << "NO" << endl;
    return;

    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
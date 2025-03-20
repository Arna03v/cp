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

#define nl "\n"
#define int long long

inline void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    if(is_sorted(nums.begin(), nums.end())){
        cout << 0 << nl;
        return;
    }

    if(n==1) {cout << 0 << nl; return;}

    for(int i=0; i<n; i++){
        if(nums[i] < i+1){
            cout << -1 << nl;
            return;
        }
    }

    int res = 0;

    for(int i=0; i<n-1; i++){
        while(nums[i+1] <= nums[i]){
            nums[i] /=2;
            res++;
        }

        if(nums[i] == 0) {
            cout << -1 << nl;
            return;
        }

    }

    for(int i = n - 1; i > 0; i--) {
        while(nums[i] <= nums[i-1] && nums[i-1] > 0) {  // Ensure nums[i-1] remains positive
            nums[i-1] /= 2;
            res++;
        }
        if(nums[i-1] == 0 && nums[i] <= nums[i-1]) {  // If nums[i-1] becomes 0 and it's still not valid
            cout << -1 << nl;
            return;
        }
    }


    cout << res << nl;
    return;
}

void solve2(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &i : a) cin >> i;
    int ans = 0;
    for(int i = n - 2; i >= 0; i--){
        while(a[i] >= a[i + 1] && a[i] > 0){
            a[i] /= 2;
            ans++;
        }
        if(a[i] == a[i+1]){
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve2();
}


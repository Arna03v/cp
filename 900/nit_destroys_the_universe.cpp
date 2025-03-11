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

inline void solve(){
    int n; cin >> n; vector<int> nums(n);
    for(int& el : nums) cin >> el;

    int sections = 0;
    int first_zero = -1;  
    for(int i=0; i<n; i++){
        if(nums[i] == 0){
            first_zero = i;
            break;
        }
    }

    if(first_zero == -1){
        // did not find any 0
        cout << 1 << nl;
        return;
    }

    // cout << "first zero is at : " << first_zero << nl;

    if(first_zero != 0){
        sections++;
    }
    first_zero++;
    int gap = 0;

    while(first_zero < n){
        if(nums[first_zero] == 0){
            if(gap != 0){
                sections++;
                gap = 0;
            }
        }else{
            gap++;
        }
        first_zero++;
    }

    // check if last number was a 0
    if(gap != 0){
        sections++;
    }

    cout << sections << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; while(t--) solve();
}
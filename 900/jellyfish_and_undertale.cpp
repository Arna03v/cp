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
using namespace std;

#define int long long

void solve(){
    int a,b,n; cin >> a >> b >> n; vector<int> nums(n);
    int res = b;
    for(int& el : nums) {
        cin >> el;
        res += min(a-1, el); // we can either add the entire element to the time, or we can add 'a' and then the time will go down by 1
        // time might not go down when we add 'el' as we can possibly add more than one element at an instant
    }

    cout << res << endl;

    // the commented out code works as well

    // // use one tool everytime the timer reaches to one
    // int time = 0;
    // while(b>0){
    //     if(b==1 && nums.size() != 0){
    //         b = min(b + nums[nums.size()-1], a);
    //         nums.pop_back();
    //     }
    //     if(b==1){
    //         time++;
    //         b--;
    //     }else {
    //         // optimising the number of steps as it is TLEing
    //         int diff = b - 1;
    //         // cout << "difference is :" << diff << endl;

    //         time+= diff;
    //         b-= diff;  
    //     }
         

    //     // cout << "after time = " << time << ", the value for b is " << endl;
    // }

    // cout << time << endl;
}

signed main(){
    int t; cin >> t; while(t--) solve();

}


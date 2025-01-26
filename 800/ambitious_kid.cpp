#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> nums(n);
    for(int& i : nums) cin >> i;

    int res = INT_MAX;

    if(find(nums.begin(), nums.end(), 0) != nums.end()){
        cout << 0 << endl;
        return 0;
    }else {
        for(int i=0; i<n; i++){
            res = min(res, abs(0-nums[i]));
        }
    }

    cout << res << endl;
    
}